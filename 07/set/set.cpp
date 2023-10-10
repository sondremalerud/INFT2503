#include "set.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Union
Set Set::operator+(const Set &other) {
    // lager en kopi av dette objektet, som til slutt skal returneres
    Set result = *this;

    for (int num : other.arr) {
        result+=num;
    }

    return result;
}

// Legg til tall
bool Set::operator+=(const int &other) {
    // tallet finnes allerede, returner false
    if ((find(arr.begin(), arr.end(), other) != arr.end())) return false;

    arr.emplace_back(other);
    return true;
}

// Sett mengde lik en annen
Set &Set::operator=(const Set &other) {
    arr = other.arr;
    return *this;
}

// Skriv ut mengde
ostream &operator<<(std::ostream &os, const Set &set) {
    os << "{ ";
    for (int value : set.arr) {
        os << value << " ";
    }
    os << "}" << endl;
    return os;
}