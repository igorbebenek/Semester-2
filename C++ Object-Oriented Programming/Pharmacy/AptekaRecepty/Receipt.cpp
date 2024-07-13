#include "Receipt.h"

Receipt::Receipt() : totalPrice(0.0) {}

const std::vector<Medicine>& Receipt::getMedicines() const {
    return medicines;
}

double Receipt::getTotalPrice() const {
    return totalPrice;
}

void Receipt::addMedicine(const Medicine& medicine) {
    medicines.push_back(medicine);
    totalPrice += medicine.getPrice();
}

void Receipt::removeMedicine(int index) {
    totalPrice -= medicines.at(index).getPrice();
    medicines.erase(medicines.begin() + index);
}
Receipt Receipt::operator+(const Receipt& other) const {
    Receipt result(*this);
    for (const Medicine& medicine : other.medicines) {
        result.addMedicine(medicine);
    }
    return result;
}