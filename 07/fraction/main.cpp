#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

// Oppgave a)
// Overloader minus-operatoren for subtraksjon av Fraction
Fraction operator-(const int num, const Fraction &other) {
    return Fraction((num * other.denominator - other.numerator), other.denominator);
}

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);

    print("a = ", a);
    print("b = ", b);
    print("a - 3 = ", (a-3));
    print("2 - b = ", (2-b));

    print("Resultat fra oppg b) = ", 5 - 3 - a - 7 - b);
}

// Oppgave b):
//  Først blir minus-operatoren til heltall brukt på 5-3
//  Så blir minus-operatoren jeg lagde her på linje 13 brukt på resultatet minus brøken 'a'.
//  Deretter har vi en brøk minus 7, som bruker medlemsfunksjonen jeg skrev på linje 48 i fraction.cpp.
//  Til slutt har vi en brøk minus brøken 'b', da bruker medlemsfunksjonen på linje 41 i fraction.cpp.
//  Regner man på denne måten, vil man sitte igjen med -25/4, som er svaret programmet gir.