#include<iostream>
#include "menu.h"
#include "tablica.h"
using namespace std;


void wyswietlanie_menu(){
	cout<<"Menu Główne"<<endl<<endl;
	cout<<"1. Wczytaj tablicę z pliku"<<endl;
	cout<<"2. Zmień rozmiar tablicy"<<endl;
	cout<<"3. Zmień zawartość tablicy"<<endl;
	cout<<"4. Wyświetl tablicę"<<endl;
	cout<<"5. Zapisz tablicę do pliku"<<endl;
	cout<<"6. Zamknij program"<<endl;
}


void przetworz_wybor(int wybor){
	switch(wybor){
		case 1: 
			cout<<"Wybrałeś wczytanie tablicy z pliku"<<endl;
		break;
		case 2:
			cout<<"Wybrałeś Zmianę rozmiaru tablicy"<<endl;
		break;
		case 3:
			cout<<"Wybrałeś zmianę zawartości tablicy"<<endl;
		break;
		case 4:
			cout<<"Wybrałeś wyświetlenie tablicy"<<endl;
		break;
		case 5:
			cout<<"Wybrałeś zapisanie tablicy do pliku"<<endl;
			
		break;
		case 6:
			cout<<"Zamknąłeś program"<<endl;
		}
}

void wybierz_funkcje(int *wybor){ 
	cout<<"Co chcesz zrobić?"<<endl;
	cin>>*wybor;
	}

void petla_menu(int **tablica){
	int wybor = 0;
	while(wybor!=6){
	wyswietlanie_menu();
	wybierz_funkcje(&wybor);
	przetworz_wybor(wybor);
	}
}
