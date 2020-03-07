#include "Obrabiarka.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Obrabiarka::Obrabiarka(int _iRozmiar) {
	if (_iRozmiar < 0) {
		cout << "Rozmiar tablicy nie moze byc ujemny. Inicjalizacja obrabiarki z zestawieniem o rozmiarze 0.\n";
		_iRozmiar = 0;
	}

	iRozmiar = _iRozmiar;
	inicjalizujTablice();

	for (int i = 0; i < iRozmiar; ++i) {
		Czas nowyCzas;
		pZestawienie[i] = nowyCzas;
	}
}

Obrabiarka::Obrabiarka(const Obrabiarka& _oObrabiarka2) {
	iRozmiar = _oObrabiarka2.iRozmiar;
	Czas* pTemp;

	inicjalizujTablice();

	for (int i = 0; i < iRozmiar; ++i) {
		pZestawienie[i] = _oObrabiarka2.pZestawienie[i];
	}
}

void Obrabiarka::inicjalizujTablice() {
	Czas* _pWskaznik;

	if (!(_pWskaznik = (Czas*) malloc(iRozmiar * sizeof(*pZestawienie)))) {
		iRozmiar = 0;
		cout << "Blad podczas przydzielania pamieci.\n";
	}

	pZestawienie = iRozmiar == 0 ? nullptr : _pWskaznik;
}

void Obrabiarka::dodajCzas(Czas& _cNowyCzas) {
	Czas* temp = (Czas*)realloc(pZestawienie, (iRozmiar+1)*sizeof(*temp));

	if (!temp) {
		cout << "Blad podczas przydzielania pamieci.\n";
		return;
	}
	pZestawienie = temp;

	++iRozmiar;

	pZestawienie[iRozmiar - 1] = _cNowyCzas;
}

void Obrabiarka::wypiszCzasy() {
	for (int i = 0; i < iRozmiar; ++i) {
		(*this)[i].wypiszCzas();
	}
	cout << endl;
}

Czas Obrabiarka::zsumujCzasy() {
	Czas cSumaCzasow;
	for (int i = 0; i < iRozmiar; ++i) {
		cSumaCzasow = cSumaCzasow + pZestawienie[i];
	}
	return cSumaCzasow;
}

Obrabiarka::~Obrabiarka() {
	free(pZestawienie);
}

Czas Obrabiarka::operator[](int _iIndeks) {
	if (_iIndeks < 0) {
		_iIndeks = iRozmiar + _iIndeks;
	}

	if (_iIndeks >= iRozmiar) {
		cout << "Indeks poza granicami zestawienia.\n";
		Czas TempCzas;
		return TempCzas;
	}

	return pZestawienie[_iIndeks];
}