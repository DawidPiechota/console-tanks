#include "ActiveUnit.h"

ActiveUnit::ActiveUnit(int a, int b, int d, bool ac):Unit(a,b),dir(d),active(ac)
{
	
}
int ActiveUnit::getDir()
{
	return dir;
}
bool ActiveUnit::getActive()
{
	return active;
}
void ActiveUnit::setDir(int d)
{
	dir=d;
}
void ActiveUnit::setActive(bool ac)
{
	active=ac;
}
	
