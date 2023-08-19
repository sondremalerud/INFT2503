#include <iostream>

int find_sum(const int *table, int length);

int main() {
    int numbers[20];

    for (int i = 0; i < 20; ++i) {
        numbers[i] = i+1;
    }

    // 55
    std::cout << find_sum(numbers, 10) << std::endl;

    // 65
    std::cout << find_sum(numbers + 10, 5) << std::endl;

    // 90
    std::cout << find_sum(numbers + 15, 5) << std::endl;

    return 0;
}

// Finner summen av elementene i en tabell
int find_sum(const int *table, int length) {
    int sum = 0;

    for (int i = 0; i < length; ++i) {
        sum += table[i];
    }

    return sum;
}