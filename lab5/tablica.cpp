#include<iostream>
#include "tablica.h"
#include<fstream>
#include "Cell.h"
using namespace	std;

Tablica::Tablica(){
	wiersze=0;
	kolumny=0;
	tablica=NULL;
}
void Tablica::zmien_rozmiar(int Nowe_wier, int Nowe_kol){
	
	Cell** tab=new Cell*[Nowe_wier];
	for(int i=0;i<Nowe_wier;i++){
		tab[i]=new Cell [Nowe_kol];
		}
	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			tab[x][y].liczba = 0;
		}
	}
	if(wiersze>Nowe_wier || kolumny>Nowe_kol){
		for(int x=0; x<Nowe_wier; x++){
			for(int y=0; y<Nowe_kol;y++){
				tab[x][y].liczba = tablica[x][y].liczba;
			}
		}
	}
	else{
		for(int x=0; x<wiersze; x++){
			for(int y=0; y<kolumny;y++){
				tab[x][y].liczba =tablica[x][y].liczba;
			}
		}
	}
	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			cout<<tab[x][y].liczba<<"\t";
		}
		cout<<endl;
	}
	for(int x=0;x<kolumny;x++){
		delete[] tablica[x];
	}
	
	delete[] tablica;

	tablica = tab;
	wiersze = Nowe_wier;
	kolumny = Nowe_kol;

	
	
	
}

void Tablica::zmien_rozmiar_tekst(int Nowe_wier, int Nowe_kol){
	
	Cell** tab=new Cell*[Nowe_wier];
	for(int i=0;i<Nowe_wier;i++){
		tab[i]=new Cell [Nowe_kol];
		}
	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			tab[x][y].tekst = "0";
		}
	}
	if(wiersze>Nowe_wier || kolumny>Nowe_kol){
		for(int x=0; x<Nowe_wier; x++){
			for(int y=0; y<Nowe_kol;y++){
				tab[x][y].tekst = tablica[x][y].tekst;
			}
		}
	}
	else{
		for(int x=0; x<wiersze; x++){
			for(int y=0; y<kolumny;y++){
				tab[x][y].tekst =tablica[x][y].tekst;
			}
		}
	}
	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			cout<<tab[x][y].tekst<<"\t";
		}
		cout<<endl;
	}
	for(int x=0;x<kolumny;x++){
		delete[] tablica[x];
	}
	
	delete[] tablica;

	tablica = tab;
	wiersze = Nowe_wier;
	kolumny = Nowe_kol;

	
	
	
}


int Tablica::zmien_zawartosc_komorki(int w_komorka, int k_komorka, int zmiana){
	if(w_komorka>wiersze || k_komorka>kolumny){
		return -1;
	}
	tablica[w_komorka-1][k_komorka-1].liczba=zmiana;
	return 0;
}

int Tablica::zmien_zawartosc_komorki_tekst(int w_komorka, int k_komorka, string zmiana){
	if(w_komorka>wiersze || k_komorka>kolumny){
		return -1;
	}
	tablica[w_komorka-1][k_komorka-1].tekst=zmiana;
	return 0;
}


int Tablica::Tab_z_pliku(){
	ifstream z_pliku;
	z_pliku.open("tablica.txt");
	if(z_pliku.good()==true){
		z_pliku>>wiersze;
		z_pliku>>kolumny;
		tablica=new Cell * [wiersze];
		for(int i=0;i<wiersze;i++){
			tablica[i]=new Cell [kolumny];
		}
		for(int x=0; x<wiersze; x++) {
			for(int y=0; y<kolumny; y++){
				z_pliku>>tablica[x][y].liczba;
		}
			}
		
		z_pliku.close();
		return 0;
	}
	else{
		return -1;}
}

int Tablica::Tab_z_pliku_tekst(){
	ifstream z_pliku;
	z_pliku.open("tablica_tekst.txt");
	if(z_pliku.good()==true){
		z_pliku>>wiersze;
		z_pliku>>kolumny;
		tablica=new Cell * [wiersze];
		for(int i=0;i<wiersze;i++){
			tablica[i]=new Cell [kolumny];
		}
		for(int x=0; x<wiersze; x++) {
			for(int y=0; y<kolumny; y++){
				z_pliku>>tablica[x][y].tekst;
		}
			}
		
		z_pliku.close();
		return 0;
	}
	else{
		return -1;}
}

