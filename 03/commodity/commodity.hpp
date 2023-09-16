#ifndef INC_03_COMMODITY_HPP
#define INC_03_COMMODITY_HPP

#include "string"

const double tax_rate = 1.25;


class Commodity {
public:
    Commodity(std::string name_, int id, double price_);
    std::string get_name() const;
    int get_id() const;
    double get_price(double amount) const;
    double get_price() const;
    void set_price(double price_);
    double get_price_with_sales_tax(double amount) const;
    double get_price_with_sales_tax() const;

private:
    std::string name;
    int id;
    double price;
};

Commodity::Commodity( std::string name_, int id_, double price_) : name(name_), id(id_), price(price_) {}

std::string Commodity::get_name() const {
    return name;
}

int Commodity::get_id() const {
    return id;
}

double Commodity::get_price(double amount) const {
    return price * amount;
}

double Commodity::get_price() const {
    return price;
}


void Commodity::set_price(double price_) {
    price = price_;
}

double Commodity::get_price_with_sales_tax(double amount) const {
    return price * tax_rate * amount;
}

double Commodity::get_price_with_sales_tax() const {
    return price * tax_rate;
}


#endif //INC_03_COMMODITY_HPP
