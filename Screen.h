#ifndef SCREEN_H_
#define SCREEN_H_
#include "Map.h"

class Screen								//Interfejs uzywany do wyswietlania obiektow na ekranie
{
public:
	virtual void update(Map & m, int direction)=0;
};


#endif
