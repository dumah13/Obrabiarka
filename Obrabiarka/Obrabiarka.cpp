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

	inicjalizujTablice();

	for (int i = 0; i < iRozmiar; ++i) {
		pZestawienie[i] = _oObrabiarka2.pZestawienie[i];
	}
}

Obrabiarka Obrabiarka::kopiuj(Czas _cZakres) {
	Obrabiarka oTemp;
	for (int i = 0; i < iRozmiar; i++)
	{
		if ((oTemp.zsumujCzasy() + (*this)[i]) <= _cZakres) {
			oTemp.dodajCzas((*this)[i]);
		}
		else return oTemp;
	}

	return oTemp;
}

Obrabiarka Obrabiarka::kopiuj(int _iN) {
	Obrabiarka oTemp(*this);

	if (_iN > iRozmiar) {
		cout << "Podana ilosc czasow jest wieksza od tej w zestawanieniu. Zwrocone zostanie cale zestawienie.\n";
		return oTemp;
	}
	if (_iN < 0) {
		_iN = iRozmiar + _iN;
	}
	if (_iN <= 0) {
		cout << "Nieprawidlowa ilosc czasow. Zwrocone zostanie puste zestawienie.\n";
		Obrabiarka oPusty;
		return oPusty;
	}

	oTemp.zmienTablice(_iN);

	return oTemp;
}

void Obrabiarka::inicjalizujTablice() 
{
	pZestawienie = new Czas[iRozmiar];
}

void Obrabiarka::zmienTablice(int _iNowyRozmiar) {
	int indeksKopiowania = iRozmiar >= _iNowyRozmiar ? _iNowyRozmiar : iRozmiar;
	Czas* pKopia = new Czas[_iNowyRozmiar];

	for (int j = 0; j < indeksKopiowania; j++) {
			pKopia[j] = pZestawienie[j];
	}

	iRozmiar = _iNowyRozmiar;
	delete[] pZestawienie;
	pZestawienie = pKopia;
}

int Obrabiarka::GetRozmiar() {
	return iRozmiar;
}

void Obrabiarka::dodajCzas(Czas _cNowyCzas) {
	zmienTablice(++iRozmiar);
	pZestawienie[iRozmiar - 1] = _cNowyCzas;
}

void Obrabiarka::wypiszCzasy() {
	if (!iRozmiar) {
		cout << "Puste zestawienie\n";
	}
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
	if (pZestawienie) delete[] pZestawienie;
}

Czas Obrabiarka::operator[](int _iIndeks) {
	if (_iIndeks < 0) {
		_iIndeks = iRozmiar + _iIndeks;
	}

	if (_iIndeks >= iRozmiar || _iIndeks < 0) {
		cout << "Indeks poza granicami zestawienia. Zostanie zwrocony pusty czas.\n";
		Czas TempCzas;
		return TempCzas;
	}

	return pZestawienie[_iIndeks];
}

Obrabiarka& Obrabiarka::operator=(Obrabiarka _oObrabiarka2) {
	swap(*this, _oObrabiarka2);

	return *this;
}