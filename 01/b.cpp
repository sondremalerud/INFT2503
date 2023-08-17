#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main () {
    const int length = 5;
    double temperatures[length];
    double temperature;
    int under_10 = 0;
    int between_10_and_20 = 0;
    int over_20 = 0;

    read_temperatures(temperatures, length);

    for (int i = 1; i <= length; i++) {
        temperature = temperatures[i-1];

        cout << "Temperatur nr " << i << ": " << temperature << endl;

        if (temperature < 10) under_10++;
        else if (temperature <= 20) between_10_and_20++;
        else over_20++;
    }

    cout << "Antall under 10 er: " << under_10 << endl;
    cout << "Antall mellom 10 og 20 er: " << between_10_and_20 << endl;
    cout << "Antall over 20 er: " << over_20 << endl;

    return 0;
}

void read_temperatures(double temperatures[], int length) {
    const char filename[] = "../tallfil.dat";
    ifstream file; // definerer filvariabel
    file.open(filename); // åpner filen
    if (!file) {
        cout << "Feil ved åpning av innfil." << endl;
        exit(EXIT_FAILURE); //uthopp av programmet
    }

    for (int i = 0; i < length; ++i) {
        file >> temperatures[i]; // legger hvert tall i tabellen
    }

    file.close();
}




