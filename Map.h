#ifndef MAP_H_
#define MAP_H_
#include <iostream>

class Map								//Klasa ktorej obiektem jest siatka wspolrzednych-mapa wczytywana z pliku
{
	char filename[40];					//Nazwa pliku z ktorego wczytywana jest mapa
	char grid[40][80];					//Tablica przechowujaca obaz mapy
public:
	Map();
	void getMap();						//Wczytanie mapy z pliku
	void set(int x, int y, char c);		//Ustawienie pojedynczej zmiennej w tablicy mapy
	char check(int x, int y, int dir,char type);	//Metoda do sprawdzania kolizji
	friend std::ostream& operator<<(std::ostream & ostr, Map m);	//Wyswietlanie mapy
	
};




#endif
