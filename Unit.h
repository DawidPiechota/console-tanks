#ifndef UNIT_H_
#define UNIT_H_

class Unit							//podstawowa klasa jednostki w ukladzie wspolrzednych
{
protected:
	int x;							//pozycje x i y obiektu
	int y;
public:	
	Unit(int a, int b);							//gettery i settery
	int getX();
	int getY();
	void setX(int a);
	void setY(int b);
};

#endif
