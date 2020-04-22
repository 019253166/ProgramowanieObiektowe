#include<iostream>
#include "tablica.h"
#include<fstream>
using namespace	std;

int** zmien_rozmiar(Tablica* arr, int Nowe_wier, int Nowe_kol){
	
	int** tab=new int*[Nowe_wier];
	for(int i=0;i<Nowe_wier;i++){
		tab[i]=new int [Nowe_kol];
		}
	for(int x=0;x<Nowe_wier;x++){
		for(int y=0;y<Nowe_kol;y++){
			tab[x][y]=arr->tablica[x][y];
		}
	}
	for(int i=0;i<arr->kolumny;i++){
		delete [] arr->tablica[i];
	}
	delete [] arr->tablica;	
	arr->tablica=tab;
	arr->wiersze=Nowe_wier;
	arr->kolumny=Nowe_kol;
	return tab;
}

void zmien_zawartosc_komorki(Tablica arr, int w_komorka, int k_komorka, int zmiana){
	
	arr.tablica[w_komorka-1][k_komorka-1]=zmiana;
}

void wyswietlanie_tablicy(Tablica arr){
	
	for(int x=0; x<arr.wiersze; x++){
		for(int y=0;y<arr.kolumny;y++){
			cout<<arr.tablica[x][y]<<"\t";
		}
		cout<<endl;
	}
}

void Tab_z_pliku(Tablica* arr){
	ifstream z_pliku;
	z_pliku.open("tablica.txt");
		z_pliku>>arr->wiersze;
		z_pliku>>arr->kolumny;
		arr->tablica=new int * [arr->wiersze];
		for(int i=0;i<arr->wiersze;i++){
			arr->tablica[i]=new int [arr->kolumny];
		}
		for(int x=0; x<arr->wiersze; x++) {
			for(int y=0; y<arr->kolumny; y++){
				z_pliku>>arr->tablica[x][y];
		}
			}
		
	z_pliku.close();
}

void Tab_do_pliku(Tablica arr){
	ofstream do_pliku;
	do_pliku.open("nowa_tablica.txt");
	do_pliku<<arr.wiersze<<endl;
	do_pliku<<arr.kolumny<<endl;
		for(int x=0; x<arr.wiersze; x++) {
			for(int y=0; y<arr.kolumny; y++){
				do_pliku<<arr.tablica[x][y]<<"\t";
			}
			do_pliku<<endl;
		}
	do_pliku.close();
}

void Suma_W(Tablica arr){
	cout<<"Wybierz wiersz do sumowania"<<endl;
	int nr_w;
	cin>>nr_w;
	int suma_w=0;
	for(int i=0;i<arr.kolumny;i++){
	suma_w+=arr.tablica[nr_w-1][i];
	}
	cout<<"Suma w wierszu nr "<<nr_w<<" wynosi "<<suma_w<<endl;
}

void Suma_K(Tablica arr){
	cout<<"Wybierz kolumnę do sumowania"<<endl;
	int nr_k=0;
	cin>>nr_k;
	int suma_k=0;
	for(int i=0;i<arr.wiersze;i++){
		suma_k+=arr.tablica[i][nr_k-1];
	}
cout<<suma_k<<endl;
}

void Min_K(Tablica arr){
	cout<<"Wybierz kolumnę"<<endl;
	int nr_k=0;
	cin>>nr_k;
	int min_k=arr.tablica[0][nr_k-1];
	for(int i=0;i<arr.wiersze;i++){
		if(min_k>arr.tablica[i][nr_k-1]){
			min_k=arr.tablica[i][nr_k-1];
		}
	}
	cout<<min_k<<endl;
}

void Max_K(Tablica arr){
	cout<<"Wybierz kolumnę"<<endl;
	int nr_k=0;
	cin>>nr_k;
	int max_k=arr.tablica[0][nr_k-1];
	for(int i=0;i<arr.wiersze;i++){
		if(max_k<arr.tablica[i][nr_k-1]){
			max_k=arr.tablica[i][nr_k-1];
		}
	}
	cout<<max_k<<endl;
}

void Min_W(Tablica arr){
	cout<<"Wybierz wiersz"<<endl;
	int nr_w=0;
	cin>>nr_w;
	int min_w=arr.tablica[nr_w-1][0];
	for(int i=0;i<arr.kolumny;i++){
		if(min_w>arr.tablica[nr_w-1][i]){
			min_w=arr.tablica[nr_w-1][i];
		}
	}
	cout<<min_w<<endl;
}

void Max_W(Tablica arr){
	cout<<"Wybierz wiersz"<<endl;
	int nr_w=0;
	cin>>nr_w;
	int max_w=arr.tablica[nr_w-1][0];
	for(int i=0;i<arr.kolumny;i++){
		if(max_w<arr.tablica[nr_w-1][i]){
			max_w=arr.tablica[nr_w-1][i];
		}
	}
	cout<<max_w<<endl;
}

void Srednia_K(Tablica arr){
	cout<<"Wybierz kolumnę"<<endl;
	int nr_k=0;
	cin>>nr_k;
	int suma_k=0;
	for(int i=0;i<arr.wiersze;i++){
		suma_k+=arr.tablica[i][nr_k-1];
	}
	int srednia_k=suma_k/arr.wiersze;
	cout<<srednia_k;
}

void Srednia_W(Tablica arr){
	cout<<"Wybierz wiersz"<<endl;
	int nr_w=0;
	cin>>nr_w;
	int suma_w=0;
	for(int i=0;i<arr.kolumny;i++){
		suma_w+=arr.tablica[nr_w-1][i];
	}
	int srednia_w=suma_w/arr.kolumny;
	cout<<srednia_w;
}
