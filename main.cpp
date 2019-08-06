#include <iostream>
#include <ctype.h>
#include "Bullet.h"
#include "Tank.h"
#include "Map.h"
#include "Position.h"
#include <conio.h>
using namespace std;

int speed=55;		// czestotliwosc "odswiezania" gry

int choice=0;		//	Ustawienie zmiennej wyboru w menu
int points1=0;		//	Zmienne przechowuj¹ce ilosc punktow
int points2=0;		
int pointsLimit=3;		//	Limit punktow
int ext=0;				//	Flaga wyjscia
void showIntro();		//	Funkcja wyswietlajaca pocz¹tkowy napis z tytulem gry
void showMenu();		//	Funkcja wyswietlajaca glowne menu
int play(int & p1, int & p2, int & e);   //Glowna funkcja gry
void results(int p1, int p2);			// wyswietlanie wynikow
void finalResults(int p1, int p2);		// wyswietlanie zwyciezcy
void showHowToPlay();					// wyswietlanie instrukcji
void showSettings();					// wyswietlanie opcji
void showProjectile(Bullet a, Bullet b);	// wyswietlanie szybkosci gry
void setProjectile(Bullet & b);				// ustawianie ^
void ShowConsoleCursor(bool showFlag);		// funkcja obslugujaca wyswietlanie migajacego kursora w konsoli- przeszkadzajace w grze czasu rzeczywistego
void showSpeed(int s);						// wyswietlanie szybkosci
void setSpeed(int & s);						// ustawianie szybkosci
void tankBoost(Tank & t,char speedboost);	//Prosta funkcja pokazujaca jak prosto i szybko mozna dodawac nowe elementy do gry.
											// tym przypadku przyspieszenie w trakcie trzymania odpowiedniego klawisza

int controls1();							// sterowanie gracza 1
int controls2();							// sterowanie gracza 2
int controlsMenu();							// sterowanie w menu

Map m;
Bullet B1(0,0,1,0,2,'o');							// Tworzenie obiektow
Bullet B2(0,0,1,0,2,'*');
Tank T1(5,5,1,1,2,1);
Tank T2(60,5,1,1,2,1);
int main()
{
	ShowConsoleCursor(false);
	showIntro();
	showMenu();
	do{
	choice=controlsMenu();								// glowny interface pozwalajacy zalaczyc gre, oraz ustawic kilka wartosci
		switch(choice)
		{
			case 1:
				{
					do{
					cout << m;
					play(points1,points2,ext);
					results(points1, points2);
					Sleep(3000);
					}while((points1!=pointsLimit)&&(points2!=pointsLimit)&&(ext==0));
					ext=0;
					finalResults(points1, points2);
					points1=points2=0;
					Sleep(3000);
					showMenu();
					Sleep(500);
				}break;
			case 2:
				{	
					system("cls");
					Sleep(100);
					showHowToPlay();
					Sleep(500);
					do{choice=controlsMenu();}while(choice!=27);
					choice=0;
					system("cls");
					Sleep(100);
					showMenu();
					Sleep(500);
				}break;
			case 3:
				{
					system("cls");
					Sleep(100);
					showSettings();
					Sleep(500);
					do{
						choice=controlsMenu();
						switch(choice)
						{
							case 1:
							{
								Sleep(100);
								m.getMap();
								system("cls");
								showSettings();
								Sleep(500);
							}break;
							case 2:
							{
								showProjectile(B1,B2);
								Sleep(500);
								do{
									choice=controlsMenu();
										switch(choice)
										{
											case 1:
											{
												Sleep(100);
												setProjectile(B1);
												Sleep(500);
												showProjectile(B1,B2);
											}break;
											case 2:
											{
												Sleep(100);
												setProjectile(B2);
												Sleep(100);
												showProjectile(B1,B2);
											}break;
											default: {}break;
										}
								}while(choice!=27);
								choice=0;
								system("cls");
								showSettings();
								Sleep(500);	
							}break;
							case 3:
							{
								showSpeed(speed);
								Sleep(500);
									do{
										choice=controlsMenu();
										switch(choice)
										{
											case 1:
												{
													Sleep(100);
													setSpeed(speed);
													Sleep(100);
													showSpeed(speed);
												}
											default: {}break;
										}
									}while(choice!=27);
								choice=0;
								system("cls");
								showSettings();
								Sleep(500);	
							}
							default: {}break;
						}
					}while(choice!=27);
					choice=0;
					system("cls");
					showMenu();
					Sleep(500);
				}break;
			case 4: { }break;
			default: { }break;
		}
	}while(choice!=27);
system("cls");
for(int i=0;i<20;i++) cout << endl;
cout << "                           THANKS FOR PLAYING!" << endl << endl;
for(int i=0;i<18;i++) cout << endl;
return 0;
}

