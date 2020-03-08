#pragma once
class Czas
{
private:
	int iSekundy;
	int iMinuty;
	int iGodziny;

	int znormalizujCzas(int& _iCzas);
	int sprowadzDoSekund();
public:
	//Konstruktor domyœlny/przeci¹¿ony
	Czas(int _iSekundy = 0, int _iMinuty = 0, int _iGodziny = 0);

	//Setter dla atrybutu iSekundy
	void setSekundy(int _iSekundy);
	//Getter dla atrybutu iSekundy
	int getSekundy();
	//Setter dla atrybutu iMinuty
	void setMinuty(int _iMinuty);
	//Getter dla atrybutu iMinuty
	int getMinuty();
	//Setter dla atrybutu iGodziny
	void setGodziny(int _iGodziny);
	//Getter dla atrybutu iGodziny
	int getGodziny();
	//Wypisuje w konsoli aktualnie przechowywany czas
	void wypiszCzas();

	//Definicje operatorów algebraicznych

	Czas operator+(int _iSekundy);
	Czas& operator++();
	Czas operator+(Czas _cCzas);

	//Definicje operatorów logicznych

	bool operator==(Czas& _cCzas);
	bool operator>(Czas& _cCzas);
	bool operator<(Czas& _cCzas);
	bool operator>=(Czas& _cCzas);
	bool operator<=(Czas& _cCzas);
	bool operator!=(Czas& _cCzas);
};

