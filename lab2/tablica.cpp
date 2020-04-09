#include<iostream>
#include "tablica.h"
#include<fstream>
using namespace	std;

int* zmien_rozmiar(int* tablica, int& rozmiar, int NowyRozmiar){
	
	int* tab=new int[NowyRozmiar];
	for(int i=0;i<NowyRozmiar;i++){
		tab[i]=tablica[i];
		}
	rozmiar=NowyRozmiar;
	return tab;
}

void zmien_zawartosc_komorki(int* tablica, int komorka, int zmiana){
	
	tablica[komorka]=zmiana;
}

void wyswietlanie_tablicy(int* tablica, int rozmiar){
	
	for(int i=0; i<rozmiar; i++){
		cout<<tablica[i]<<" ";
	}
}


