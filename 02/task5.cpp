#include <iostream>

int main() {
    double number;

    // Peker som peker til number
    double *pointer = &number;

    // Referanse som refererer til number
    double &reference = number;

    // Tre måter å tilordne verdi til number. Utskrift skal se slik ut: 123
    number = 1;
    std::cout << number;

    *pointer = 2;
    std::cout << number;

    reference = 3;
    std::cout << number;

    return 0;
}