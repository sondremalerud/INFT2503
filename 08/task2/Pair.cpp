#include "Pair.hpp"

template<typename Type1, typename Type2>
Pair<Type1, Type2>::Pair(Type1 type1, Type2 type2) : first(type1), second(type2) {}

template<typename Type1, typename Type2>
Pair<Type1, Type2> Pair<Type1, Type2>::operator+(const Pair<Type1, Type2> &other) const {
    Pair result = Pair(this->first + other.first, this->second + other.second);
    return result;
}

template<typename Type1, typename Type2>
bool Pair<Type1, Type2>::operator>(const Pair<Type1, Type2> &other) const {
    return (this->first+this->second > other.first+other.second);
}
