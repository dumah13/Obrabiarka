#include "Czas.h"
#include <utility>

#pragma once
class Obrabiarka	//ETAP 3.3
{
private:
	//Rozmiar zestawienia (ilo�� Czas�w)
	int iRozmiar; //ETAP 3.3 - DOWOLNA SZEROKO�� (w granicach rozs�dku...)
	//Wska�nik na pierwszy element zestawienia (tablica Czas�w)
	Czas* pZestawienie;

	//Metoda pomocnicza do zmiany rozmiaru tablicy dynamicznej
	void zmienTablice(int _iNowyRozmiar);	//ETAP 3.3 - ROZSZERZALNO��
	//Metoda pomocnicza do inicjalizacji tablicy dynamicznej
	void inicjalizujTablice();	//ETAP 3.3 - TABLICA
public:

	//Konstruktor (domy�lny)
	Obrabiarka(int _iRozmiar = 0);

	//Konstruktor kopiuj�cy
	Obrabiarka(const Obrabiarka& _oObrabiarka2); //ETAP 4.1 - ZASADA TRZECH

	//Getter dla atrybutu iRozmiar (ilo�� czas�w)
	int GetRozmiar(); //ETAP 3.3a - ODCZYT ILO�CI CZAS�W

	//Destruktor
	~Obrabiarka();	//ETAP 4.1 - ZASADA TRZECH

	//Metoda dodaj�ca czas do zestawienia
	//_cNowyCzas - obiekt klasy Czas do dodania
	void dodajCzas(Czas _cNowyCzas); //ETAP 3.3a - DODAWANIE CZASU DO ZESTAWIENIA

	//Metoda wypisuj�ca w konsoli wszystkie czasy w zestawieniu.
	void wypiszCzasy();	//ETAP 3.3c - WYPISANIE WSZYSTKICH CZAS�W W ZESTAWIENIU

	//Metoda sumuj�ca wszystkie czasy w zestawieniu
	//Zwraca: obiekt klasy Czas b�d�cy sum� wszystkich czas�w w Obrabiarce
	Czas zsumujCzasy();	//ETAP 3.3b - ZSUMOWANIE WSZYSTKICH CZAS�W W ZESTAWIENIU

	//Metoda kopiuj�ca Obrabiark� z pierwszymi _iN elementami
	//Zwraca: obiekt klasy Obrabiarka
	Obrabiarka kopiuj(int _iN);	//ETAP 4.2 - METODA KOPIUJ�CA PIERWSZE N CZAS�W OBRABIARKI

	//Metoda kopiuj�ca Obrabiark� z pierwszymi czasami zawieraj�cymi si� w _cZakres
	//_cZakres - obiekt klasy Czas zawieraj�cy graniczny czas
	//Zwraca: obiekt klasy Obrabiarka
	Obrabiarka kopiuj(Czas _cZakres);	//ETAP 4.3 - METODA KOPIUJ�CA TYLKO TYLE PIERWSZYCH CZAS�W ILE MIE�CI SI� W ZAKRESIE ZADANYM OBIEKTEM KLASY CZAS

	//Operatory:

	//Przeci��ony operator tablicy do zabezpieczenia przed naruszeniem pami�ci, pozwalaj�cy na odczyt konkretnego czasu z zestawienia
	//Pozwala na negatywn� indeksacj� (-1 to ostatni element itd.)
	Czas operator[](int _iIndeks);	//ETAP 3.3a - ODCZYT KONKRETNEGO CZASU Z ZESTAWIENIA

	//Przeci��ony operator przypisania (u�yte zosta�o przypisanie typu copy and swap idiom)
	Obrabiarka& operator=(Obrabiarka _oObrabiarka2);	//ETAP 4.1 - ZASADA TRZECH

	//Redefinicja funkcji swap w celu zastosowania przypisania idiomowego
	friend void swap(Obrabiarka& _oObrabiarka1, Obrabiarka& _oObrabiarka2) {
		using std::swap;

		swap(_oObrabiarka1.iRozmiar, _oObrabiarka2.iRozmiar);
		swap(_oObrabiarka1.pZestawienie, _oObrabiarka2.pZestawienie);
	}
};

