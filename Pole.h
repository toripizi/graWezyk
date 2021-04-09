#pragma once

class Pole {
private: 
	unsigned char znak = 0;
	bool czyJestWaz = false;
	int jakDlugo = 0;
	bool obramowanie = false;
	bool jedzenie = false;
public:
	Pole(unsigned char znak);
	Pole();
	Pole(const Pole& pole);
	const char getZnak();
	const bool getCzyJestWaz();
	const int getJakDlugo();
	const bool getJedzenie();
	void setZnak(char znak);
	void setCzyJestWaz(bool czy);
	void setJakDlugo(int ile);
	void setObramowanie(bool b);
	void setJedzenie(bool p);
	bool aktualizuj();
	Pole& operator=(const Pole& pole); //kopiuj¹cy operator przepisania
	Pole& operator=(Pole&& pole) noexcept; //przenosz¹cy operator przepisania
};