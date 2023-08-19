#include <iostream>

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    // 1a)
    // Her ser vi at p og q skriver ut adressene til i og j henholdsvis
    std::cout << "i adresse: " << &i << "\ni verdi: " << i << std::endl;
    std::cout << "j adresse: " << &j << "\nj verdi: " << j << std::endl;
    std::cout << "p adresse: " << &p << "\np verdi: " << p << std::endl;
    std::cout << "q adresse: " << &q << "\nq verdi: " << q << std::endl;

    // 1b)
    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    // Skriver ut 8 8, som forventet
    std::cout << *p << " " << *q << std::endl;
    return 0;
}
