#include<iostream>
#include "tablica.h"
#include<fstream>
using namespace	std;

int** zmien_rozmiar(int** tablica, int & wiersze,int & kolumny, int Nowe_wier, int Nowe_kol){
	
	int** tab=new int*[Nowe_wier];
	for(int i=0;i<Nowe_wier;i++){
		tab[i]=new int [Nowe_kol];
		}
	for(int x=0;x<Nowe_wier;x++){
		for(int y=0;y<Nowe_kol;y++){
			tab[x][y]=tablica[x][y];
		}
	}
	wiersze=Nowe_wier;
	kolumny=Nowe_kol;
	return tab;
}

void zmien_zawartosc_komorki(int** tablica, int w_komorka, int k_komorka, int zmiana){
	
	tablica[w_komorka][k_komorka]=zmiana;
}

void wyswietlanie_tablicy(int** tablica, int wiersze, int kolumny){
	
	for(int x=0; x<wiersze; x++){
		for(int y=0;y<wiersze;y++){
			cout<<tablica[x][y]<<"\t";
		}
	}
}

void Tab_z_pliku(int ** &tablica, int *wiersze, int *kolumny){
	ifstream z_pliku;
	z_pliku.open("tablica.txt");
		z_pliku>>*wiersze;
		z_pliku>>*kolumny;
		tablica=new int * [*wiersze];
		for(int i=0;i<*wiersze;i++){
			tablica[i]=new int [*kolumny];
		}
		for(int x=0; x<*wiersze; x++) {
			for(int y=0; y<*kolumny; y++){
				z_pliku>>tablica[x][y];
		}
			}
		
	z_pliku.close();
}

void Tab_do_pliku(int wiersze, int kolumny, int ** tablica){
	ofstream do_pliku;
	do_pliku.open("nowa_tablica.txt");
		for(int x=0; x<wiersze; x++) {
			for(int y=0; y<kolumny; y++){
				do_pliku<<tablica[x][y]<<"\t";
			}
			do_pliku<<endl;
		}
	do_pliku.close();
}
