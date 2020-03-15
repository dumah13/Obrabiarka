#include "Czas.h"
#include "Obrabiarka.h"
#include <iostream>
#include <ctime>
#include <string>
#include <random>

using namespace std;

int losowaZakres(int _iDolny, int _iGorny) {
	return _iDolny + rand() % (_iGorny - _iDolny + 1);
}

int main(){
	const int iMaksymalnaLiczbaObrabiarek = 20;

#pragma region Testy
	Czas czas1;
	Czas czas2;
	Czas czas3(10, 2, 3);
	Czas czas4(1);
	Czas czas5(1, 2);

	czas1 = czas2;

	czas3.wypiszCzas();
	czas4.wypiszCzas();
	czas5.wypiszCzas();

	czas1.wypiszCzas();
	czas2.wypiszCzas();

	czas1.setGodziny(2);
	czas1.setMinuty(5);
	czas1.setSekundy(58);

	cout << endl << czas1.getSekundy() << endl;
	cout << endl << czas1.getMinuty() << endl;
	cout << endl << czas1.getGodziny() << endl;

	czas1.wypiszCzas();

	czas2.setSekundy(95239);

	cout << endl << czas2.getSekundy() << endl;
	cout << endl << czas2.getMinuty() << endl;
	cout << endl << czas2.getGodziny() << endl;

	czas2.wypiszCzas();

	czas2 = czas1 + czas1 + 3000;

	cout << endl << (czas2 == czas1) << endl;
	cout << endl << (czas2 == czas2) << endl;
	cout << endl << (czas2 >= czas1) << endl;
	cout << endl << (czas2 > czas1) << endl;
	cout << endl << (czas2 <= czas1) << endl;
	cout << endl << (czas2 < czas1) << endl;
	cout << endl << (czas2 != czas1) << endl;
	cout << endl << (czas1 != czas1) << endl;

	++czas1;
	++czas1;

	Obrabiarka obrabiarka1(5);
	Obrabiarka obrabiarka2(obrabiarka1);
	Obrabiarka obrabiarka3;

	obrabiarka3.dodajCzas(czas1);
	obrabiarka3.dodajCzas(czas2);
	obrabiarka3.dodajCzas(czas3);
	obrabiarka3.dodajCzas(czas4);
	obrabiarka3.dodajCzas(czas5);

	obrabiarka1.dodajCzas(czas1);
	obrabiarka2.dodajCzas(czas2);

	obrabiarka1.wypiszCzasy();
	obrabiarka2.wypiszCzasy();
	obrabiarka3.wypiszCzasy();

	obrabiarka3[5].wypiszCzas();
	obrabiarka3[4].wypiszCzas();
	obrabiarka3[-4].wypiszCzas();

	obrabiarka1.zsumujCzasy().wypiszCzas();
	obrabiarka3.zsumujCzasy().wypiszCzas();

	cout << endl;

	obrabiarka1 = obrabiarka2;
	obrabiarka2 = obrabiarka3;

	obrabiarka1.wypiszCzasy();
	obrabiarka2.wypiszCzasy();
	obrabiarka3.wypiszCzasy();

	obrabiarka1 = obrabiarka3.kopiuj(2);

	for (int i = 0; i < 1000000; i++)
	{
		Czas testCzas(5, 5, 0);
		obrabiarka1 = obrabiarka3.kopiuj(5);
		obrabiarka2 = obrabiarka2.kopiuj(testCzas);
	}

	obrabiarka1.wypiszCzasy();
	obrabiarka2.wypiszCzasy();
	obrabiarka3.wypiszCzasy();

	obrabiarka2 = obrabiarka2.kopiuj(-2);
	obrabiarka2.wypiszCzasy();

	Czas zakres1(0, 10, 10);
	Czas zakres2(0, 0, 5);

	cout << "Test kopiwoania 2 \n";
	Obrabiarka obrabiarka4 = obrabiarka1.kopiuj(zakres1);
	obrabiarka4.wypiszCzasy();
	obrabiarka4 = obrabiarka1.kopiuj(zakres2);
	obrabiarka4.wypiszCzasy();

	obrabiarka4 = obrabiarka1.kopiuj(8);
	obrabiarka4.wypiszCzasy();

	czas1.wypiszCzas();
	czas2.wypiszCzas();

	srand(time(0));

	czas1.setCzas(0);
	czas1.wypiszCzas();
	czas1.setCzas(1, 4);
	czas1.wypiszCzas();
	czas1.setCzas(60, 9, 10);
	czas1.wypiszCzas();

	czas1 += 100;
#pragma endregion

#pragma region PetlaProgramu
	Obrabiarka obrabiarkiMenu[iMaksymalnaLiczbaObrabiarek];
	string sDeksryptory[iMaksymalnaLiczbaObrabiarek];
	Czas cZakresCzasu;
	int iIloscCzasow = losowaZakres(10, 20);
	int iKrokProgramu = 0;
	int i = 0;
	int iIloscObrabiarek = 1;
	int iWybranaObrabiarka = 0;
	int iIloscCzasowDoWysw = 0;
	bool bProgramOn = 1;

	for (int i = 0; i < iIloscCzasow; i++)
	{
		Czas cNowyCzas(losowaZakres(0, 59), losowaZakres(0, 59), losowaZakres(0, 3));
		obrabiarkiMenu[0].dodajCzas(cNowyCzas);
	}

	sDeksryptory[0] = "Oryginalny zestaw czasow procesow";

	cout << flush;
	system("cls");
	while (bProgramOn)
	{
		switch (iKrokProgramu)
		{
		case 0:
			iIloscCzasow = obrabiarkiMenu[iWybranaObrabiarka].GetRozmiar();

			cout << "Maksymalna liczba obrabiarek: " << iMaksymalnaLiczbaObrabiarek << "\tObecna liczba obrabiarek: " << iIloscObrabiarek << endl;
			cout << "Liczba czasow: " << iIloscCzasow << endl;
			cout << "Czasy procesow obrabiarki:" << endl;
			obrabiarkiMenu[iWybranaObrabiarka].wypiszCzasy();

			cout << "Wpisz co chcesz zrobic:" << endl
				<< "1 - Wypisz pierwsze n czasow" << endl
				<< "2 - Wypisz czasy ktore zawieraja sie odpowiednim zakresie czasu" << endl
				<< "3 - Wybierz zestawienie czasow (obrabiarke)" << endl
				<< "4 - Zakoncz program" << endl;
			cin >> iKrokProgramu;

			if (iKrokProgramu < 0 || iKrokProgramu > 4) {
				iKrokProgramu = 0;
				cout << "Podaj prawidlowy numer funkcji." << endl;
			}
			if (iIloscObrabiarek >= iMaksymalnaLiczbaObrabiarek && (iKrokProgramu == 1 || iKrokProgramu == 2)) {
				cout << "Osiagnieto maksymalna liczbe obrabiarek." << endl;
				iKrokProgramu = 0;
			}
			break;
		case 1:
			cout << "Podaj ilosc n czasow do wyswietlenia. (Dozwolona negatywna subskrypcja)" << endl;
			cin >> iIloscCzasowDoWysw;

			obrabiarkiMenu[iIloscObrabiarek] = obrabiarkiMenu[iWybranaObrabiarka].kopiuj(iIloscCzasowDoWysw);
			iWybranaObrabiarka = iIloscObrabiarek;
			++iIloscObrabiarek;
			sDeksryptory[iWybranaObrabiarka] = "Kopia obrabiarki z " + to_string(obrabiarkiMenu[iWybranaObrabiarka].GetRozmiar()) + " czasami.";

			iKrokProgramu = 0;

			if (!iIloscCzasowDoWysw) {
				iKrokProgramu = 0;
				continue;
			}
			cout << flush;
			system("cls");

			break;
		case 2:
			int sekundy;
			int minuty;
			int godziny;
			cout << "Podaj liczbe godzin" << endl;
			cin >> godziny;
			cout << "Podaj liczbe minut" << endl;
			cin >> minuty;
			cout << "Podaj liczbe sekund" << endl;
			cin >> sekundy;
			cZakresCzasu.setCzas(sekundy,minuty,godziny);

			obrabiarkiMenu[iIloscObrabiarek] = obrabiarkiMenu[iWybranaObrabiarka].kopiuj(cZakresCzasu);
			iWybranaObrabiarka = iIloscObrabiarek;
			++iIloscObrabiarek;
			sDeksryptory[iWybranaObrabiarka] = "Kopia obrabiarki mieszczaca sie w zakresie " + to_string(cZakresCzasu.getGodziny()) + " godzin, "
				+ to_string(cZakresCzasu.getMinuty()) + " minut i " + to_string(cZakresCzasu.getSekundy()) + " sekund.";

			iKrokProgramu = 0;

			cout << flush;
			system("cls");

			break;
		case 3:
			cout << "Wybierz obrabiarke z listy (wpisujac jej numer):" << endl;
			for (i = 0; i < iIloscObrabiarek; i++) {
				cout << "Obrabiarka " << i << " - " << sDeksryptory[i] << endl;
			}
			cin >> iWybranaObrabiarka;
			iKrokProgramu = 0;

			if (iWybranaObrabiarka < 0 || iWybranaObrabiarka >= iIloscObrabiarek) {
				cout << "Nie ma takiej obrabiarki." << endl;
				iWybranaObrabiarka = 0;
				iKrokProgramu = 3;
			}
			else {
				cout << flush;
				system("cls");
			}

			break;
		case 4:
		case 100:
			bProgramOn = 0;
			break;
		default:
			break;
		}
	}
#pragma endregion

	cout << "Koncze program...\n";

	return 0;
}