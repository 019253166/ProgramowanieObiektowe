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
	cout<<"5. Sumuj według kolumny"<<endl;
	cout<<"6. Wartość najmniejsza w kolumnie"<<endl;
	cout<<"7. Wartość największa w kolumnie"<<endl;
	cout<<"8. Wartość średnia w kolumnie"<<endl;
	cout<<"9. Sumuj wedug wiersza"<<endl;
	cout<<"10.Wartość najmniejsza w wierszu"<<endl;
	cout<<"11. Wartość największa w wierszu"<<endl;
	cout<<"12. Wartość średnia w wierszu"<<endl;
	cout<<"13. Zapisz tablicę do pliku"<<endl;
	cout<<"14. Zamknij program"<<endl;
}


void przetworz_wybor(int wybor, Tablica &arr){
	int w_komorka=0;
	int k_komorka=0;
	int zmiana=0;
	int Nowe_wier=0;
	int Nowe_kol=0;
	switch(wybor){
		case 1: 
			cout<<"Wybrałeś wczytanie tablicy z pliku"<<endl;
			Tab_z_pliku(&arr);
		break;
		case 2:
			cout<<"Wybrałeś Zmianę rozmiaru tablicy"<<endl;
			cin>>Nowe_wier;
			cin>>Nowe_kol;
			zmien_rozmiar(&arr, Nowe_wier, Nowe_kol);
		break;
		case 3:
			cout<<"Wybrałeś zmianę zawartości tablicy"<<endl;
			cout<<"W którym wierszu i w której kolumnie znajduje się pole?"<<endl;
			cout<<"Wiersz: ";
			cin>>w_komorka;
			cout<<"Kolumna: ";
			cin>>k_komorka;
			cout<<"Co wstawić w to pole?"<<endl;
			cin>>zmiana;
			zmien_zawartosc_komorki(arr, w_komorka, k_komorka, zmiana);
		break;
		case 4:
			cout<<"Wybrałeś wyświetlenie tablicy"<<endl;
			wyswietlanie_tablicy(arr);
		break;
		case 5:
			cout<<"Wybrałeś sumowanie według kolumny"<<endl;
			Suma_K(arr);
		break;
		case 6:
			cout<<"Wybrałeś wartość najmniejszą w kolumnie"<<endl;
			Min_K(arr);
		break;
		case 7:
			cout<<"Wybrałeś wartość największą w kolumnie"<<endl;
			Max_K(arr);
		break;
		case 8:
			cout<<"Wybrałeś wartość średnią w kolumnie"<<endl;
			Srednia_K(arr);
		break;
		case 9:
			cout<<"Wybrałeś sumowanie według wiersza"<<endl;
			Suma_W(arr);
		break;
		case 10:
			cout<<"Wybrałeś wartość najmniejszą w wierszu"<<endl;
			Min_W(arr);

		break;
		case 11:
			cout<<"Wybrałeś wartość największą w wierszu"<<endl;
			Max_W(arr);
		break;
		case 12:
			cout<<"Wybrałeś wartość średnią w wierszu"<<endl;
			Srednia_W(arr);
		break;
		case 13:
			cout<<"Wybrałeś zapisanie tablicy do pliku"<<endl;
			Tab_do_pliku(arr);
		break;
		case 14:
			cout<<"Zamknąłeś program"<<endl;
		}
}

void wybierz_funkcje(int *wybor){ 
	cout<<"Co chcesz zrobić?"<<endl;
	cin>>*wybor;
	}

void petla_menu(Tablica &arr){
	int wybor = 0;
	while(wybor!=14){
	wyswietlanie_menu();
	wybierz_funkcje(&wybor);
	przetworz_wybor(wybor, arr);
	}
}
