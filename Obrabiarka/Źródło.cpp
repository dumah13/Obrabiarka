#include "Czas.h"
#include "Obrabiarka.h"
#include <iostream>

int main(){
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

	std::cout << std::endl << czas1.getSekundy() << std::endl;
	std::cout << std::endl << czas1.getMinuty() << std::endl;
	std::cout << std::endl << czas1.getGodziny() << std::endl;

	czas1.wypiszCzas();

	czas2.setSekundy(95239);

	std::cout << std::endl << czas2.getSekundy() << std::endl;
	std::cout << std::endl << czas2.getMinuty() << std::endl;
	std::cout << std::endl << czas2.getGodziny() << std::endl;

	czas2.wypiszCzas();

	czas2 = czas1 + czas1 + 3000;

	std::cout << std::endl << (czas2 == czas1) << std::endl;
	std::cout << std::endl << (czas2 == czas2) << std::endl;
	std::cout << std::endl << (czas2 >= czas1) << std::endl;
	std::cout << std::endl << (czas2 > czas1) << std::endl;
	std::cout << std::endl << (czas2 <= czas1) << std::endl;
	std::cout << std::endl << (czas2 < czas1) << std::endl;
	std::cout << std::endl << (czas2 != czas1) << std::endl;
	std::cout << std::endl << (czas1 != czas1) << std::endl;

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

	int i;
	cin >> i;

	czas1.wypiszCzas();
	czas2.wypiszCzas();
}