#ifndef ACTIVEUNIT_H_
#define ACTIVEUNIT_H_
#include "Unit.h"

class ActiveUnit: public Unit
{
protected:
	int dir;							//kierunek ruchu/ustawienia punktu. Clockwise: 1-gora,2-prawo,3-dol,4-lewo
	bool active;
public:
	
	ActiveUnit(int a, int b, int d, bool ac);
	int getDir();							//gettery i settery
	bool getActive();
	void setDir(int d);
	void setActive(bool ac);
	
	
	
};




#endif
