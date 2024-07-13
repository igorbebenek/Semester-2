#pragma once

class Macierz
{
	int a[10][10], wiersz, kolumna;

public:
	void inputmacierz();
	void outputmacierz();
	Macierz operator*(Macierz x);
	Macierz transponuj();


};