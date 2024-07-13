#include "Medicine.h"
#include <iostream>

Medicine::Medicine() : Product(), DataWaznosci(""), InstrukcjePrzechowywania("") {}

Medicine::Medicine(const std::string& name, double price, const std::string& expirationDate, const std::string& storageInstructions)
    : Product(name, price), DataWaznosci(expirationDate), InstrukcjePrzechowywania(storageInstructions) {}

const std::string& Medicine::getExpirationDate() const {
    return DataWaznosci;
}

const std::string& Medicine::getStorageInstructions() const {
    return InstrukcjePrzechowywania;
}

void Medicine::setExpirationDate(const std::string& expirationDate) {
    this->DataWaznosci = expirationDate;
}

void Medicine::setStorageInstructions(const std::string& storageInstructions) {
    this->InstrukcjePrzechowywania = storageInstructions;
}

void Medicine::display() const {
    std::cout << "Nazwa: " << name << std::endl;
    std::cout << "Kwota: $" << price << std::endl;
    std::cout << "Data waznosci: " << DataWaznosci << std::endl;
    std::cout << "Instrukcje przechowywania: " << InstrukcjePrzechowywania << std::endl;
}
