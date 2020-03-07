#include "Czas.h"

using namespace std;
#pragma once
class Obrabiarka
{
private:
	int iRozmiar;
	Czas* pZestawienie;
	void inicjalizujTablice();
public:
	Obrabiarka(int _iRozmiar = 0);
	Obrabiarka(const Obrabiarka& _oObrabiarka2);
	~Obrabiarka();
	void dodajCzas(Czas& _cNowyCzas);
	void wypiszCzasy();
	Czas zsumujCzasy();

	Czas operator[](int _iIndeks);
};

