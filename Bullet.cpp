#include "Bullet.h"
#include <iostream>
using namespace std;

Bullet::Bullet(int a, int b, int d, int ac, int s, char t):ActiveUnit(a,b,d,ac),speed(s),type(t)
{
	type=t;
}
int Bullet::getSpeed()
{
	return speed;
}
char Bullet::getType()
{
	return type;
}
void Bullet::setSpeed(int s)
{
	speed=s;
}
void Bullet::setType(char t)
{
	type=t;
}

void Bullet::update(Map & m, int direction)
{
	if(active)
	{
		switch(dir)
		{
			case 1:
				{
					for(int i=0;i<speed;i++)
					{
						if((m.check(x,y,1,'b'))=='#'){gotoxyC(x,y); cout << " "; active=0 ;x=0;y=0;break;}					//Sprawdzenie kolizji z sciana
						else
						{
							y--;																	// W razie czystej drogi, poruszenie sie do przodu poprzez 
							gotoxyC(x,y); cout << type;												// wyswietlenie znaku w miejscu docelowym oraz usuniecie go ze starego miejsca
							gotoxyC(x,y+1); cout << " ";
							
						}
					}
				}
				break;
			case 2:
				{
					for(int i=0;i<speed;i++)
					{
						if((m.check(x,y,2,'b'))=='#'){gotoxyC(x,y); cout << " "; active=0;x=0;y=0;break;}
						else
						{
							x++;
							gotoxyC(x,y); cout << type;
							gotoxyC(x-1,y); cout << " ";
						}
					}
				}
				break;
			case 3:
				{
					
					for(int i=0;i<speed;i++)
					{
						if((m.check(x,y,3,'b'))=='#'){gotoxyC(x,y); cout << " "; active=0; x=0;y=0;break;}
						else
						{
							y++;
							gotoxyC(x,y); cout << type;
							gotoxyC(x,y-1); cout << " ";
						}
					}
				}
				break;
			case 4:
				{
					
					for(int i=0;i<speed;i++)
					{
						if((m.check(x,y,4,'b'))=='#'){gotoxyC(x,y); cout << " "; active=0; x=0;y=0;break;}
						else
						{
							x--;
							gotoxyC(x,y); cout << type;
							gotoxyC(x+1,y); cout << " ";
						}
					}
				}
				break;	
		}
	}
}







