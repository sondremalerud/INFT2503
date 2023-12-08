#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <functional>
#include <thread>
// #include <mutex> don't need

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "{ ";
    if (!vec.empty()) {
        os << vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            os << ", " << vec[i];
        }
    }
    os << " }";
    return os;
}

int times_two(int n) {
    return n*2;
}

string times_two(const string& n) {
    return n+n;
}

double times_two(double n) {
    return n*2;
}

vector<int> times_two(vector<int> list) {
    for (size_t i = 0; i < list.size(); i++) {
        list[i] += list[i];
    }
    return list;
}

class BuildSystem {
public:
    virtual string build() const = 0;
};

class CMake : public BuildSystem {
public:
    string build() const override {
        return "cmake --build .";
    };
};

class Meson : public BuildSystem {
public:
    string build() const override {
        return "meson compile -c .";
    };
};

class Cargo : public BuildSystem {
public:
    string build() const override {
        return "cargo build";
    };
};

class ProgrammingLanguage {
public:
    unique_ptr<BuildSystem> build_system;
    ProgrammingLanguage(){};
    ProgrammingLanguage(unique_ptr<BuildSystem> buildSystem_) : build_system(std::move(buildSystem_)) {};

    virtual string print_line(const string text) const = 0;
    virtual string for_each(const string text1, const string text2) const = 0;
    string build() const { return build_system->build();};
};

class Cpp : public ProgrammingLanguage {
public:
    Cpp() {};
    Cpp(unique_ptr<BuildSystem> buildSystem_) : ProgrammingLanguage(std::move(buildSystem_)) {};

    string print_line(const string text) const {
        string result = "cout << \"" + text + "\" << endl;";
        return result;
    }
    string for_each(const string text1, const string text2) const {
        string result = "for(auto &" + text1 + ": " + text2 + ") {}";
        return result;
    }
};

class Rust : public ProgrammingLanguage {
public:
    Rust(){};
    Rust(unique_ptr<BuildSystem> buildSystem) : ProgrammingLanguage(std::move(buildSystem)) {};

    string print_line(const string text) const {
        string result = "println!(\"" + text + "\");";
        return result;
    }
    string for_each(const string text1, const string text2) const {
        string result = "for " + text1 + " in &" + text2 + " {}";
        return result;
    }
};

template <typename T>
class Angle {
public:
    Angle(int value) : value(value % 360) {}; //deg
    Angle(double value) : value(fmod(value, M_PI)) {}; //rad

    // Overloading av <<-operatoren for utskrift
    friend ostream& operator<<(ostream& os, const Angle& angle ) {
        return os << angle.value;
    };

    template <typename T2>
    Angle<T> operator+(const T2 &number) {
        Angle angle = value + static_cast<T>(number); // caster til samme type som "value" er
        return angle;
    }


private:
    T value;
};

vector<int> parallell_transform(vector<int> a, vector<int> b, function<int(const int a_element, const int b_element)> f) {
    const int size = min(a.size(), b.size());
    const int num_threads = thread::hardware_concurrency();
    vector<int> result(size);
    vector<thread> threads;
    threads.reserve(num_threads); // pre-allocate memory
    //std::mutex mutex; dont need it

    for(size_t i = 0; i < num_threads; i++) {
        size_t start = i * size / num_threads;
        size_t end = (i+1)*size / num_threads;

        threads.emplace_back([&, start, end]() {
            for (size_t j = start; j < end; j++ ) {
                {
                    //std::lock_guard<std::mutex> lock(mutex); // Lock the critical section, not necessary here
                    result[start] = (f(a[j], b[j]));
                }
            }
        });
    };

    for (auto& thread : threads) {
        thread.join();
    }
    return result;
}

void task1() {
    cout << times_two(2) << endl;
    cout << times_two(2.25) << endl;
    cout << times_two("test") << endl;
    cout << times_two(vector<int>{1, 2, 3}) << endl;
}

void task2a() {
    vector<unique_ptr<ProgrammingLanguage>> programming_languages;
    // Uncommenting the following line should cause compilation error:
    // programming_languages.emplace_back(make_unique<ProgrammingLanguage>());
    programming_languages.emplace_back(make_unique<Cpp>());
    programming_languages.emplace_back(make_unique<Rust>());
    for (auto &programming_language : programming_languages) {
        cout << programming_language->print_line("Hello World") << endl;
        cout << programming_language->for_each("e", "vec") << endl
             << endl;
    }
}

void task2b(){
    vector<unique_ptr<ProgrammingLanguage>> programming_languages;
    programming_languages.emplace_back(make_unique<Cpp>(make_unique<CMake>()));
    programming_languages.emplace_back(make_unique<Cpp>(make_unique<Meson>()));
    programming_languages.emplace_back(make_unique<Rust>(make_unique<Cargo>()));
    for (auto &programming_language : programming_languages) {
        cout << programming_language->build() << endl;
    }
}

void task3() {
    cout << Angle<int>(30) << endl;
    cout << (Angle<int>(30) + 360) << endl;
    cout << (Angle<int>(30) + 3.14159265359) << endl;
    cout << Angle<double>(3.14159265359 / 2) << endl;
    cout << (Angle<double>(3.14159265359 / 2) + 3.14159265359) << endl;
    cout << (Angle<double>(3.14159265359 / 2) + 3) << endl;
}

void task4() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 5, 6};
    cout << parallell_transform(a, b, [](int a_element, int b_element) {
        return a_element + b_element;
    }) << endl;
    cout << parallell_transform(a, b, [](int a_element, int b_element) {
        return a_element * b_element;
    }) << endl;

}


int main() {
    task1();
    task2a();
    task2b();
    task3();
    task4();
}