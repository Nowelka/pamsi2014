#include "Tablica.h"
#include <iostream>
#include <random>

using namespace std;


Tablica::Tablica(void)
{
}


Tablica::~Tablica(void)
{
}


void Tablica::setRozmiar(int rozmiar1)
{
	rozmiar = rozmiar1;
}


int Tablica::getRozmiar(void)
{
	return rozmiar;
}


void Tablica::setRozklad(int rozklad1)
{
	rozklad = rozklad1;
}


int Tablica::getRozklad(void)
{
	return rozklad;
}


void Tablica::setUporzadkowanie(int uporzadkowanie1)
{
	uporzadkowanie = uporzadkowanie1;
}


int Tablica::getUporzadkowanie(void)
{
	return uporzadkowanie;
}

void Tablica::wyswietlanieTablicy(void)
{
	for(int i = 0; i < rozmiar; i++)
		cout << tablica[i] << " ";
	cout << endl;
}


void Tablica::uzupelnianeTablicy(void)
{
	for(int i = 0; i < rozmiar; i++) tablica[i] = 0;
	int eksperymenty = 10000;
	int liczba = 100;
	default_random_engine generator;
	//rozklad jednostajny
	if(rozklad == 0) {
		uniform_int_distribution < int> dystrybucja(0,9);
		for(int i = 0; i < eksperymenty; i++) {
			int numer = dystrybucja(generator);
			++tablica[numer];
		}
		for(int i = 0; i < rozmiar; i++) 
			tablica[i] = tablica[i] * liczba / eksperymenty;
	}
	//rozkald normalny
	else if(rozklad == 1) {
		normal_distribution <double> dystrubucja(5.0,2.0);
		for(int i = 0; i < eksperymenty; i++) {
			int numer = dystrubucja(generator);
			if((numer >= 0.0) && (numer < rozmiar))
				++tablica[(int)numer];
		}
		for(int i = 0; i < rozmiar; i++)
			tablica[i] = tablica[i] * liczba / eksperymenty;
	}
	//rozklad poissona
	else if(rozklad == 2) {
		
		poisson_distribution<int> dystrybucja(4.1);

	
		for(int i = 0; i < eksperymenty; i++) {
			int numer = dystrybucja(generator);
			if(numer < rozmiar)
				++tablica[numer];
		}
		for(int i = 0; i < rozmiar; i++) 
			tablica[i] = tablica[i] * liczba / eksperymenty;
	}
}


void Tablica::wstepneSortowanie(void) 
{
	float procent = 0;
	if(uporzadkowanie == 0) procent = 0;
	else if(uporzadkowanie == 1) procent = 0.1;
	else if(uporzadkowanie == 2) procent = 0.5;
	else if(uporzadkowanie == 3) procent = 0.9;

	for(int i = 0; i < (int)rozmiar * procent; i++) {

	}
}