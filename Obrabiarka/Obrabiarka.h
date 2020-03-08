#include "Czas.h"
#include <utility>

#pragma once
class Obrabiarka
{
private:
	int iRozmiar;
	Czas* pZestawienie;

	void inicjalizujTablice();
public:
	//Konstruktor (domyœlny)
	Obrabiarka(int _iRozmiar = 0);
	//Konstruktor kopiuj¹cy
	Obrabiarka(const Obrabiarka& _oObrabiarka2);
	//Getter dla atrybutu iRozmiar (iloœæ czasów)
	int GetRozmiar();
	//Destruktor
	~Obrabiarka();

	//Funckja dodaj¹ca czas do zestawienia
	//_cNowyCzas - obiekt klasy Czas do dodania
	void dodajCzas(Czas _cNowyCzas);
	//Funkcja wypisuj¹ca w konsoli wszystkie czasy w zestawieniu.
	void wypiszCzasy();
	//Funkcja sumuj¹ca wszystkie czasy w zestawieniu
	//Zwraca: obiekt klasy Czas bêd¹cy sum¹ wszystkich czasów w Obrabiarce
	Czas zsumujCzasy();
	//Funkcja kopiuj¹ca Obrabiarkê z pierwszymi _iN elementami
	//Zwraca: obiekt klasy Obrabiarka
	Obrabiarka kopiuj(int _iN);
	//Funkcja kopiuj¹ca Obrabiarkê z pierwszymi czasami zawieraj¹cymi siê w _cZakres
	//_cZakres - obiekt klasy Czas zawieraj¹cy graniczny czas
	//Zwraca: obiekt klasy Obrabiarka
	Obrabiarka kopiuj(Czas _cZakres);

	//Operatory:

	Czas operator[](int _iIndeks);
	Obrabiarka& operator=(Obrabiarka _oObrabiarka2);

	//Redefinicja funkcji swap w celu zastosowania przypisania idiomowego

	friend void swap(Obrabiarka& _oObrabiarka1, Obrabiarka& _oObrabiarka2) {
		using std::swap;

		swap(_oObrabiarka1.iRozmiar, _oObrabiarka2.iRozmiar);
		swap(_oObrabiarka1.pZestawienie, _oObrabiarka2.pZestawienie);
	}
};

