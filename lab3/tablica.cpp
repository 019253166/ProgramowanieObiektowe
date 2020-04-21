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
		for(int y=0;y<kolumny;y++){
			cout<<tablica[x][y]<<"\t";
		}
		cout<<endl;
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

void Suma_W(int ** tablica, int wiersze, int kolumny){
	cout<<"Wybierz wiersz do sumowania"<<endl;
	int nr_w;
	cin>>nr_w;
	int suma_w=0;
	for(int i=0;i<kolumny;i++){
	suma_w+=tablica[nr_w-1][i];
	}
	cout<<suma_w<<endl;
}

void Suma_K(int ** tablica, int wiersze, int kolumny){
	cout<<"Wybierz kolumnę do sumowania"<<endl;
	int nr_k=0;
	cin>>nr_k;
	int suma_k=0;
	for(int i=0;i<wiersze;i++){
		suma_k+=tablica[i][nr_k-1];
	}
cout<<suma_k<<endl;
}

void Min_K(int **tablica, int wiersze, int kolumny){
	cout<<"Wybierz kolumnę"<<endl;
	int nr_k=0;
	cin>>nr_k;
	int min_k=tablica[0][nr_k-1];
	for(int i=0;i<wiersze;i++){
		if(min_k>tablica[i][nr_k-1]){
			min_k=tablica[i][nr_k-1];
		}
	}
	cout<<min_k<<endl;
}

void Max_K(int **tablica, int wiersze, int kolumny){
	cout<<"Wybierz kolumnę"<<endl;
	int nr_k=0;
	cin>>nr_k;
	int max_k=tablica[0][nr_k-1];
	for(int i=0;i<wiersze;i++){
		if(max_k<tablica[i][nr_k-1]){
			max_k=tablica[i][nr_k-1];
		}
	}
	cout<<max_k<<endl;
}

void Min_W(int **tablica, int wiersze, int kolumny){
	cout<<"Wybierz wiersz"<<endl;
	int nr_w=0;
	cin>>nr_w;
	int min_w=tablica[nr_w-1][0];
	for(int i=0;i<kolumny;i++){
		if(min_w>tablica[nr_w-1][i]){
			min_w=tablica[nr_w-1][i];
		}
	}
	cout<<min_w<<endl;
}

void Max_W(int **tablica, int wiersze, int kolumny){
	cout<<"Wybierz wiersz"<<endl;
	int nr_w=0;
	cin>>nr_w;
	int max_w=tablica[nr_w-1][0];
	for(int i=0;i<kolumny;i++){
		if(max_w<tablica[nr_w-1][i]){
			max_w=tablica[nr_w-1][i];
		}
	}
	cout<<max_w<<endl;
}

void Srednia_K(int ** tablica, int wiersze, int kolumny){
	cout<<"Wybierz kolumnę"<<endl;
	int nr_k=0;
	cin>>nr_k;
	int suma_k=0;
	for(int i=0;i<wiersze;i++){
		suma_k+=tablica[i][nr_k-1];
	}
	int srednia_k=suma_k/wiersze;
	cout<<srednia_k;
}

void Srednia_W(int ** tablica, int wiersze, int kolumny){
	cout<<"Wybierz wiersz"<<endl;
	int nr_w=0;
	cin>>nr_w;
	int suma_w=0;
	for(int i=0;i<kolumny;i++){
		suma_w+=tablica[nr_w-1][i];
	}
	int srednia_w=suma_w/kolumny;
	cout<<srednia_w;
}
