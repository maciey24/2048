/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: maciek
 *
 * Created on 23 maja 2017, 15:07
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <unistd.h>
#include <chrono>
#include <thread>



using namespace std;

void wyswietl (int tab[4][4], int *score);
void dwie (int plansza[4][4]);
void losujkloca (int plansza[4][4]);
void powitanie();
void przesun (int plansza[4][4], char *litera, int *zmiana, int *score);
void wait();
int puste (int plansza[4][4]);
int dasie (int plansza[4][4]);
int goal (int plansza[4][4]);
void wygral();
void go();


int main()
{
	
powitanie();
Start:
srand(time(NULL));
const int w=4, k=4;
int plansza[w][k];
char kierunek='0'; 
char dalej, nowagra='y';
int ruch=0, lost=0, ponad=0, wynik=0;
////////////////////
dwie (plansza);

for ( ; ; )
{	
		system("cls");
		wyswietl (plansza, &wynik); 
		
		if (ponad==0)
		{
			if(goal(plansza)==1)
			{
				wygral();
				ponad=1;
					do
					{	
						system("cls");
						cout<<"DO YOU WISH TO CONTINUE? [y/n]";
						dalej=getch();
					} while (dalej!='y'&&dalej!='Y'&&dalej!='n'&&dalej!='N');
			
					if (dalej=='n'||dalej=='N')
					{
						go();
						getch();
							do
							{	
								system("cls");
								cout<<"PLAY AGAIN? [y/n]";
								nowagra=getch();
							} while (nowagra!='y'&&nowagra!='Y'&&nowagra!='n'&&nowagra!='N');
						if (nowagra=='n'||nowagra=='N') return 0;
						else goto Start;
					}
					
					if (dalej=='y'||dalej=='Y')
					{
						system("cls");
						wyswietl (plansza, &wynik); 
					}
			}
		}
		
		if(puste(plansza)==0&&dasie(plansza)==0)
		{
			go();
			getch();
				do
				{	
					system("cls");
					cout<<"PLAY AGAIN? [y/n]";
					nowagra=getch();
				} while (nowagra!='y'&&nowagra!='Y'&&nowagra!='n'&&nowagra!='N');
			if (nowagra=='n'||nowagra=='N') return 0;
			else goto Start;
		}
		
		ruch=0;
		
		do
		{
			kierunek=getch();
		}	
		while (kierunek!='w'&&kierunek!='a'&&kierunek!='s'&&kierunek!='d'&&kierunek!='8'&&kierunek!='4'&&kierunek!='5'&&kierunek!='6');
		
		przesun(plansza, &kierunek, &ruch, &wynik);
		
		if (ruch==1)
		losujkloca (plansza);
}

return 0;
}

void wyswietl(int tab[4][4], int *score)
{
cout<<"\n\n\n"<<"\t\t\t|-------|-------|-------|-------|"<<"\n"<<"\t\t\t|\t|\t|\t|\t|"<<"\n";
	for (int j=0; j<4; j++)
	{cout<<"\t\t\t|";
		for (int i=0; i<4; i++)
		{if (tab[i][j]==0)
		cout<<"\t";
			else if (tab[i][j]<10)
			cout<<"   "<<tab[i][j]<<"   ";
				else if (tab[i][j]<100)
				cout<<"  "<<tab[i][j]<<"   ";
					else if (tab[i][j]<1000)
					cout<<"  "<<tab[i][j]<<"  ";
						else if (tab[i][j]<10000)
						cout<<" "<<tab[i][j]<<"  ";
							else if (tab[i][j]<100000)
							cout<<" "<<tab[i][j]<<" ";
			cout<<"|";
		}
	cout<<"\n"<<"\t\t\t|"<<"\t|\t|\t|\t|";
	cout<<"\n"<<"\t\t\t|"<<"-------|-------|-------|-------|";
	if (j<3)
	cout<<"\n"<<"\t\t\t|"<<"\t|\t|\t|\t|\n";
	}
	cout<<"\n\n\tSCORE: "<<*score;
}

