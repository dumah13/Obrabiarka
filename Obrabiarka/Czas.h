#pragma once
class Czas //ETAP 1.1
{
private:
	//Liczba sekund
	//Zakres 0-59
	int iSekundy;	//ETAP 1.1

	//Liczba minut
	//Zakres 0-59
	int iMinuty;	//ETAP 1.1

	//Liczba godzin
	//Zakres 0-MAXINT (chyba) 
	int iGodziny;	//ETAP1.1

	//Metody prywatne:

	//Metoda normalizuj¹ca sekundy i minuty do ich prawid³owych prezdzia³ów (np. 120s -> 2m, 6000s -> 1h 40 min itp.)
	int znormalizujCzas(int& _iCzas);

	//Metoda pomocnicza przeliczaj¹ca godziny, minuty i sekundy do sekund w celu np. porównania
	int sprowadzDoSekund();
public:
	//Konstruktor domyœlny/przeci¹¿ony (tylko s, s+m, s+m+g, ¿aden parametr)
	Czas(int _iSekundy = 0, int _iMinuty = 0, int _iGodziny = 0);	//ETAP 3.1

	//ETAP 3.2
	//Klasa Czas nie musi zawieraæ ¿adnego przeci¹¿onego desktruktora,
	//gdy¿ nie zawiera ona ¿adnych zmiennych dynamicznych, nie musi zwalniaæ ¿adnej pamiêci,
	//nie ma wiêc ryzyka zwi¹zanego np. z wyciekami pamiêci.
	//Destruktor utworzony przez kompilator w zupe³noœci wystarczy

	//Setter przeci¹¿ony dla wprowadzania czasu w dowolnej jednostce Czasu
	void setCzas(int _iSekundy, int _iMinuty = 0, int _iGodziny = 0);	//ETAP 2.1

	//Setter dla atrybutu iSekundy
	void setSekundy(int _iSekundy);	//ETAP 1.2

	//Getter dla atrybutu iSekundy
	int getSekundy();	//ETAP 1.2

	//Setter dla atrybutu iMinuty
	void setMinuty(int _iMinuty);	//ETAP 1.2

	//Getter dla atrybutu iMinuty
	int getMinuty();	//ETAP 1.2

	//Setter dla atrybutu iGodziny
	void setGodziny(int _iGodziny);	//ETAP 1.2

	//Getter dla atrybutu iGodziny
	int getGodziny();	//ETAP 1.2

	//Wypisuje w konsoli aktualnie przechowywany czas
	void wypiszCzas();	//ETAP 1.3

	//Przeci¹¿enia operatorów algebraicznych

	//Przeci¹¿ony operator dodawania odpowiedniej iloœci sekund do Czasu
	Czas operator+(int _iSekundy);

	//Przeci¹¿ony operator zwiêkszania Czasu o odpowiedni¹ iloœæ sekund
	Czas& operator+=(int _iSekundy);	//ETAP 2.2

	//Przeci¹¿ony operator preinkrementacji czasu (prawdopodobnie zupe³nie niepotrzebny)
	Czas& operator++();

	//Przeci¹¿ony operator dodawania dwóch Czasów (sumowanie czasów obróbki)
	Czas operator+(Czas _cCzas);	//ETAP 2.2

	//Przeci¹¿enia operatorów logicznych //ETAP 2.3

	bool operator==(Czas& _cCzas);
	bool operator>(Czas& _cCzas);
	bool operator<(Czas& _cCzas);
	bool operator>=(Czas& _cCzas);
	bool operator<=(Czas& _cCzas);
	bool operator!=(Czas& _cCzas);
};

