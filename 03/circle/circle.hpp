#ifndef INC_03_CIRCLE_HPP
#define INC_03_CIRCLE_HPP

const double pi = 3.141592;

class Circle {
public:
    Circle(double radius_);
    double get_area() const;
    double get_circumference() const;
private:
    double radius;
};


Circle::Circle(double radius_) : radius(radius_) {}

double Circle::get_area() const{
    return pi * radius * radius;
}

double Circle::get_circumference() const {
    double circumference = 2.0 * pi * radius;
    return circumference;
}

#endif //INC_03_CIRCLE_HPP
