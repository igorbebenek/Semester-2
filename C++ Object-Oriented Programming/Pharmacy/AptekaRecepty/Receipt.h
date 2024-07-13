#ifndef RECEIPT_H
#define RECEIPT_H

#include <vector>
#include "Medicine.h"

class Receipt {
public:
    // Konstruktory
    Receipt();

    // Gettery
    const std::vector<Medicine>& getMedicines() const;
    double getTotalPrice() const;

    // Dodaj i usun leki
    void addMedicine(const Medicine& medicine);
    void removeMedicine(int index);
    Receipt operator+(const Receipt& other) const;

private:
    std::vector<Medicine> medicines;
    double totalPrice;
};

#endif // RECEIPT_H
