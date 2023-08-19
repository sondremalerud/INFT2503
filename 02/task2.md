Dersom man skriver:
```cpp
char *line = nullptr;   // eller char *line = 0;
strcpy(line, "Dette er en tekst");
```
vil funksjonen strcpy prøve å kopiere teksten skrevet inn til en nullpointer, som ikke vil funke. `line` må være en char-array som er stor nok til at teksten vi ønsker å kopiere _og_ '\0' har plass.