void powitanie()
{
	cout<<"HELLO!\n";
	getch();
	system("cls");
	cout<<"THIS IS AN UNOFFICIAL CONSOLE - VERSION OF A POPULAR 2048 GAME, WRITTEN IN C++.\n\n\t\t\t\t\t\t\t\tmaciey24@o2.pl\n";
	getch();
	cout<<"\n\nTHE ORIGINAL ONLINE VERSION IS AVAILABLE AT \n\n\t\t\t\t\thttp://gabrielecirulli.github.io/2048/\n";
	getch();
	system("cls");
	cout<<"JOIN THE NUMBERS AND GET TO THE 2048 TILE!\n";
	getch();
	cout<<"\nWHEN TWO TILES WITH THE SAME NUMBER TOUCH, THEY MERGE INTO ONE!\n";
	getch();
	cout<<"\nPLEASE USE w, a, s AND d, OR NUMPAD 8, 4, 5 AND 6 KEYS TO PLAY.\n";
	getch();
	cout<<"\n\nHAVE FUN!!!\n";
	getch();
	system("cls");
}

void wait()
{
     Sleep(1000);//nie dziala
}

void dwie(int plansza[4][4])
{int liczba, o, p;
for (int t=0; t<4; t++)
{
	for (int r=0; r<4; r++)
	{
		plansza[t][r]=0;
	}
}

for (int ile=2; ile>0; ile--)
{	do
	{
	o=rand()%4;
	p=rand()%4;
	}
	while (plansza[o][p]!=0);
	
	if (rand()%10<=3)
		plansza[o][p]=4;
			else plansza[o][p]=2;

}
}

void losujkloca (int plansza[4][4])
{
int ilepustych=0;
int wartosc;
int a, b;

	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
		{
			if (plansza[i][j]==0)
			ilepustych++;
		}
	}
	
if ((rand()%100)<=(ilepustych+16))
wartosc=4;
else wartosc=2;

do
{
	a=rand()%4;
	b=rand()%4;
}
while (plansza[a][b]!=0);

plansza[a][b]=wartosc;
}

int puste(int plansza[4][4])
{int ile=0;
	for (int a=0; a<4; a++)
	{
		for (int b=0; b<4; b++)
		{
			if (plansza[a][b]==0)
			ile++;
		}
	}
return ile;
}


int dasie(int plansza[4][4])
{int licz=0;
	for (int a=0; a<4; a++)
	{
		for (int b=0; b<3; b++)
		{
			if (plansza[a][b]==plansza[a][b+1])
			licz++;
		}
	}
	
	for (int c=0; c<4; c++)
	{
		for (int d=0; d<3; d++)
		{
			if (plansza[d][c]==plansza[d+1][c])
			licz++;
		}
	}
if (licz>0) return 1;
else return 0;
}

void go()
{
	cout<<"\n\n\t\t\t";
	cout<<".";
	cout<<".";
	cout<<".";
	cout<<"GAME OVER!!!";
}

void wygral()
{
	cout<<"\n\n\t\t\t";
	wait();
	cout<<".";
	wait();
	cout<<".";
	wait();
	cout<<".";
	wait();
	cout<<".";
	wait();
	cout<<".";
	wait();
	cout<<"YOU WIN!!!\n";
	getch();
}

int goal (int plansza[4][4])
{int yes=0;
	for (int a=0; a<4; a++)
	{
		for (int b=0; b<4; b++)
		{
			if (plansza[a][b]==2048)
			{
				yes=1;
			}
		}
	}
return yes; 
}

