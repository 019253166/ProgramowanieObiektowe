#include<iostream>
#include "tablica.h"
#include<fstream>
#include "Cell.h"
using namespace	std;

Tablica::Tablica(){
	wiersze=0;
	kolumny=0;
	jaka_kolumna=NULL;
	tablica=NULL;
}

void Tablica::zmien_rozmiar(int Nowe_wier, int Nowe_kol){
	string* tymczasowa_jaka_kolumna;
	tymczasowa_jaka_kolumna=new string[Nowe_kol];
		for(int x=0;x<Nowe_kol;x++){
			if(x<kolumny){
				tymczasowa_jaka_kolumna[x]=jaka_kolumna[x];
			}
			else{ cout<<"Podaj typ dodatkowej kolumn"<<endl;
			cin>>tymczasowa_jaka_kolumna[x];
			
			}
		}
	Cell*** tab=new Cell**[Nowe_kol];
	for(int i=0;i<Nowe_kol;i++){
		tab[i]=new Cell *[Nowe_wier];
		}
	for(int i=0;i<Nowe_kol;i++){
		for(int j=0; j<Nowe_wier;j++){
			if(tymczasowa_jaka_kolumna[i]=="int"){
				tab[i][j]=new Cell_Int;
			}
			else{
				tab[i][j]= new Cell_String;
			}
		}
	}
	

	if(wiersze>Nowe_wier || kolumny>Nowe_kol){
		for(int x=0; x<Nowe_kol; x++){
			if(tymczasowa_jaka_kolumna[x]=="int"){
				for(int y=0; y<Nowe_wier;y++){
					tab[x][y]->ustaw_wartosc(tablica[x][y]->zwroc_liczba());
				}
			}
			else{
				for(int y=0; y<Nowe_wier;y++){
					tab[x][y]->ustaw_wartosc(tablica[x][y]->zwroc_tekst());
				}
			}
		}
	}
	else{
		for(int x=0; x<kolumny; x++){
			if(tymczasowa_jaka_kolumna[x]=="int"){
				for(int y=0; y<wiersze;y++){
					tab[x][y]->ustaw_wartosc(tablica[x][y]->zwroc_liczba());
				}
			}
			else{
				for(int y=0; y<wiersze;y++){
					tab[x][y]->ustaw_wartosc(tablica[x][y]->zwroc_tekst());
				}
			}
		}
	}

	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			cout<<tab[y][x]->zwroc_tekst()<<"\t";
		}
		cout<<endl;
	}
	for(int x=0;x<kolumny;x++){
		for(int y=0;y<wiersze;y++){
			delete tablica[x][y];
		}
		delete[] tablica[x];
	}
	
	delete[] tablica;
	delete[] jaka_kolumna;

	tablica = tab;
	wiersze = Nowe_wier;
	kolumny = Nowe_kol;
	jaka_kolumna=tymczasowa_jaka_kolumna;
}

/*
void Tablica::zmien_rozmiar_tekst(int Nowe_wier, int Nowe_kol){
	
	Cell** tab=new Cell*[Nowe_wier];
	for(int i=0;i<Nowe_wier;i++){
		tab[i]=new Cell [Nowe_kol];
		}
	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			tab[x][y]->zwroc_tekst() = "0";
		}
	}
	if(wiersze>Nowe_wier || kolumny>Nowe_kol){
		for(int x=0; x<Nowe_wier; x++){
			for(int y=0; y<Nowe_kol;y++){
				tab[x][y]->zwroc_tekst() = tablica[x][y]->zwroc_tekst();
			}
		}
	}
	else{
		for(int x=0; x<wiersze; x++){
			for(int y=0; y<kolumny;y++){
				tab[x][y]->zwroc_tekst() =tablica[x][y]->zwroc_tekst();
			}
		}
	}
	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			cout<<tab[x][y]->zwroc_tekst()<<"\t";
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
*/

int Tablica::zmien_zawartosc_komorki(int w_komorka, int k_komorka, int zmiana){
	if(w_komorka>wiersze || k_komorka>kolumny){
		return -1;
	}
	tablica[k_komorka-1][w_komorka-1]->ustaw_wartosc(zmiana);
	return 0;
}

int Tablica::zmien_zawartosc_komorki_tekst(int w_komorka, int k_komorka, string zmiana){
	if(w_komorka>wiersze || k_komorka>kolumny){
		return -1;
	}
	tablica[k_komorka-1][w_komorka-1]->ustaw_wartosc(zmiana);
	return 0;
}

/*
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
				z_pliku>>tablica[x][y]->zwroc_liczba();
		}
			}
		
		z_pliku.close();
		return 0;
	}
	else{
		return -1;}
}
*/

