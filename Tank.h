#ifndef TANK_H_
#define TANK_H_
#include "ActiveUnit.h"
#include "Screen.h"
#include <iostream>
#include "Position.h"
#include "Bullet.h"

using namespace std;

class Tank: public ActiveUnit, public Screen					//Klasa ktorej obiektami sa czolgi sterowane przez gracza
{
	int speed;							//szybkosc obiektu
	int life;							//ilosc punktow zycia
	const int defx;							//domyslne x i y
	const int defy;
public:
	Tank(int a, int b, int d, int ac, int s, int l);
	int getSpeed();							//gettery i settery
	int getLife();
	int getDefx();
	int getDefy();
	void setSpeed(int s);
	void setLife(int l);
	void checkShot(Map & m,Bullet & b,char s);							//Metoda wywolujaca "wystrzal" pocisku
	int checkHit(Bullet & b);											//Sprawdzenie trafienia
	
	void update(Map & m, int direction);								// Zdefniniowanie funkcji z klasy wirtualnej
	
	friend std::ostream& operator<<(std::ostream & ostr, Tank t);		//Przeladowanie operatora <<
};


#endif
