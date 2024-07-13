#ifndef MEDICINE_H
#define MEDICINE_H

#include "Product.h"
#include <string>
#include <iostream>

class Medicine : public Product {
public:
    Medicine();
    Medicine(const std::string& nazwa, double cena, const std::string& terminwaznosci, const std::string& Instrukcjeprzechowywania);

    // Gettery
    const std::string& getExpirationDate() const;
    const std::string& getStorageInstructions() const;

    // Settery
    void setExpirationDate(const std::string& expirationDate);
    void setStorageInstructions(const std::string& storageInstructions);

    // Display
    void display() const;
    
private:
    std::string DataWaznosci;
    std::string InstrukcjePrzechowywania;
};

#endif // MEDICINE_H
