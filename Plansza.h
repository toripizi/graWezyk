#pragma once
#include "Pole.h"
#include <iostream>
#include "Waz.h"

class Plansza
{
private:
	Pole** pola;
	int wysokosc;
	int szerokosc;
	bool gameOver = false;

public:
	Plansza(int szerokosc, int wysokosc);
	~Plansza();
	void wypisz();
	Pole** getPola();
	int getWysokosc();
	int getSzerokosc();
	bool getGameOver();
	void aktualizuj(Waz& waz);
	void wylosujJedzenie();
};

