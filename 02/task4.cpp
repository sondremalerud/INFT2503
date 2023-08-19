int main() {
    int a = 5;
    int &b = a; // Denne feilet opprinnelig fordi den er satt opp som en referanse, uten å si hvilken variabel den faktisk skal referere.
    int *c;
    c = &b;
    a = b + *c; // Her feiler det fordi a og b ikke er pekere, de er originalt definert som int og referanse til int henholdsvis.
    b = 2; // Her feilet det fordi den prøver å sette adressen til b, til tallet 2. Dette funker ikke, og dersom man heller vil sette verdien til referansen til b, til 2, må man skrive det slik jeg rettet det opp.

    return 0;
}