#pragma once

class Pole {
private: 
	unsigned char znak = 0;
	int jakDlugo = 0;
	bool obramowanie = false;
	bool jedzenie = false;
public:
	Pole(unsigned char znak);
	Pole();
	Pole(const Pole& pole);
	const char getZnak();
	const int getJakDlugo();
	const bool getJedzenie();
	void setZnak(char znak);
	void setJakDlugo(int ile);
	void setObramowanie(bool b);
	void setJedzenie(bool p);
	bool aktualizuj(int dlugoscWeza);
	Pole& operator=(const Pole& pole); //kopiuj�cy operator przepisania
	Pole& operator=(Pole&& pole) noexcept; //przenosz�cy operator przepisania
};