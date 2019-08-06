#include"Map.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

	Map::Map()
	{
		fstream wej;
		wej.open("map.txt", ios::in);		//Domyslna mapa wczytywana z pliku map.txt
		if(!(wej.good())) exit(1);
	for(int y=0;y<40;y++)
		{
			for(int x=0;x<80;x++)
			{
				wej >> grid[y][x];
			}
		}
		
	wej.close();
	}
	void Map::getMap()						//Wczytanie swojej mapy
	{
		fstream wej;
		do{
		system("cls");
		for(int i=0;i<19;i++) cout << endl;
		cout << "                            Podaj nazwe pliku mapy: ";
		cin >> filename;
		wej.open(filename, ios::in);
		}while(!(wej.good()));
		
	for(int y=0;y<40;y++)
		{
			for(int x=0;x<80;x++)
			{
				wej >> grid[y][x];
			}
		}
		
	wej.close();
	}
	
	void Map::set(int x, int y, char c)
	{
		grid[y][x]=	c;
	}	
	
	char Map::check(int x, int y, int dir,char type)
	{
	if(type=='w')								//Kolizje scian, zwraca 0 gdy "czysto", # gdy sciana uniemozliwia ruch
		switch(dir)
		{
		case 0: 
			break;
		
		case 1:
			if( ((grid[y-2][x-1])=='#') || ((grid[y-2][x])=='#') || ((grid[y-2][x+1])=='#') ) return '#';
			else return 0;
			break;

		case 2:
			if( ((grid[y+1][x+2])=='#') || ((grid[y][x+2])=='#') || ((grid[y-1][x+2])=='#') ) return '#';
			else return 0;
			break;
			
		case 3:
			if( ((grid[y+2][x-1])=='#') || ((grid[y+2][x])=='#') || ((grid[y+2][x+1])=='#') ) return '#';
			else return 0;
			break;

		case 4:
			if( ((grid[y+1][x-2])=='#') || ((grid[y][x-2])=='#') || ((grid[y-1][x-2])=='#') ) return '#';
			else return 0;
			break;

		}
	else if(type=='b')								//Kolizje pocisku ze sciana
		switch(dir)
		{
		case 1:
			if(((grid[y-1][x])=='#')) return '#';
			else return 0;
			break;
		case 2:
			if((grid[y][x+1])=='#') return '#';
			else return 0;
			break;
		case 3:
			if((grid[y+1][x])=='#') return '#';
			else return 0;
			break;
		case 4:
			if((grid[y][x-1])=='#') return '#';
			else return 0;
			break;
		}
	else if(type=='t')								//Kolizje czolgu z innym czolgiem
		switch(dir)
		{
		case 1:
			if((grid[y-3][x-2]=='@')||(grid[y-3][x-1]=='@')||(grid[y-3][x]=='@')||(grid[y-3][x+1]=='@')||(grid[y-3][x+2]=='@')) return '@';
			else return 0;
			break;
		case 2:
			if((grid[y-2][x+3]=='@')||(grid[y-1][x+3]=='@')||(grid[y][x+3]=='@')||(grid[y+1][x+3]=='@')||(grid[y+2][x+3]=='@')) return '@';
			else return 0;
			break;
		case 3:
			if((grid[y+3][x-2]=='@')||(grid[y+3][x-1]=='@')||(grid[y+3][x]=='@')||(grid[y+3][x+1]=='@')||(grid[y+3][x+2]=='@')) return '@';
			else return 0;
			break;
		case 4:
			if((grid[y-2][x-3]=='@')||(grid[y-1][x-3]=='@')||(grid[y][x-3]=='@')||(grid[y+1][x-3]=='@')||(grid[y+2][x-3]=='@')) return '@';
			else return 0;
			break;
		}
	}
		
	std::ostream& operator<<(std::ostream & ostr, Map m)
	{
		{
	system("cls");

	for(int y=0; y<40; y++)	
		for(int x=0; x<80; x++)
		{
			if(m.grid[y][x]=='0') ostr << " ";
			else	ostr << m.grid[y][x];
		}
	return ostr;
}

	}
