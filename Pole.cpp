#include "Pole.h"
#include <iostream>

Pole::Pole(unsigned char znak) : znak(znak) {}
Pole::Pole() : znak(' ') {}
Pole::Pole(const Pole& pole)
	: znak(pole.znak), jakDlugo(pole.jakDlugo), czyJestWaz(pole.czyJestWaz) {}
const char Pole::getZnak() {
	return znak;
}
const bool Pole::getCzyJestWaz() {
	return czyJestWaz;
}
const int Pole::getJakDlugo() {
	return jakDlugo;
}
const bool Pole::getJedzenie() {
	return jedzenie;
}
void Pole::setZnak(char znak) {
	this->znak = znak;
}
void Pole::setCzyJestWaz(bool czy) {
	this->czyJestWaz = czy;
}
void Pole::setJakDlugo(int ile) {
	this->jakDlugo = ile;
}
void Pole::setObramowanie(bool b) {
	this->obramowanie = b;
}

//kopiuj¹cy operator przepisania
Pole& Pole::operator=(const Pole& pole) {
	znak = pole.znak;
	jakDlugo = pole.jakDlugo;
	czyJestWaz = pole.czyJestWaz;
	return *this;
}

//przenosz¹cy operator przepisania
Pole& Pole::operator=(Pole&& pole) noexcept {
	std::swap(znak, pole.znak);
	std::swap(jakDlugo, pole.jakDlugo);
	std::swap(czyJestWaz, pole.czyJestWaz);
	return *this;
} 

bool Pole::aktualizuj() {
	if (jakDlugo == 0 && !obramowanie && !jedzenie) znak = ' ';
	else if (jakDlugo > 0 && jedzenie) {
		jakDlugo--;
		znak = 178;
		return false;
	}
	else if (jakDlugo > 0 && obramowanie) {
		jakDlugo--;
		znak = 178;
		return false;
	}
	else if (jakDlugo > 0) {
		jakDlugo--;
		znak = 178;
	}
	return true;
}
void Pole::setJedzenie(bool p) {
	jedzenie = p;
}