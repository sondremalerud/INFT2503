#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <functional>
#include <thread>
// #include <mutex> don't need

using namespace std;

// t1: output, t2: input, t3: first function output
template<typename T1, typename T2, typename T3>
T1 pipe(function<T3(const T2 x)> f1, function<T1(const T3 x)> f2, const T2 input) {
    T1 result = f2(f1(input));
    return result;
}


class Shape {
public:
    virtual int get_area() const = 0;
};

class Square : public Shape {
public:
    Square(int side) : side(side) {}

    int get_area() const override {
        return side * side;
    }

private:
    int side;
};

class Rectangle : public Shape {
public:
    Rectangle(int length, int height) : length(length), height(height) {}

    int get_area() const override {
        return length * height;
    }

private:
    int length;
    int height;
};

string clean_text(string input) {
    bool inside_parentheses = false;
    string result = "";
    for (char c: input) {
        if (c == '(') {
            inside_parentheses = true;
            continue;
        } else if (c == ')') {
            inside_parentheses = false;
            continue;
        }

        if (inside_parentheses) continue;

        result += c;
    }
    return result;
}

ostream &operator<<(ostream &os, const vector<bool> &vec) {
    os << "{ ";
    if (!vec.empty()) {
        if (vec[0]) os << "true";
        else os << "false";

        for (size_t i = 1; i < vec.size(); ++i) {
            os << ", ";
            if (vec[i]) os << "true";
            else os << "false";


        }
    }
    os << " }";
    return os;
}

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) if (num % i == 0) return false;

    return true;
}

vector<bool> parallell_prime(vector<int> a) {
    const int num_threads = thread::hardware_concurrency();
    vector<bool> result(a.size());
    vector<thread> threads;
    threads.reserve(num_threads); // pre-allocate memory

    for (size_t i = 0; i < num_threads; i++) {
        threads.emplace_back([&, i]() {
            result[i] = is_prime(a[i]);
        });
    }

    for (auto &thread: threads) {
        thread.join();
    }
    return result;
}


void task1() {
    // 4*10-1
    cout << pipe<int, int, int>([](int x) { return x * 10; },
                                [](int x) { return x - 1; }, 4) << endl;

    // hellohello.length
    cout << pipe<int, string, string>([](string x) { return x + x; },
                                      [](string x) { return x.length(); },
                                      "hello") << endl;
}

void task2() {
    vector<unique_ptr<Shape>> shapes;
    shapes.emplace_back(new Square(10));
    shapes.emplace_back(new Rectangle(10, 4));
    for (auto &shape: shapes)
        cout << shape->get_area() << endl;
}

void task3() {
    string input_a = "Hello (world)";
    string input_b = "INF(INI)T(E)25()03()";
    cout << clean_text(input_a) << endl;
    cout << clean_text(input_b) << endl;
}

void task4() {
    vector<int> a = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << parallell_prime(a) << endl;
}


int main() {
    task1();
    task2();
    task3();
    task4();
}