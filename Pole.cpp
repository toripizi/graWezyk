#include "Pole.h"
#include <iostream>

Pole::Pole(unsigned char znak) : znak(znak) {}
Pole::Pole() : znak(' ') {}
Pole::Pole(const Pole& pole)
	: znak(pole.znak), jakDlugo(pole.jakDlugo) {}
const char Pole::getZnak() {
	return znak;
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
	return *this;
}

//przenosz¹cy operator przepisania
Pole& Pole::operator=(Pole&& pole) noexcept {
	std::swap(znak, pole.znak);
	std::swap(jakDlugo, pole.jakDlugo);
	return *this;
} 

bool Pole::aktualizuj(int dlugoscWeza) {
	if (jakDlugo == 0 && !obramowanie && !jedzenie) znak = ' ';
	else if (jakDlugo == dlugoscWeza && !jedzenie && !obramowanie) {
		jakDlugo--;
		znak = 151;
	}
	else if (jakDlugo == dlugoscWeza && jedzenie && !obramowanie) {
		jakDlugo--;
		znak = 151;
		return false;
	}
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