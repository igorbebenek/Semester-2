#include "Product.h"
#include <iostream>

Product::Product() : name(""), price(0.0) {}

Product::Product(const std::string& name, double price) : name(name), price(price) {}

const std::string& Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::setName(const std::string& name) {
    this->name = name;
}

void Product::setPrice(double price) {
    this->price = price;
}
