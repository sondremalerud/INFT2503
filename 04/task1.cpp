#include <vector>
#include <iostream>

using namespace std;

// TASK 1
int main() {
    // C++ Vector tilsvarer Java ArrayList minus tregheten som arraylist har
    // Derfor brukes Vector i stedet for vanlige arrays i C++

    vector<double> numbers;

    numbers.reserve(5);
    for (int i = 0; i < 5; ++i) {
        numbers.emplace_back(i*i); // legger til noen tall
    }

    for (double number : numbers) {
        cout << number << " "; // skriver ut tallene
    }
    cout << endl;
    cout << "front(): " << numbers.front() << endl;
    cout << "back(): " << numbers.back() << endl;

    numbers.emplace(numbers.begin()+1, 999);
    cout << "front() after emplace: " << numbers.front() << endl;
}