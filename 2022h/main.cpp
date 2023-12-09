#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <functional>
#include <thread>
// #include <mutex> don't need

using namespace std;

string concat(string a, string b) {
    return a + b;
}

string concat(int a, int b) {
    return to_string(a) + to_string(b);
}

string concat(vector<string> vec) {
    string result;
    for (string s: vec) {
        result += s;
    }
    return result;
}

class Animal {
public:
    virtual string makeNoise() const = 0;
};

class Elephant : public Animal {
public:
    string makeNoise() const override { return "Toot!"; };
};

class Pig : public Animal {
    string makeNoise() const override { return "Honk!"; };
};

template<typename T1, typename T2>
vector<T2> map_f(const vector<T1> list, function<T2(const T1 element)> func) {
    vector<T2> result;
    transform(list.begin(), list.end(), back_inserter(result), func);

    return result;
}

template<typename T1>
ostream &operator<<(ostream &os, const vector<T1> &vec) {
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

template<typename T1>
class Matrix {
public:
    Matrix() {};

    Matrix(const vector<vector<int>> &vec) : mat(vec) {};

    Matrix<int> operator*(const Matrix<int> &other) const {
        if (mat[0].size() != other.mat.size())
            throw invalid_argument("Number of rows must equal to number of columns of the other matrix");

        const int num_threads = mat.size();
        vector<thread> threads;
        threads.reserve(num_threads);

        vector<vector<int>> result(mat.size(), vector<int>(other.mat[0].size(), 0));

        for (size_t i = 0; i < num_threads; i++) {
            // husk at "&" inne i [&] betyr "capture all variables by reference".
            threads.emplace_back([&, i]() {
                for (size_t j = 0; j < other.mat[0].size(); ++j) {
                    // for row in other matrix
                    for (size_t k = 0; k < other.mat.size(); ++k) {
                        result[i][j] += mat[i][k] * other.mat[k][j];
                    }
                }
            });
        }
        for (auto &thread: threads) {
            thread.join();
        }
        return Matrix<int>(result);
    }

    friend ostream &operator<<(ostream &os, const Matrix mat) {
        for (const auto &row: mat.mat) {
            os << "[ ";
            for (const auto &element: row) {
                os << element << " ";
            }
            os << "]" << endl;
        }
        return os;
    }

private:
    vector<vector<int>> mat;
};

void task1() {
    cout << concat("hello", "world") << endl;
    cout << concat(1, 2) << endl;
    cout << concat({"a", "b", "c"}) << endl;
}

void task2() {
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(make_unique<Elephant>());
    animals.emplace_back(make_unique<Elephant>());
    animals.emplace_back(make_unique<Pig>());

    for (auto &a: animals)
        cout << a->makeNoise() << endl;
}

void task3() {
    cout << map_f<int, int>({1, 2, 3}, [](int a) { return a * 2; }) << endl;
    cout << map_f<float, float>({1, 2.3, 3}, [](float a) { return a / 2; }) << endl;
    cout << map_f<string, string>({"hello", "world"}, [](string s) { return s + "."; }) << endl;
    cout << map_f<string, int>({"hello", "world"}, [](string s) { return s.size(); }) << endl;
}

void task4() {
    Matrix<int> m_a({{1, 2},
                     {3, 4},
                     {5, 6}});
    Matrix<int> m_b({{1, 2, 3},
                     {4, 5, 6}});

    cout << m_a << endl;
    cout << m_b << endl;
    cout << m_a * m_b << endl;
    cout << m_b * m_a << endl;

    Matrix<int> m_c({{1, 2}});
    Matrix<int> m_d({{2},
                     {2}});

    cout << m_c * m_d << endl;
    cout << m_d * m_c << endl;
}


int main() {
    task1();
    task2();
    task3();
    task4();
}