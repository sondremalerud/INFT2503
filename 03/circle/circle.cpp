#include "circle.hpp"
#include <iostream>
using namespace std;

// TASK 2
int main() {
    Circle circle = Circle(5);

    double area = circle.get_area();
    cout << "Arealet er lik " << area << endl;

    double circumference = circle.get_circumference();
    cout << "Omkretsen er lik " << circumference << endl;
}