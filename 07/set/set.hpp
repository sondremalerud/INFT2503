#include <iostream>
#include <vector>

#pragma once

using namespace std;

class Set{
public:

    // lager en ny tabell
    Set() {
        arr = vector<int>();
    }

    Set(const Set &other) {
        arr = other.arr;
    }

    Set operator+(const Set &other);
    bool operator+=(const int &other);
    Set &operator=(const Set &other);
    friend ostream &operator<<(ostream &os, const Set &set);


private:
    vector<int> arr;
};