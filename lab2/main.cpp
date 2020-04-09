#include<iostream>
#include<fstream>
#include "menu.h"
#include "tablica.h"
using namespace std;

int main(){
	cout<< "Witaj w moim programie"<<endl<<endl;
	int*tablica;
	int wiersze;
	int kolumny;

	ifstream z_pliku;
	z_pliku.open("tablica.txt");
		z_pliku>>wiersze;
		z_pliku>>kolumny;
		tablica=new int[wiersze*kolumny];
		for(int i=0;i<wiersze*kolumny;i++){
			z_pliku>>tablica[i];
		}
		
	z_pliku.close();


	petla_menu(tablica);	


	ofstream do_pliku;
	do_pliku.open("nowa_tablica.txt");

		for(int i=0; i<wiersze*kolumny; i++) {
			do_pliku<<tablica[i]<<"\t";
			if((i+1)>=kolumny){
				if((i+1)%kolumny==0){	
					do_pliku<<endl;
				}
			}
		}
	do_pliku.close();

	return 0;
}

