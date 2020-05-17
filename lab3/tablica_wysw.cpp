#include<iostream>
#include "tablica.h"
#include "tablica_wysw.h"
using namespace std;

void wyswietlanie_tablicy(Tablica arr){
	
	for(int x=0; x<arr.wiersze; x++){
		for(int y=0;y<arr.kolumny;y++){
			cout<<arr.tablica[x][y]<<"\t";
		}
		cout<<endl;
	}
}