int Tablica::Tab_do_pliku(){
	ofstream do_pliku;
	if(do_pliku.good()==true){
		do_pliku.open("nowa_tablica.txt");
		do_pliku<<wiersze<<endl;
		do_pliku<<kolumny<<endl;
			for(int x=0; x<wiersze; x++) {
				for(int y=0; y<kolumny; y++){
					do_pliku<<tablica[x][y].liczba<<"\t";
				}
				do_pliku<<endl;
			}
		do_pliku.close();
		return 0;
	}
	else{
		return -1;}
}

int Tablica::Tab_do_pliku_tekst(){
	ofstream do_pliku;
	if(do_pliku.good()==true){
		do_pliku.open("nowa_tablica_tekst.txt");
		do_pliku<<wiersze<<endl;
		do_pliku<<kolumny<<endl;
			for(int x=0; x<wiersze; x++) {
				for(int y=0; y<kolumny; y++){
					do_pliku<<tablica[x][y].tekst<<"\t";
				}
				do_pliku<<endl;
			}
		do_pliku.close();
		return 0;
	}
	else{
		return -1;}
}

int Tablica::Suma_W(int nr_w){
	if(nr_w>wiersze){
		return -1;
	}
	int suma_w=0;
	for(int i=0;i<kolumny;i++){
	suma_w+=tablica[nr_w-1][i].liczba;
	}
	cout<<"Suma w wierszu nr "<<nr_w<<" wynosi "<<suma_w<<endl;
	return 0;
}

int Tablica::Suma_K(int nr_k){
	if(nr_k>kolumny){
		return -1;
	}
	int suma_k=0;
	for(int i=0;i<wiersze;i++){
		suma_k+=tablica[i][nr_k-1].liczba;
	}
	cout<<suma_k<<endl;
	return 0;
}

int Tablica::Min_K(int nr_k){
	if(nr_k>kolumny){
		return -1;
	}
	int min_k=tablica[0][nr_k-1].liczba;
	for(int i=0;i<wiersze;i++){
		if(min_k>tablica[i][nr_k-1].liczba){
			min_k=tablica[i][nr_k-1].liczba;
		}
	}
	cout<<min_k<<endl;
	return 0;
}

int Tablica::Max_K(int nr_k){
	if(nr_k>kolumny){
		return -1;
	}
	int max_k=tablica[0][nr_k-1].liczba;
	for(int i=0;i<wiersze;i++){
		if(max_k<tablica[i][nr_k-1].liczba){
			max_k=tablica[i][nr_k-1].liczba;
		}
	}
	cout<<max_k<<endl;
	return 0;
}

int Tablica::Min_W(int nr_w){
	if(nr_w>wiersze){
		return -1;
	}
	int min_w=tablica[nr_w-1][0].liczba;
	for(int i=0;i<kolumny;i++){
		if(min_w>tablica[nr_w-1][i].liczba){
			min_w=tablica[nr_w-1][i].liczba;
		}
	}
	cout<<min_w<<endl;
	return 0;
}

int Tablica::Max_W(int nr_w){
	if(nr_w>wiersze){
		return -1;
	}
	int max_w=tablica[nr_w-1][0].liczba;
	for(int i=0;i<kolumny;i++){
		if(max_w<tablica[nr_w-1][i].liczba){
			max_w=tablica[nr_w-1][i].liczba;
		}
	}
	cout<<max_w<<endl;
	return 0;
}

int Tablica::Srednia_K(int nr_k){
	if(nr_k>kolumny){
		return -1;
	}
	float suma_k=0;
	for(int i=0;i<wiersze;i++){
		suma_k+=tablica[i][nr_k-1].liczba;
	}
	float srednia_k=suma_k/wiersze;
	cout<<srednia_k;
	return 0;
}

int Tablica::Srednia_W(int nr_w){
	if(nr_w>wiersze){
		return -1;
	}
	float suma_w=0;
	for(int i=0;i<kolumny;i++){
		suma_w+=tablica[nr_w-1][i].liczba;
	}
	float srednia_w=suma_w/kolumny;
	cout<<srednia_w;
	return 0;
}

void Tablica::wyswietlanie_tablicy(){
	
	for(int x=0; x<wiersze; x++){
		for(int y=0;y<kolumny;y++){
			cout<<tablica[x][y].liczba<<"\t";
		}
		cout<<endl;
	}
}

void Tablica::wyswietlanie_tablicy_tekst(){
	
	for(int x=0; x<wiersze; x++){
		for(int y=0;y<kolumny;y++){
			cout<<tablica[x][y].tekst<<"\t";
		}
		cout<<endl;
	}
}

Tablica::~Tablica(){
	cout<<tablica[1][1].liczba;
	for(int x=0;x<kolumny;x++){
		delete[] tablica[x];
	}
	
	delete[] tablica;
	cout<<tablica[1][1].liczba;
}
