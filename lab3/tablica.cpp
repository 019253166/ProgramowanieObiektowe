#include<iostream>
#include "tablica.h"
#include<fstream>
using namespace	std;

void zmien_rozmiar(Tablica & arr, int Nowe_wier, int Nowe_kol){
	
	int** tab=new int*[Nowe_wier];
	for(int i=0;i<Nowe_wier;i++){
		tab[i]=new int [Nowe_kol];
		}
	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			tab[x][y] = 0;
		}
	}
	if(arr.wiersze>Nowe_wier || arr.kolumny>Nowe_kol){
		for(int x=0; x<Nowe_wier; x++){
			for(int y=0; y<Nowe_kol;y++){
				tab[x][y] = arr.tablica[x][y];
			}
		}
	}
	else{
		for(int x=0; x<arr.wiersze; x++){
			for(int y=0; y<arr.kolumny;y++){
				tab[x][y] = arr.tablica[x][y];
			}
		}
	}
	for(int x=0; x<Nowe_wier;x++){
		for(int y=0; y<Nowe_kol;y++){
			cout<<tab[x][y]<<"\t";
		}
		cout<<endl;
	}
	for(int x=0;x<arr.kolumny;x++){
		delete[] arr.tablica[x];
	}
	
	delete[] arr.tablica;

	arr.tablica = tab;
	arr.wiersze = Nowe_wier;
	arr.kolumny = Nowe_kol;

	
	
	
}



int zmien_zawartosc_komorki(Tablica arr, int w_komorka, int k_komorka, int zmiana){
	if(w_komorka>arr.wiersze || k_komorka>arr.kolumny){
		return -1;
	}
	arr.tablica[w_komorka-1][k_komorka-1]=zmiana;
	return 0;
}



int Tab_z_pliku(Tablica* arr){
	ifstream z_pliku;
	z_pliku.open("tablica.txt");
	if(z_pliku.good()==true){
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
		return 0;
	}
	else{
		return -1;}
}

int Tab_do_pliku(Tablica arr){
	ofstream do_pliku;
	if(do_pliku.good()==true){
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
		return 0;
	}
	else{
		return -1;}
}

int Suma_W(Tablica arr, int nr_w){
	if(nr_w>arr.wiersze){
		return -1;
	}
	int suma_w=0;
	for(int i=0;i<arr.kolumny;i++){
	suma_w+=arr.tablica[nr_w-1][i];
	}
	cout<<"Suma w wierszu nr "<<nr_w<<" wynosi "<<suma_w<<endl;
	return 0;
}

int Suma_K(Tablica arr, int nr_k){
	if(nr_k>arr.kolumny){
		return -1;
	}
	int suma_k=0;
	for(int i=0;i<arr.wiersze;i++){
		suma_k+=arr.tablica[i][nr_k-1];
	}
	cout<<suma_k<<endl;
	return 0;
}

int Min_K(Tablica arr, int nr_k){
	if(nr_k>arr.kolumny){
		return -1;
	}
	int min_k=arr.tablica[0][nr_k-1];
	for(int i=0;i<arr.wiersze;i++){
		if(min_k>arr.tablica[i][nr_k-1]){
			min_k=arr.tablica[i][nr_k-1];
		}
	}
	cout<<min_k<<endl;
	return 0;
}

int Max_K(Tablica arr, int nr_k){
	if(nr_k>arr.kolumny){
		return -1;
	}
	int max_k=arr.tablica[0][nr_k-1];
	for(int i=0;i<arr.wiersze;i++){
		if(max_k<arr.tablica[i][nr_k-1]){
			max_k=arr.tablica[i][nr_k-1];
		}
	}
	cout<<max_k<<endl;
	return 0;
}

int Min_W(Tablica arr, int nr_w){
	if(nr_w>arr.wiersze){
		return -1;
	}
	int min_w=arr.tablica[nr_w-1][0];
	for(int i=0;i<arr.kolumny;i++){
		if(min_w>arr.tablica[nr_w-1][i]){
			min_w=arr.tablica[nr_w-1][i];
		}
	}
	cout<<min_w<<endl;
	return 0;
}

int Max_W(Tablica arr, int nr_w){
	if(nr_w>arr.wiersze){
		return -1;
	}
	int max_w=arr.tablica[nr_w-1][0];
	for(int i=0;i<arr.kolumny;i++){
		if(max_w<arr.tablica[nr_w-1][i]){
			max_w=arr.tablica[nr_w-1][i];
		}
	}
	cout<<max_w<<endl;
	return 0;
}

int Srednia_K(Tablica arr, int nr_k){
	if(nr_k>arr.kolumny){
		return -1;
	}
	float suma_k=0;
	for(int i=0;i<arr.wiersze;i++){
		suma_k+=arr.tablica[i][nr_k-1];
	}
	float srednia_k=suma_k/arr.wiersze;
	cout<<srednia_k;
	return 0;
}

int Srednia_W(Tablica arr, int nr_w){
	if(nr_w>arr.wiersze){
		return -1;
	}
	float suma_w=0;
	for(int i=0;i<arr.kolumny;i++){
		suma_w+=arr.tablica[nr_w-1][i];
	}
	float srednia_w=suma_w/arr.kolumny;
	cout<<srednia_w;
	return 0;
}
