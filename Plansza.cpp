#include "Plansza.h"
#include <iostream>
#include <ctime>

Plansza::Plansza(int szerokosc, int wysokosc)
	: szerokosc(szerokosc), wysokosc(wysokosc) {
	pola = new Pole* [wysokosc];
	for (int i = 0; i < wysokosc; i++) {
		pola[i] = new Pole[szerokosc];
		for (int j = 0; j < szerokosc; j++) {
			if (i == 0 || i == wysokosc - 1 || j == 0 || j == szerokosc - 1 || j == 1 || j == szerokosc - 2) {
				pola[i][j].setZnak(219);
				pola[i][j].setObramowanie(true);
			}
		}
	}
	wylosujJedzenie();
}
Plansza::~Plansza() {
	for (int i = 0; i < wysokosc; i++) {
		delete[] pola[i];
	}
	delete[] pola;
	pola = nullptr;
}

void Plansza::wypisz() {
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			std::cout << pola[i][j].getZnak();
		}
		std::cout << std::endl;
	}
}

Pole** Plansza::getPola() {
	return pola;
}

int Plansza::getWysokosc() {
	return wysokosc;
}
int Plansza::getSzerokosc() {
	return szerokosc;
}
bool Plansza::getGameOver() {
	return gameOver;
}
void Plansza::aktualizuj(Waz& waz) {
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			if (!pola[i][j].aktualizuj(waz.getDlugosc())) {
				if (pola[i][j].getJedzenie()) {
					waz.setDlugosc(waz.getDlugosc() + 1);
					pola[i][j].setJedzenie(false);
					wylosujJedzenie();
				}
				else gameOver = true;
			}
		}
	}
}
void Plansza::wylosujJedzenie() {
	srand((unsigned)time(NULL));
	int X;
	int Y;
	X = (rand() % (szerokosc-4)) + 2;
	Y = (rand() % (wysokosc-2)) + 1;
	pola[Y][X].setZnak(3);
	pola[Y][X].setJedzenie(true);
}
