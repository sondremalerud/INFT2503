#include <iostream>
#include "set.hpp"

using namespace std;

int main() {
    Set set;
    set+=2;
    set+=1;
    set+=2;
    set+=9;

    cout << "Skriver ut set: " << set << endl;

    Set set2;
    set2+=1;
    set2+=2;
    set2+=3;
    cout << "Skriver ut set2: " << set2 << endl;

    cout << "Skriver ut union av set og set2: " << set+set2 << endl;

    set = set + set2;
    cout << "Skriver ut set etter å ha satt den lik unionen: " << set << endl;

    return 0;
}