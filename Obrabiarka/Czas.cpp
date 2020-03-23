#include <iostream>
#include <iomanip>
#include "Czas.h"

Czas::Czas(int _iSekundy, int _iMinuty, int _iGodziny) {
	iSekundy = _iSekundy;
	iMinuty = _iMinuty;
	iGodziny = _iGodziny;
}

int Czas::znormalizujCzas(int& _iCzas) {
	int iWyzszyCzas = _iCzas / 60;
	_iCzas = _iCzas % 60;
	return iWyzszyCzas;
}

void Czas::setSekundy(int _iSekundy) {
	if (_iSekundy < 0) {
		std::cout << "Czas nie moze byc mniejszy od zera. Wpisuje 0.\n" << "Podany czas: " << _iSekundy << " s\n";
	}
	else if (_iSekundy >= 60) {
		if ((iMinuty = znormalizujCzas(_iSekundy)) >= 60) iGodziny = znormalizujCzas(iMinuty);
		iSekundy = _iSekundy;
	}
	else iSekundy = _iSekundy;
}

void Czas::setCzas(int _iSekundy, int _iMinuty, int _iGodziny) {
	if (_iSekundy < 0) {
		std::cout << "Czas nie moze byc mniejszy od zera. Wpisuje 0 do sekund.\n" << "Podany czas: " << _iSekundy << " s\n";
		_iSekundy = 0;
	}
	if (_iMinuty < 0) {
		std::cout << "Czas nie moze byc mniejszy od zera. Wpisuje 0 do minut.\n" << "Podany czas: " << _iMinuty << " m\n";
		_iMinuty = 0;
	}
	if (_iGodziny < 0) {
		std::cout << "Czas nie moze byc mniejszy od zera. Wpisuje 0 do godzin.\n" << "Podany czas: " << _iGodziny << " g\n";
		_iGodziny = 0;
	}

	setSekundy(_iSekundy + _iMinuty*60 + _iGodziny*3600);
}

int Czas::getSekundy() {
	return iSekundy;
}

void Czas::setMinuty(int _iMinuty) {
	if (_iMinuty < 0) {
		std::cout << "Czas nie moze byc mniejszy od zera. Wpisuje 0\n" << "Podany czas: " << _iMinuty << " m\n";
	}
	else if (_iMinuty >= 60) {
		iGodziny += znormalizujCzas(_iMinuty);
		iMinuty = _iMinuty;
	}
	else iMinuty = _iMinuty;
}

int Czas::getMinuty() {
	return iMinuty;
}

void Czas::setGodziny(int _iGodziny) {
	if (_iGodziny < 0) { 
		std::cout << "Czas nie moze byc mniejszy od zera. Wpisuje 0.\n" << "Podany czas: " << _iGodziny << " g\n";
	}
	else iGodziny = _iGodziny;
}

int Czas::getGodziny() {
	return iGodziny;
}

void Czas::wypiszCzas() {
	std::cout << "Sekundy: " << std::setw(2) << iSekundy << " Minuty: " << 
		std::setw(2) << iMinuty << " Godziny: " << 
		std::setw(2) << iGodziny << std::endl;
}

int Czas::sprowadzDoSekund() {
	int iCalkowityCzasS;

	iCalkowityCzasS = iGodziny * 60 * 60 + iMinuty * 60 + iSekundy;

	return iCalkowityCzasS;
}

Czas Czas::operator+(int _iSekundy) {
	Czas temp;
	temp.setSekundy(sprowadzDoSekund() + _iSekundy);
	return temp;
}

Czas Czas::operator+(Czas _cCzas) {
	Czas temp;
	temp.setSekundy(sprowadzDoSekund() + _cCzas.sprowadzDoSekund());
	return temp;
}

Czas& Czas::operator+=(int _iSekundy) {
	this->setSekundy(sprowadzDoSekund() + _iSekundy);
	return *this;
}

Czas& Czas::operator++() {
	int iSekundyZnormalizowane = sprowadzDoSekund();
	(*this).setSekundy(++iSekundyZnormalizowane);
	return *this;
}

bool Czas::operator==(Czas& _cCzas) {
	return (sprowadzDoSekund() == _cCzas.sprowadzDoSekund());
}

bool Czas::operator<(Czas& _cCzas) {
	return (sprowadzDoSekund() < _cCzas.sprowadzDoSekund());
}

bool Czas::operator!=(Czas& _cCzas) {
	return !(*this == _cCzas);
}

bool Czas::operator<=(Czas& _cCzas) {
	return (*this == _cCzas || *this < _cCzas);
}

bool Czas::operator>(Czas& _cCzas) {
	return !(*this <= _cCzas);
}

bool Czas::operator>=(Czas& _cCzas) {
	return !(*this < _cCzas);
}