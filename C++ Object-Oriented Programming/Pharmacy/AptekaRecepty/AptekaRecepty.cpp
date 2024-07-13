#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Product.h"
#include "Medicine.h"
#include "Receipt.h"
#include "Pharmacy.h"

void displayMenu() {
    std::cout << "1. Dodaj lek do recepty" << std::endl;
    std::cout << "2. Usun lek z recepty" << std::endl;
    std::cout << "3. Dodaj nowa recepte" << std::endl;
    std::cout << "4. Usun recepte" << std::endl;
    std::cout << "5. Pokaz recepte wedlug indeksu" << std::endl;
    std::cout << "6. Szukaj leku po nazwie" << std::endl;
    std::cout << "7. Wyjdz" << std::endl;
    std::cout << "8. Lista lekow" << std::endl;
}

int main() {
    Pharmacy pharmacy;

    // czytanie lekow z pliku
    pharmacy.readFromFile("medicines.txt");

    int choice;
    do {
        displayMenu();
        std::cout << "Wybierz opcje ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string nazwa;
            std::cout << "Wpisz nazwe leku: ";
            std::cin >> nazwa;
            std::vector<Medicine> foundMedicines = pharmacy.searchMedicinesByName(nazwa);


            if (!foundMedicines.empty()) {
                if (!pharmacy.getReceipts().empty()) {
                    int indeksrecepty = pharmacy.getReceipts().size() - 1;
                    pharmacy.addMedicineToReceipt(indeksrecepty, foundMedicines.front());
                    std::cout << "Lek dodany do recepty" << std::endl;
                }
                else {
                    std::cout << "Nie znaleziono recepty. Prosze dodaj najpierw recepte" << std::endl;
                }
            }
            else {
                std::cout << "Leku nie znaleziono. Prosze sprobuj ponownie." << std::endl;
            }

            break;
        }
        case 2: {
            size_t receiptIndex, indeksleku;
            std::cout << "Wpisz indeks recepty: ";
            std::cin >> receiptIndex;
            std::cout << "Wpisz indeks leku: ";
            std::cin >> indeksleku;
            pharmacy.removeMedicineFromReceipt(receiptIndex, indeksleku);
            break;
        }
        case 3: {
            Receipt r;
            pharmacy.addReceipt(r);
            break;
        }
        case 4: {
            int receiptIndex;
            std::cout << "Wpisz indeks recepty : ";
            std::cin >> receiptIndex;
            pharmacy.removeReceipt(receiptIndex);
            break;
        }
        case 5: {
            int receiptIndex;
            std::cout << "Wpisz indeks recepty: ";
            std::cin >> receiptIndex;
            const Receipt& r = pharmacy.getReceipt(receiptIndex);
            std::cout << "Produkty w recepcie: " << std::endl;
            for (const Medicine& m : r.getMedicines()) {
                m.display();
                std::cout << std::endl;
            }

            std::cout << "Cala kwota: " << r.getTotalPrice() << std::endl;
            break;
        }
        case 6: {
            std::string nazwa;
            std::cout << "Wpisz nazwe leku: ";
            std::cin >> nazwa;
            std::vector<Medicine> results = pharmacy.searchMedicinesByName(nazwa);

            for (const Medicine& m : results) {
                m.display();
                std::cout << std::endl;
            }
            break;
        }
        case 7:
            std::cout << "Wychodzimy..." << std::endl;
            break;
        case 8: {
            std::cout << "Lista lekow:" << std::endl;
            for (const Medicine& m : pharmacy.getMedicines()) {
                m.display();
                std::cout << std::endl;
            }
            break;
        }
        default:
            std::cout << "Nieprawidlowy wybor. Prosze sprobowac ponownie." << std::endl;
        }

    } while (choice != 7);

    
    for (const Receipt& r : pharmacy.getReceipts()) {
        
    }


    for (const Medicine& m : pharmacy.getMedicines()) {
       
    }


    return 0;
}