void przesun(int plansza[4][4], char *litera, int *zmiana, int *score)
{int a, b;

	if (*litera=='w'||*litera=='8')
	{
		for (a=0; a<4; a++)
		{
			for (b=0; b<4; b++)
			{
				if (plansza[a][b]!=0&&plansza[a][b-1]==0&&b>0)
				{
					plansza[a][b-1]=plansza[a][b];
					plansza[a][b]=0;
					b=b-2;
					*zmiana=1;
				}
			}
			
			for (b=0; b<4; b++)
			{
				if (plansza[a][b]!=0&&plansza[a][b]==plansza[a][b+1]&&b<3)
				{
					plansza[a][b]=plansza[a][b]*2;
					*score=*score+plansza[a][b];
					plansza[a][b+1]=0;
					*zmiana=1;
				}
			}
			
			for (b=0; b<4; b++)
			{
				if (plansza[a][b]!=0&&plansza[a][b-1]==0&&b>0)
				{
					plansza[a][b-1]=plansza[a][b];
					plansza[a][b]=0;
					b=b-2;
					*zmiana=1;
				}
			}
		}
	}	
	
	
	if (*litera=='a'||*litera=='4')
	{
		for (b=0; b<4; b++)
		{
			for (a=0; a<4; a++)
			{
				if (plansza[a][b]!=0&&plansza[a-1][b]==0&&a>0)
				{
					plansza[a-1][b]=plansza[a][b];
					plansza[a][b]=0;
					a=a-2;
					*zmiana=1;
				}
			}
			
			for (a=0; a<4; a++)
			{
				if (plansza[a][b]!=0&&plansza[a][b]==plansza[a+1][b]&&a<3)
				{
					plansza[a][b]=plansza[a][b]*2;
					*score=*score+plansza[a][b];
					plansza[a+1][b]=0;
					*zmiana=1;
				}
			}
			
			for (a=0; a<4; a++)
			{
				if (plansza[a][b]!=0&&plansza[a-1][b]==0&&a>0)
				{
					plansza[a-1][b]=plansza[a][b];
					plansza[a][b]=0;
					a=a-2;
					*zmiana=1;
				}
			}			
		}
	}

	if (*litera=='s'||*litera=='5')
	{
		for (a=0; a<4; a++)
		{
			for (b=3; b>=0; b--)
			{
				if (plansza[a][b]!=0&&plansza[a][b+1]==0&&b<3)
				{
					plansza[a][b+1]=plansza[a][b];
					plansza[a][b]=0;
					b=b+2;
					*zmiana=1;
				}
			}

			for (b=3; b>=0; b--)
			{
				if (plansza[a][b]!=0&&plansza[a][b]==plansza[a][b-1]&&b>0)
				{
					plansza[a][b]=plansza[a][b]*2;
					*score=*score+plansza[a][b];
					plansza[a][b-1]=0;
					*zmiana=1;
				}
			}
			
			for (b=3; b>=0; b--)
			{
				if (plansza[a][b]!=0&&plansza[a][b+1]==0&&b<3)
				{
					plansza[a][b+1]=plansza[a][b];
					plansza[a][b]=0;
					b=b+2;
					*zmiana=1;
				}
			}			

		}
	}	
	
	
	if (*litera=='d'||*litera=='6')
	{
		for (b=0; b<4; b++)
		{
			for (a=3; a>=0; a--)
			{
				if (plansza[a][b]!=0&&plansza[a+1][b]==0&&a<3)
				{
					plansza[a+1][b]=plansza[a][b];
					plansza[a][b]=0;
					a=a+2;
					*zmiana=1;
				}
			}
			
			for (a=3; a>=0; a--)
			{
				if (plansza[a][b]!=0&&plansza[a][b]==plansza[a-1][b]&&a>0)
				{
					plansza[a][b]=plansza[a][b]*2;
					*score=*score+plansza[a][b];
					plansza[a-1][b]=0;
					*zmiana=1;
				}
			}
			
			for (a=3; a>=0; a--)
			{
				if (plansza[a][b]!=0&&plansza[a+1][b]==0&&a<3)
				{
					plansza[a+1][b]=plansza[a][b];
					plansza[a][b]=0;
					a=a+2;
					*zmiana=1;
				}
			}
		}
	}

}




