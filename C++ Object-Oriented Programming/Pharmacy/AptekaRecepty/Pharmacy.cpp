#include "Pharmacy.h"
#include "Medicine.h"
#include <fstream>
#include <sstream>


Pharmacy::Pharmacy() {}

void Pharmacy::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string nazwa;
        double cena;
        std::string terminwaznosci;
        std::string instrukcjeprzechowywania;

        std::getline(iss, nazwa, ',');
        iss >> cena;
        iss.ignore(); 
        std::getline(iss, terminwaznosci, ',');
        std::getline(iss, instrukcjeprzechowywania);

        Medicine medicine(nazwa, cena, terminwaznosci, instrukcjeprzechowywania);
        medicines.push_back(medicine);
    }

    file.close();
}





const std::vector<Medicine>& Pharmacy::getMedicines() const {
    return medicines;
}

const std::vector<Receipt>& Pharmacy::getReceipts() const {
    return receipts;
}

Receipt& Pharmacy::getReceipt(int index) {
    return receipts.at(index);
}

void Pharmacy::addReceipt(const Receipt& receipt) {
    receipts.push_back(receipt);
}

void Pharmacy::removeReceipt(int index) {
    receipts.erase(receipts.begin() + index);
}

std::vector<Medicine> Pharmacy::searchMedicinesByName(const std::string& name) const {
    std::vector<Medicine> foundMedicines;

    for (const Medicine& medicine : medicines) {
        if (medicine.getName() == name) {
            foundMedicines.push_back(medicine);
        }
    }

    return foundMedicines;
}



void Pharmacy::addMedicineToReceipt(int receiptIndex, const Medicine& medicine) {
    receipts.at(receiptIndex).addMedicine(medicine);
}

void Pharmacy::removeMedicineFromReceipt(int receiptIndex, int medicineIndex) {
    receipts.at(receiptIndex).removeMedicine(medicineIndex);
}