#include "Waz.h"
#include <conio.h>

Waz::Waz(int x, int y) : X(x), Y(y){}
int Waz::getDlugosc() {
	return dlugosc;
}
void Waz::setDlugosc(int dlugosc) {
	this->dlugosc = dlugosc;
}
void Waz::sprawdz(Pole pole) {
	if (pole.getJakDlugo()>0) {
		gameover = true;
	}
}
void Waz::idzPrawo(Pole** pola) {
	sprawdz(pola[Y][X + 2]);
	pola[Y][X + 2].setJakDlugo(dlugosc);
	pola[Y][X + 3].setJakDlugo(dlugosc);
	X += 2;
}
void Waz::idzLewo(Pole** pola) {
	sprawdz(pola[Y][X - 1]);
	pola[Y][X - 1].setJakDlugo(dlugosc);
	pola[Y][X - 2].setJakDlugo(dlugosc);
	X -= 2;
}
void Waz::idzDol(Pole** pola) {
	sprawdz(pola[Y - 1][X]);
	pola[Y - 1][X].setJakDlugo(dlugosc);
	pola[Y - 1][X + 1].setJakDlugo(dlugosc);
	Y -= 1;
}
void Waz::idzGora(Pole** pola) {
	sprawdz(pola[Y + 1][X]);
	pola[Y + 1][X].setJakDlugo(dlugosc);
	pola[Y + 1][X + 1].setJakDlugo(dlugosc);
	Y += 1;
}
void Waz::steruj() {
	unsigned char znak = _getch();
	switch (znak)
	{
	case 224: //klawisze specjalne
		znak = _getch();
		switch (znak)
		{
		case 72: //strza³ka w dol
			if (gdzieIdz != 2)
				gdzieIdz = 1;
			break;
		case 80: //strza³ka w gore
			if (gdzieIdz != 1)
				gdzieIdz = 2;
			break;
		case 75: //strza³ka w lewo
			if (gdzieIdz != 4)
				gdzieIdz = 3;
			break;
		case 77: //strza³ka w prawo
			if (gdzieIdz != 3)
				gdzieIdz = 4;
			break;
		}
		break;
	}
}

int Waz::getGdzieIdz() {
	return gdzieIdz;
}

bool Waz::getGameOver() {
	return gameover;
}
