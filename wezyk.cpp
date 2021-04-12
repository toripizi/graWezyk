#include <iostream>
#include "Plansza.h"
#include <windows.h>
#include "Waz.h"
#include <conio.h>

using namespace std;

int wysokosc;
int szerokosc;
int szybkosc;
clock_t time1;
clock_t time2;

void czekaj(clock_t koniec_czekania, Waz& waz)
{
	do
	{
		if (_kbhit())
		{
			waz.steruj();
		}
	} while (clock() < koniec_czekania);
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

void wybierzPoziomTrudnosci(int number) {
	switch (number) {
	case 1:
		szerokosc = 50;
		wysokosc = 20;
		szybkosc = 130;
		break;
	case 2:
		szerokosc = 50;
		wysokosc = 20;
		szybkosc = 90;
		break;
	case 3:
		szerokosc = 50;
		wysokosc = 20;
		szybkosc = 70;
		break;
	}
}

void showMenu(Waz& waz) {
	int number = 1;
	do {
		cout << "Wybierz Poziom trudności: " << endl;
		cout << "1. Latwy" << endl;
		cout << "2. Normalny" << endl;
		cout << "3. Trudny" << endl;
		if (number > 3 || number < 1) cout << "nie prawidłowa liczba, prosze wprowadzic jeszcze raz: ";
		cin >> number;
		idzdoxy(0, 0);
	} while (number > 3 || number < 1);
	system("cls");
	wybierzPoziomTrudnosci(number);
}

int main()
{
	Waz waz(4, 4);
	
	system("cls");

	showMenu(waz);

	Plansza plansza(szerokosc, wysokosc);

	while(!plansza.getGameOver() && !waz.getGameOver()) {
		time1 = clock();
		cout << "Punkty: " << waz.getDlugosc() << endl;
		steruj(waz, plansza);
		plansza.aktualizuj(waz);
		plansza.wypisz();
		idzdoxy(0,0);
		time2 = clock();
		czekaj(clock() + szybkosc - time2 + time1, waz);
	}


	return 0;
}