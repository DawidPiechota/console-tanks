#ifndef BULLET_H_
#define BULLET_H_
#include "ActiveUnit.h"
#include "Screen.h"
#include "Position.h"
#include "Map.h"

class Bullet: public ActiveUnit, public Screen								// Klasa ktorej obiektami sa pociski
{
	int speed;							// Szybkosc obiektu
	char type;							// Wyglad obiektu
public:
	Bullet(int a, int b, int d, int ac, int s, char t);
	int getSpeed();							// Gettery i settery
	char getType();
	void setSpeed(int s);
	void setType(char t);

	void update(Map & m, int direction);	// Zdefniniowanie funkcji z klasy wirtualnej
	
	
	
};



#endif
