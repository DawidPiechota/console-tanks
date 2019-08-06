#include "Tank.h"
#include "Map.h"

Tank::Tank(int a, int b, int d, int ac, int s, int l):ActiveUnit(a,b,d,ac),speed(s),life(l),defx(a),defy(b)
{

}
int Tank::getSpeed()
{
	return speed;
}
int Tank::getLife()
{
	return life;
}
int Tank::getDefx()
{
	return defx;
}
int Tank::getDefy()
{
	return defy;
}
void Tank::setSpeed(int s)
{
	speed=s;
}
void Tank::setLife(int l)
{
	life=l;
}

void Tank::checkShot(Map & m,Bullet & b, char s)
{
if(GetAsyncKeyState(s) & 0x8000)								//Sprawdzenie czy jest wcisniety klawisz odpowiedzialny za strzal
{
	if(!(b.getActive())&&(life>0))								//warunki musza byc spelnione do strzalu
	{

		switch(dir)
		{
			case 1: 
			{
			if((m.check(x,y-1,dir,'b')!='#'))    //sprawdzenie czy czolg nie stoi przy scianie
			{
				b.setX(x);						 //Aktywowanie i ustawienie pocisku w miejsce przed czolgiem o danym kierunku
				b.setY(y-2);
				b.setDir(dir);
				b.setActive(1);
			}
			}break;
			case 2: 
			{
			if((m.check(x+1,y,dir,'b')!='#'))
			{
			b.setX(x+2);
			b.setY(y);
			b.setDir(dir);
			b.setActive(1);
			}
			}break;
			case 3: 
			{
			if((m.check(x,y+1,dir,'b')!='#'))
			{
			b.setX(x);
			b.setY(y+2);
			b.setDir(dir);
			b.setActive(1);
			}
			}break;
			case 4:
			{
			if((m.check(x-1,y,dir,'b')!='#'))
			{
			b.setX(x-2);
			b.setY(y);
			b.setDir(dir);
			b.setActive(1);
			}
			}break;
		}
	}
}
}

int Tank::checkHit(Bullet & b)
{
	if(b.getActive())
	if((x-b.getX())*(x-b.getX())+(y-b.getY())*(y-b.getY())<=2)								//Sprawdzenie trafienia
	{
		life--;																//W przypadku trafienia- odjecie zycia oraz deaktywacja pocisku
		b.setActive(0);
		return 1;
	}
return 0;
}


void Tank::update(Map & m,int direction)
{
	if(life>0)																// Sprawdzenie czy czolg nie zostal zniszczony
	switch(direction)
	{
		case 0: 
			break;
		
		case 1:			
			for(int i=0; i<speed; i++)
			{
			if( (m.check(x,y,1,'w')=='#')||(m.check(x,y,1,'t')=='@')) break;			// Sprawdzenie kolizji ze sciana/drugim czolgiem
				m.set(x,y,'0');															// usuniecie starej lokalizacji czolgu z mapy
				y--;																	// Ruch
				m.set(x,y,'@');															// Zapis czolgu na mapie
				gotoxyC(x-1,y-1);	cout << "@|@";										// Wyswietlenie czolgu na ekranie
				gotoxyC(x-1,y);		cout << "@@@";
				gotoxyC(x-1,y+1);	cout << "@ @";
				gotoxyC(x-1,y+2);	cout << "   ";										// Usuniecie pozostalosci za czolgiem
				dir=direction;
			}
			break;
		case 2:			
			for(int i=0; i<speed; i++)
			{
			if( (m.check(x,y,2,'w')=='#')||(m.check(x,y,2,'t')=='@') ) break;
				m.set(x,y,'0');
				x++;
				m.set(x,y,'@');
				gotoxyC(x-2,y-1); 	cout << " @@@";
				gotoxyC(x-2,y);		cout << "  @-";
				gotoxyC(x-2,y+1);	cout << " @@@";
				dir=direction;
			}
			break;
		case 3:			
			for(int i=0; i<speed; i++)
			{
			if( (m.check(x,y,3,'w')=='#')||(m.check(x,y,3,'t')=='@') ) break;
				m.set(x,y,'0');
				y++;
				m.set(x,y,'@');
				gotoxyC(x-1,y-2); 	cout << "   ";
				gotoxyC(x-1,y-1);	cout << "@ @";
				gotoxyC(x-1,y);		cout << "@@@";
				gotoxyC(x-1,y+1);	cout << "@|@";
				dir=direction;
			}
			break;
		case 4:	
			for(int i=0; i<speed; i++)
			{
			if( (m.check(x,y,4,'w')=='#')||(m.check(x,y,4,'t')=='@') ) break;
				m.set(x,y,'0');
				x--;
				m.set(x,y,'@');
				gotoxyC(x-1,y-1); 	cout << "@@@ ";
				gotoxyC(x-1,y);		cout << "-@  ";
				gotoxyC(x-1,y+1);	cout << "@@@ ";
				dir=direction;
			}
			break;
	}
	else{ gotoxyC(x,y); cout << "X";}
		
}

std::ostream& operator<<(std::ostream & ostr, Tank t)
{
	gotoxyC(t.x-1,t.y-1);	cout << "@|@";
	gotoxyC(t.x-1,t.y);		cout << "@@@";
	gotoxyC(t.x-1,t.y+1);	cout << "@ @";
	
}






