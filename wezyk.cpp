#include <iostream>
#include "Plansza.h"
#include <windows.h>
#include "Waz.h"
#include <conio.h>

using namespace std;

void czekaj(int sekundy, Waz& waz)
{
	double koniec_czekania;
	koniec_czekania = ((double)clock() + 30 - clock()/CLOCKS_PER_SEC);
	while ((double)clock() < koniec_czekania)
	{
		if (_kbhit())
		{
			waz.steruj();
		}
	}
}
void idzdoxy(int x, int y)
{
	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}
void steruj(Waz& waz, Plansza& plansza) {
	switch (waz.getGdzieIdz()) {
	case 1:
		waz.idzDol(plansza.getPola());
		break;
	case 2:
		waz.idzGora(plansza.getPola());
		break;
	case 3:
		waz.idzLewo(plansza.getPola());
		break;
	case 4:
		waz.idzPrawo(plansza.getPola());
		break;
	}
}

int main()
{
	Plansza plansza(70, 25);
	Waz waz(16, 20);

	system("cls");
	cout << "Punkty: " << waz.getDlugosc()*100;
	while(!plansza.getGameOver() && !waz.getGameOver()) {
		steruj(waz, plansza);
		plansza.aktualizuj(waz);
		plansza.wypisz();
		czekaj(1, waz);
		idzdoxy(0,0);
	}
	return 0;
}