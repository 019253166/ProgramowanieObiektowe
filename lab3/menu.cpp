#include<iostream>
#include "menu.h"
#include "tablica.h"
#include "tablica_wysw.h"
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
	int nr_w=0;
	int nr_k=0;
	int err=0;
	switch(wybor){
		case 1: 
			cout<<"Wybrałeś wczytanie tablicy z pliku"<<endl;
			err=Tab_z_pliku(&arr);
			if(err){
				cout<<"Brak dostępu do pliku"<<endl;
			}
		break;
		case 2:
			cout<<"Wybrałeś Zmianę rozmiaru tablicy"<<endl;
			cin>>Nowe_wier;
			cin>>Nowe_kol;
			zmien_rozmiar(arr, Nowe_wier, Nowe_kol);
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
			err=zmien_zawartosc_komorki(arr, w_komorka, k_komorka, zmiana);
			if(err){
				cout<<"Wskazano niepoprawną komórkę"<<endl;
			}
		break;
		case 4:
			cout<<"Wybrałeś wyświetlenie tablicy"<<endl;
			wyswietlanie_tablicy(arr);
		break;
		case 5:
			cout<<"Wybrałeś sumowanie według kolumny"<<endl;
			cout<<"Wybierz kolumnę do sumowania"<<endl;
			cin>>nr_k;
			err=Suma_K(arr, nr_k);
			if(err){
				cout<<"Wskazano niepoprawną kolumnę"<<endl;
			}
		break;
		case 6:
			cout<<"Wybrałeś wartość najmniejszą w kolumnie"<<endl;
			cout<<"Wybierz kolumnę"<<endl;
			cin>>nr_k;
			err=Min_K(arr, nr_k);
			if(err){
				cout<<"Wskazano niepoprawną kolumnę"<<endl;
			}
		break;
		case 7:
			cout<<"Wybrałeś wartość największą w kolumnie"<<endl;
			cout<<"Wybierz kolumnę"<<endl;
			cin>>nr_k;
			err=Max_K(arr, nr_k);
			if(err){
				cout<<"Wskazano niepoprawną kolumnę"<<endl;
			}
		break;
		case 8:
			cout<<"Wybrałeś wartość średnią w kolumnie"<<endl;
			cout<<"Wybierz kolumnę"<<endl;
			cin>>nr_k;
			err=Srednia_K(arr, nr_k);
			if(err){
				cout<<"Wskazano niepoprawną kolumnę"<<endl;
			}
		break;
		case 9:
			cout<<"Wybrałeś sumowanie według wiersza"<<endl;
			cout<<"Wybierz wiersz do sumowania"<<endl;
			cin>>nr_w;
			err=Suma_W(arr, nr_w);
			if(err){
				cout<<"Wskazano niepoprawny wiersz"<<endl;
			}
		break;
		case 10:
			cout<<"Wybrałeś wartość najmniejszą w wierszu"<<endl;
			cout<<"Wybierz wiersz"<<endl;
			cin>>nr_w;
			err=Min_W(arr, nr_w);
			if(err){
				cout<<"Wskazano niepoprawny wiersz"<<endl;
			}

		break;
		case 11:
			cout<<"Wybrałeś wartość największą w wierszu"<<endl;
			cout<<"Wybierz wiersz"<<endl;
			cin>>nr_w;
			err=Max_W(arr, nr_w);
			if(err){
				cout<<"Wskazano niepoprawny wiersz"<<endl;
			}
		break;
		case 12:
			cout<<"Wybrałeś wartość średnią w wierszu"<<endl;
			cout<<"Wybierz wiersz"<<endl;
			cin>>nr_w;
			err=Srednia_W(arr, nr_w);
			if(err){
				cout<<"Wskazano niepoprawny wiersz"<<endl;
			}
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
