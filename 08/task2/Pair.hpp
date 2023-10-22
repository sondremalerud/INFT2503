#ifndef INC_08_PAIR_HPP
#define INC_08_PAIR_HPP

template <typename Type1, typename Type2>
class Pair {
public:
    Type1 first;
    Type2 second;

    Pair(Type1 type1, Type2 type2);
    Pair operator+(const Pair &other) const; // legge sammen to par elementvis
    bool operator>(const Pair<Type1, Type2> &other) const; // sjekke om par er større enn annet par

};



#endif //INC_08_PAIR_HPP
