#include "Czas.h"
#include <utility>

#pragma once
class Obrabiarka	//ETAP 3.3
{
private:
	//Rozmiar zestawienia (iloœæ Czasów)
	int iRozmiar; //ETAP 3.3 - DOWOLNA SZEROKOŒÆ (w granicach rozs¹dku...)
	//WskaŸnik na pierwszy element zestawienia (tablica Czasów)
	Czas* pZestawienie;

	//Metoda pomocnicza do zmiany rozmiaru tablicy dynamicznej
	void zmienTablice(int _iNowyRozmiar);	//ETAP 3.3 - ROZSZERZALNOŒÆ
	//Metoda pomocnicza do inicjalizacji tablicy dynamicznej
	void inicjalizujTablice();	//ETAP 3.3 - TABLICA
public:

	//Konstruktor (domyœlny)
	Obrabiarka(int _iRozmiar = 0);

	//Konstruktor kopiuj¹cy
	Obrabiarka(const Obrabiarka& _oObrabiarka2); //ETAP 4.1 - ZASADA TRZECH

	//Getter dla atrybutu iRozmiar (iloœæ czasów)
	int GetRozmiar(); //ETAP 3.3a - ODCZYT ILOŒCI CZASÓW

	//Destruktor
	~Obrabiarka();	//ETAP 4.1 - ZASADA TRZECH

	//Metoda dodaj¹ca czas do zestawienia
	//_cNowyCzas - obiekt klasy Czas do dodania
	void dodajCzas(Czas _cNowyCzas); //ETAP 3.3a - DODAWANIE CZASU DO ZESTAWIENIA

	//Metoda wypisuj¹ca w konsoli wszystkie czasy w zestawieniu.
	void wypiszCzasy();	//ETAP 3.3c - WYPISANIE WSZYSTKICH CZASÓW W ZESTAWIENIU

	//Metoda sumuj¹ca wszystkie czasy w zestawieniu
	//Zwraca: obiekt klasy Czas bêd¹cy sum¹ wszystkich czasów w Obrabiarce
	Czas zsumujCzasy();	//ETAP 3.3b - ZSUMOWANIE WSZYSTKICH CZASÓW W ZESTAWIENIU

	//Metoda kopiuj¹ca Obrabiarkê z pierwszymi _iN elementami
	//Zwraca: obiekt klasy Obrabiarka
	Obrabiarka kopiuj(int _iN);	//ETAP 4.2 - METODA KOPIUJ¥CA PIERWSZE N CZASÓW OBRABIARKI

	//Metoda kopiuj¹ca Obrabiarkê z pierwszymi czasami zawieraj¹cymi siê w _cZakres
	//_cZakres - obiekt klasy Czas zawieraj¹cy graniczny czas
	//Zwraca: obiekt klasy Obrabiarka
	Obrabiarka kopiuj(Czas _cZakres);	//ETAP 4.3 - METODA KOPIUJ¥CA TYLKO TYLE PIERWSZYCH CZASÓW ILE MIEŒCI SIÊ W ZAKRESIE ZADANYM OBIEKTEM KLASY CZAS

	//Operatory:

	//Przeci¹¿ony operator tablicy do zabezpieczenia przed naruszeniem pamiêci, pozwalaj¹cy na odczyt konkretnego czasu z zestawienia
	//Pozwala na negatywn¹ indeksacjê (-1 to ostatni element itd.)
	Czas operator[](int _iIndeks);	//ETAP 3.3a - ODCZYT KONKRETNEGO CZASU Z ZESTAWIENIA

	//Przeci¹¿ony operator przypisania (u¿yte zosta³o przypisanie typu copy and swap idiom)
	Obrabiarka& operator=(Obrabiarka _oObrabiarka2);	//ETAP 4.1 - ZASADA TRZECH

	//Redefinicja funkcji swap w celu zastosowania przypisania idiomowego
	friend void swap(Obrabiarka& _oObrabiarka1, Obrabiarka& _oObrabiarka2) {
		using std::swap;

		swap(_oObrabiarka1.iRozmiar, _oObrabiarka2.iRozmiar);
		swap(_oObrabiarka1.pZestawienie, _oObrabiarka2.pZestawienie);
	}
};

