#include<iostream>
#include "tablica.h"
#include<fstream>
using namespace	std;

void Tablica::zmien_rozmiar(int Nowe_wier, int Nowe_kol){
	
	int** tab=new int*[Nowe_wier];
	for(int i=0;i<Nowe_wier;i++){
		tab[i]=new int [Nowe_kol];
		}
	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			tab[x][y] = 0;
		}
	}
	if(wiersze>Nowe_wier || kolumny>Nowe_kol){
		for(int x=0; x<Nowe_wier; x++){
			for(int y=0; y<Nowe_kol;y++){
				tab[x][y] = tablica[x][y];
			}
		}
	}
	else{
		for(int x=0; x<wiersze; x++){
			for(int y=0; y<kolumny;y++){
				tab[x][y] =tablica[x][y];
			}
		}
	}
	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			cout<<tab[x][y]<<"\t";
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
	tablica[w_komorka-1][k_komorka-1]=zmiana;
	return 0;
}



int Tablica::Tab_z_pliku(){
	ifstream z_pliku;
	z_pliku.open("tablica.txt");
	if(z_pliku.good()==true){
		z_pliku>>wiersze;
		z_pliku>>kolumny;
		tablica=new int * [wiersze];
		for(int i=0;i<wiersze;i++){
			tablica[i]=new int [kolumny];
		}
		for(int x=0; x<wiersze; x++) {
			for(int y=0; y<kolumny; y++){
				z_pliku>>tablica[x][y];
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
					do_pliku<<tablica[x][y]<<"\t";
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
	suma_w+=tablica[nr_w-1][i];
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
		suma_k+=tablica[i][nr_k-1];
	}
	cout<<suma_k<<endl;
	return 0;
}

int Tablica::Min_K(int nr_k){
	if(nr_k>kolumny){
		return -1;
	}
	int min_k=tablica[0][nr_k-1];
	for(int i=0;i<wiersze;i++){
		if(min_k>tablica[i][nr_k-1]){
			min_k=tablica[i][nr_k-1];
		}
	}
	cout<<min_k<<endl;
	return 0;
}

int Tablica::Max_K(int nr_k){
	if(nr_k>kolumny){
		return -1;
	}
	int max_k=tablica[0][nr_k-1];
	for(int i=0;i<wiersze;i++){
		if(max_k<tablica[i][nr_k-1]){
			max_k=tablica[i][nr_k-1];
		}
	}
	cout<<max_k<<endl;
	return 0;
}

int Tablica::Min_W(int nr_w){
	if(nr_w>wiersze){
		return -1;
	}
	int min_w=tablica[nr_w-1][0];
	for(int i=0;i<kolumny;i++){
		if(min_w>tablica[nr_w-1][i]){
			min_w=tablica[nr_w-1][i];
		}
	}
	cout<<min_w<<endl;
	return 0;
}

int Tablica::Max_W(int nr_w){
	if(nr_w>wiersze){
		return -1;
	}
	int max_w=tablica[nr_w-1][0];
	for(int i=0;i<kolumny;i++){
		if(max_w<tablica[nr_w-1][i]){
			max_w=tablica[nr_w-1][i];
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
		suma_k+=tablica[i][nr_k-1];
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
		suma_w+=tablica[nr_w-1][i];
	}
	float srednia_w=suma_w/kolumny;
	cout<<srednia_w;
	return 0;
}

void Tablica::wyswietlanie_tablicy(){
	
	for(int x=0; x<wiersze; x++){
		for(int y=0;y<kolumny;y++){
			cout<<tablica[x][y]<<"\t";
		}
		cout<<endl;
	}
}