int controls1()
{
	if(GetAsyncKeyState('W') & 0x8000) return 1;
	if(GetAsyncKeyState('D') & 0x8000) return 2;
	if(GetAsyncKeyState('S') & 0x8000) return 3;
	if(GetAsyncKeyState('A') & 0x8000) return 4;
	return 0;
}
int controls2()
{
	if(GetAsyncKeyState(VK_UP) & 0x8000)    return 1;
	if(GetAsyncKeyState(VK_RIGHT) & 0x8000) return 2;
	if(GetAsyncKeyState(VK_DOWN) & 0x8000)  return 3;
	if(GetAsyncKeyState(VK_LEFT) & 0x8000)  return 4;
	return 0;
}
int controlsMenu()
{
	if(GetAsyncKeyState('1') & 0x8000)			return 1;
	if(GetAsyncKeyState('2') & 0x8000)			return 2;
	if(GetAsyncKeyState('3') & 0x8000)			return 3;
	if(GetAsyncKeyState('4') & 0x8000)			return 4;
	if(GetAsyncKeyState(VK_ESCAPE) & 0x8000)    return 27;
return 0;	
}

void showIntro()
{
	system("cls");
	cout << "Dawid Piechota";
	for(int i=0;i<20;i++) cout << endl;
	cout << "            TTTTTTTTTTT      AA        NN     NN   KK   KK     SSSSSS " << endl;
	cout << "            TTTTTTTTTTT     AAAA       NNN    NN   KK  KK     SS       " << endl;
	cout << "                TTT        AA  AA      NN N   NN   KK KK     SS        " << endl;
	cout << "                TTT       AA    AA     NN  N  NN   KKKK       SSSSSSS  " << endl;
	cout << "                TTT      AAAAAAAAAA    NN   N NN   KK KK            SS " << endl;
	cout << "                TTT     AA        AA   NN    NNN   KK  KK          SS  " << endl;
	cout << "                TTT    AA          AA  NN     NN   KK   KK    SSSSSS   " << endl <<endl;
Sleep(2000);
}

void showMenu()
{
	system("cls");
	for(int i=0;i<19;i++) cout << endl;
	cout << "                                    MAIN MENU" << endl << endl;
	cout << "                               1.) PLAY!" << endl << endl;
	cout << "                               2.) HOW TO PLAY" << endl << endl;
	cout << "                               3.) SETTINGS" << endl << endl;
	cout << "                               Esc QUIT";
	
}

void showHowToPlay()
{
	system("cls");
	cout << " _" << endl;
	cout << "|\\" << endl;
	cout << "  \\" << endl;
	cout << "    Click the icon for font and window size settings" << endl;
	for(int i=0;i<12;i++) cout << endl;
	cout << "                                HOW TO PLAY" << endl << endl;
	cout << "             Set the console size: width to 80, and height to 50." << endl << endl;
	cout << "             Font: Raster font 12x16." << endl << endl;
	cout << "             Steering:     movement       fire " << endl << endl;
	cout << "             Player1       WASD            V   " << endl << endl;
	cout << "             Player2       ARROW KEYS      P   " << endl << endl;
	cout << "             Esc BACK";
	
}

