#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product();
    Product(const std::string& name, double price);

    // Gettery
    const std::string& getName() const;
    double getPrice() const;

    // Settery
    void setName(const std::string& name);
    void setPrice(double price);

protected:
    std::string name;
    double price;
};

#endif // PRODUCT_H
