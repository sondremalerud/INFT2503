#include <iostream>
#include <string>
using namespace std;

// TASK 4
int main() {

    // a)
    std::string word1;
    std::string word2;
    std::string word3;
    std::cout << "Skriv tre ord (trykk enter etter hvert ord)" << std::endl;

    std::cin >> word1;
    std::cin >> word2;
    std::cin >> word3;

    // b)
    std::string sentence = word1 + " " + word2 + " " + word3 + ".";

    // c)
    std::cout << word1.length() << std::endl;
    std::cout << word2.length() << std::endl;
    std::cout << word3.length() << std::endl;
    std::cout << sentence.length() << std::endl;

    // d)
    std::string sentence2 = sentence;

    // e)
    for (int i = 9; i < 12; ++i) {
        sentence2[i] = 'x';
    }

    std::cout << sentence2 << std::endl;


    // f)
    std::string sentence_start = sentence.substr(0, 5);

    std::cout << "sentence: " << sentence << std::endl;
    std::cout << "sentence_start: " << sentence_start << std::endl;

    // g)
    if (sentence.find("hallo") != std::string::npos) {
        std::cout << "setningen inneholder \"hallo\"" << std::endl;
    } else {
        std::cout << "setningen inneholder ikke \"hallo\"" << std::endl;
    }

    // h)
    int index = 0;
    int count = 0;
    while ((index = sentence.find("er", index)) != std::string::npos) {
        count++;
        index += 2; // length of "er"
    }
    std::cout << "setningen inneholder " << count << " forekomster av \"er\"" << std::endl;

}