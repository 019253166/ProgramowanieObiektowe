#include<iostream>
#include "menu.h"
using namespace std;

void wyswietlanie_menu(){
	cout<<"Menu Główne"<<endl<<endl;
	cout<<"1. Zmień rozmiar tablicy"<<endl;
	cout<<"2. Zmień zawartość tablicy"<<endl;
	cout<<"3. Wyświetl tablicę"<<endl;
	cout<<"4. Zamknij program"<<endl;
}


void przetworz_wybor(int wybor){
	switch(wybor){
		case 1: 
			cout<<"Wybrałeś Zmianę rozmiaru tablicy"<<endl;
		break;
		case 2:
			cout<<"Wybrałeś Zmianę zawartości tablicy"<<endl;
		break;
		case 3:
			cout<<"Wybrałeś Wyświetlenie tablicy"<<endl;
		break;
		case 4:
			cout<<"Zamknąłeś program"<<endl;
			
		break;
		}
}

void wybierz_funkcje(int *wybor){ 
	cout<<"Co chcesz zrobić?"<<endl;
	cin>>*wybor;
	}

void petla_menu(int *tablica){
	int wybor = 0;
	while(wybor!=4){
	wyswietlanie_menu();
	wybierz_funkcje(&wybor);
	przetworz_wybor(wybor);
	}
}
