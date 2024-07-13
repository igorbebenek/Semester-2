#ifndef PHARMACY_H
#define PHARMACY_H

#include <vector>
#include <string>
#include "Medicine.h"
#include "Receipt.h"

class Pharmacy {
public:
    Pharmacy();

    // czytac leki z pliku
    void readFromFile(const std::string& filename);

    // Gettery
    const std::vector<Medicine>& getMedicines() const;
    const std::vector<Receipt>& getReceipts() const;
    Receipt& getReceipt(int index);

    // dodaj i usun recepty
    void addReceipt(const Receipt& receipt);
    void removeReceipt(int index);

    // szukaj lekow po nazwie
    std::vector<Medicine> searchMedicinesByName(const std::string& name) const;
    void addMedicineToReceipt(int receiptIndex, const Medicine& medicine);
    void removeMedicineFromReceipt(int receiptIndex, int medicineIndex);
private:
    std::vector<Medicine> medicines;
    std::vector<Receipt> receipts;
};

#endif // PHARMACY_H