int Tablica::Tab_z_pliku_tekst(){
	ifstream z_pliku;
	z_pliku.open("tablica.txt");
	if(z_pliku.good()==true){
		z_pliku>>wiersze;
		z_pliku>>kolumny;
		jaka_kolumna= new string [kolumny];
		for(int i=0;i<kolumny;i++){
			z_pliku>>jaka_kolumna[i];
		}
		tablica=new Cell **[kolumny];
		for(int i=0; i<kolumny;i++){
			tablica[i]=new Cell*[wiersze];
		}

		for(int i=0;i<kolumny;i++){
			for(int j=0;j<wiersze;j++){
				if(jaka_kolumna[i]=="int"){
					tablica[i][j]=new Cell_Int;
				}
				else{
					tablica[i][j]= new Cell_String;
				}
			}
		}
			
	
	
		for(int x=0; x<wiersze; x++) {
			for(int y=0; y<kolumny; y++){
				if(jaka_kolumna[y]=="int"){
					int wpisz;
					z_pliku>>wpisz;
					tablica[y][x]->ustaw_wartosc(wpisz);
				}
				else{
					string wpisz;
					z_pliku>>wpisz;
					tablica[y][x]->ustaw_wartosc(wpisz);
				}
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
		for(int x=0;x<kolumny;x++){
			do_pliku<<jaka_kolumna[x]<<" \t";
		}
		do_pliku<<endl;
			for(int x=0; x<wiersze; x++){
				for(int y=0; y<kolumny; y++){
					do_pliku<<tablica[y][x]->zwroc_tekst()<<"\t";
				}
				do_pliku<<endl;
			}
		do_pliku.close();
		return 0;
	}
	else
		return -1;
}

/*int Tablica::Tab_do_pliku_tekst(){
	ofstream do_pliku;
	if(do_pliku.good()==true){
		do_pliku.open("nowa_tablica_tekst.txt");
		do_pliku<<wiersze<<endl;
		do_pliku<<kolumny<<endl;
			for(int x=0; x<wiersze; x++) {
				for(int y=0; y<kolumny; y++){
					do_pliku<<tablica[x][y]->zwroc_tekst()<<"\t";
				}
				do_pliku<<endl;
			}
		do_pliku.close();
		return 0;
	}
	else{
		return -1;}
}*/

int Tablica::Suma_W(int nr_w){
	if(nr_w>wiersze){
		return -1;
	}
	int suma_w=0;
	for(int i=0;i<kolumny;i++){
	suma_w+=tablica[i][nr_w-1]->zwroc_liczba();
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
		suma_k+=tablica[nr_k-1][i]->zwroc_liczba();
	}
	cout<<suma_k<<endl;
	return 0;
}

int Tablica::Min_K(int nr_k){
	if(nr_k>kolumny){
		return -1;
	}
	int min_k=tablica[nr_k-1][0]->zwroc_liczba();
	for(int i=0;i<wiersze;i++){
		if(min_k>tablica[nr_k-1][i]->zwroc_liczba()){
			min_k=tablica[nr_k-1][i]->zwroc_liczba();
		}
	}
	cout<<min_k<<endl;
	return 0;
}

int Tablica::Max_K(int nr_k){
	if(nr_k>kolumny){
		return -1;
	}
	int max_k=tablica[0][nr_k-1]->zwroc_liczba();
	for(int i=0;i<wiersze;i++){
		if(max_k<tablica[i][nr_k-1]->zwroc_liczba()){
			max_k=tablica[i][nr_k-1]->zwroc_liczba();
		}
	}
	cout<<max_k<<endl;
	return 0;
}

int Tablica::Min_W(int nr_w){
	if(nr_w>wiersze){
		return -1;
	}
	int min_w=tablica[nr_w-1][0]->zwroc_liczba();
	for(int i=0;i<kolumny;i++){
		if(min_w>tablica[i][nr_w-1]->zwroc_liczba()){
			min_w=tablica[i][nr_w-1]->zwroc_liczba();
		}
	}
	cout<<min_w<<endl;
	return 0;
}

int Tablica::Max_W(int nr_w){
	if(nr_w>wiersze){
		return -1;
	}
	int max_w=tablica[nr_w-1][0]->zwroc_liczba();
	for(int i=0;i<kolumny;i++){
		if(max_w<tablica[i][nr_w-1]->zwroc_liczba()){
			max_w=tablica[i][nr_w-1]->zwroc_liczba();
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
		suma_k+=tablica[nr_k-1][i]->zwroc_liczba();
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
		suma_w+=tablica[i][nr_w-1]->zwroc_liczba();
	}
	float srednia_w=suma_w/kolumny;
	cout<<srednia_w;
	return 0;
}

void Tablica::wyswietlanie_tablicy(){
	
	for(int x=0; x<wiersze; x++){
		for(int y=0;y<kolumny;y++){
			cout<<tablica[y][x]->zwroc_tekst()<<"\t";
		}
		cout<<endl;
	}
}

void Tablica::wyswietlanie_tablicy_tekst(){
	
	for(int x=0; x<wiersze; x++){
		for(int y=0;y<kolumny;y++){
			cout<<tablica[y][x]->zwroc_tekst()<<"\t";
		}
		cout<<endl;
	}
}

Tablica::~Tablica(){
	
	for(int x=0;x<kolumny;x++){
		for(int y=0;y<wiersze;y++){
			delete tablica[x][y];
		}
		delete[] tablica[x];
	}
	
	delete[] tablica;
	delete[] jaka_kolumna;
}

void Tablica::utworz_tablice(int Nowe_wier, int Nowe_kol){
	wiersze=Nowe_wier;
	kolumny=Nowe_kol;
	jaka_kolumna=new string[kolumny];
	for(int i=0;i<kolumny;i++){
		cout<<"wybierz typ kolumny (int lub string)"<<endl;
		cin>>jaka_kolumna[i];
	}
	tablica=new Cell **[kolumny];
	for(int i=0; i<kolumny;i++){
		tablica[i]=new Cell*[wiersze];
	}

	for(int i=0;i<kolumny;i++){
		for(int j=0;j<wiersze;j++){
			if(jaka_kolumna[i]=="int"){
				tablica[i][j]=new Cell_Int;
			}
			else
				tablica[i][j]= new Cell_String;
		}
	}
	for(int x=0;x<kolumny;x++){
		cout<<jaka_kolumna[x]<<" "<<endl;
	}
}

