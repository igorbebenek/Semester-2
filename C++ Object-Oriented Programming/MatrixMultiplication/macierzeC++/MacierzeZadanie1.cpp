#include<iostream>
#include<stdlib.h>
#include "Macierz.h"
using namespace std;
char selekcja;



int main()
{
    Macierz A, B, C;

    do {
        cout << "1. Wpisz wymiar i elementy macierzy A" << endl;
        cout << "2. Wpisz wymiar i elementy macierzy B" << endl;
        cout << "3. Pomnoz macierze i wyswietl macierz wynikowa C" << endl;
        cout << "4. Transponuj macierz A" << endl;
        cout << "5. Transponuj macierz B" << endl;
        cout << "6. Transponuj macierz wynikowa C" << endl;
        cout << "7. Wyjdz" << endl;
        cin >> selekcja;


        switch (selekcja)
        {
        case '1':
            cout << "Macierz A:" << endl;
            A.inputmacierz();
            break;
        case '2':
            cout << "Macierz B:" << endl;
            B.inputmacierz();
            C = A * B;
            break;
        case '3':
            cout << "Macierz wynikowa C:" << endl;
            C.outputmacierz();
            break;
        case '4':
            cout << "Macierz transponowana A:" << endl;
            A.transponuj();
            break;
        case '5':
            cout << "Macierz transponowana A:" << endl;
            B.transponuj();
            break;
        case '6':
            cout << "Macierz transponowana A:" << endl;
            C.transponuj();
            C.outputmacierz();
            break;
        case '7':
            cout << "Zegnam!" << endl;
            exit(0);

        default: cout << selekcja << "Nie jest mozliwym wyborem" << endl;

        }
    } while (selekcja != 7);



    return 0;


}

