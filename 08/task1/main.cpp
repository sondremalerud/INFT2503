#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Skal finne ut om to verdier er like
template <typename Type> bool
equal(Type a, Type b) {
    cout << "Bruker template-versjonen av equal()" << endl;
    return a == b;
}

bool equal(double a, double b) {
    cout << "Bruker double-versjonen av equal()" << endl;
    double result = abs(a-b);
    return result < 0.00001;
}

int main() {
    int a_int = 2;
    int b_int = 2;

    // template equals
    if (equal(a_int, b_int)) {
        cout << a_int << " = " << b_int << endl;
    }
    vector<double> a_vec;
    vector<double> b_vec;

    for (int i = 0; i < 3; ++i) {
        a_vec.emplace_back(i+3*0.2);
        b_vec.emplace_back(i+3*0.2);
    }

    // template equals
    if (equal(a_vec, b_vec)) {
        cout << "a_vec = b_vec" << endl;
    }

    double a = 1.234567;
    double b = 1.234568;

    // double equals
    if (equal(a, b)) {
        cout <<  setprecision(7) << a << " = " << b << endl;
    }
}