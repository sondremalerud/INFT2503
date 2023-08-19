Gitt følgende programbit:
```cpp
char text[5];
char *pointer = text;
char search_for = 'e';
cin >> text;
while (*pointer != search_for) {
  *pointer = search_for;
  pointer++;
}
```
Hva kan gå galt?
* `text` har kun allokert minne til maks-lengde 5 (fire bokstaver i tillegg til \0). Dersom bruker skriver inn et større ord vil programmet skrive over uønsket minne.
* While-løkken vil fortsette å gå til minnet utenfor ordet man skriver inn, dersom ordet _ikke_ inneholder `search_for`. Den vil da søke videre i minnet forbi de fem bytesa vi opprinnelig allokerte.