void showSettings()
{
	system("cls");
	for(int i=0;i<19;i++) cout << endl;
	cout << "                                 SETTINGS" << endl << endl;
	cout << "                             1.) MAP CHANGE" << endl << endl;
	cout << "                             2.) PROJECTILE CHANGE " << endl << endl;
	cout << "                             3.) GAME SPEED" << endl << endl;
	cout << "                             Esc BACK";
	
	
}
void showProjectile(Bullet a, Bullet b)
{
	system("cls");
	for(int i=0;i<19;i++) cout << endl;
	cout << "                                 CHANGE PROJECTILE" << endl << endl;
	cout << "                             1.) PLAYER 1: " << a.getType() << endl << endl;
	cout << "                             2.) PLAYER 2: " << b.getType() << endl << endl;
	cout << "                             Esc BACK";
	
	
}
void setProjectile(Bullet & b)
{
	system("cls");
	for(int i=0;i<19;i++) cout << endl;
	cout << "                         Set projectile (1 character): ";
	char c;
	cin.clear();
	cin.sync();
	cin >> c;
	b.setType(c);
}
void showSpeed(int s)
{
	system("cls");
	for(int i=0;i<19;i++) cout << endl;
	cout << "                              Game speed: " << s << endl << endl;
	cout << "                             1.) CHANGE" << endl << endl;
	cout << "                             Esc BACK";
}
void setSpeed(int & s)
{
	system("cls");
	for(int i=0;i<19;i++) cout << endl;
	cout << "       Game speed (10-100, lower value=faster game clock): ";
	cin.clear();
	cin.sync();
	cin >> s;
	if((s<10)||(s>100)) s=55;
}
void tankBoost(Tank & t,char speedboost)
{
if(GetAsyncKeyState(speedboost) & 0x8000) t.setSpeed(2);
else t.setSpeed(1);
}

int play(int & p1, int & p2,int & e)
{
int score1=0;
int score2=0;
T1.setActive(1);
T2.setActive(1);
T1.setLife(1);
T2.setLife(1);
T1.setX(T1.getDefx());
T1.setY(T1.getDefy());
T2.setX(T2.getDefx());
T2.setY(T2.getDefy());
cout << T1 << T2;
	do{
	tankBoost(T1,'B');			//Przyspieszanie czolgu
	tankBoost(T2,'O');
	T1.update(m,controls1());	//Wyswietlanie czolgu w zaleznosci od funkcji sterujace;
	T2.update(m,controls2());
	T1.checkShot(m,B1,'V');		//sprawdzanie wystrzalu
	T2.checkShot(m,B2,'P');
	if(T1.checkHit(B2)) score2++;	//sprawdzanie trafienia->odpowiednia punktacja
	if(T2.checkHit(B1)) score1++;
	B1.update(m,1);				//Wyswietlanie (o ile aktywny) pocisku
	B2.update(m,1);
	Sleep(speed);				//Zegar gry
	if(GetAsyncKeyState(VK_ESCAPE) & 0x8000){e=1; break;}
	}while((score1==0)&&(score2==0));
	Sleep(1000);
	if(score1) p1++;		//Dodawanie punktu odpowiedniemu graczowi
	if(score2) p2++;
	m.set(T1.getX(),T1.getY(),'0');			// Usuwanie czolgu z mapy wspolrzednych po zakonczeniu rundy
	m.set(T2.getX(),T2.getY(),'0');
}

void results(int p1,int p2)
{
	system("cls");
	for(int i=0; i<19; i++) cout << endl;
	cout << "                                  SCORE:" << endl << endl;
	cout << "                          Player1:            Player2:" << endl;
	cout << "                          " << p1 << "                   " << p2 << endl << endl;
}

void finalResults(int p1, int p2)
{
	system("cls");
	for(int i=0; i<19; i++) cout << endl;
	if(p1>p2) cout << "                                 PLAYER 1 WINS!" << endl << endl;
	else if(p1<p2) cout << "                                 PLAYER 2 WINS!" << endl << endl;
	else cout << "                                  DRAW!" << endl << endl;	
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}





