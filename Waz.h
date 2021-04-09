#pragma once
#include "Pole.h"


class Waz
{
	int X = 16;
	int Y = 9;
	int dlugosc = 5;
	int gdzieIdz = 1;
	bool gameover = false;
public:
	Waz(int X, int Y);
	int getDlugosc();
	void setDlugosc(int dlugosc);
	void idzPrawo(Pole** pola);
	void idzLewo(Pole** pola);
	void idzDol(Pole** pola);
	void idzGora(Pole** pola);
	void steruj();
	int getGdzieIdz();
	void sprawdz(Pole pole1);
	bool getGameOver();
};

