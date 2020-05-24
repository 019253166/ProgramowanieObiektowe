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
	cout<<"14. Wczytaj tablicę tekstową"<<endl;
	cout<<"15. Wyświetl tablicę tekstową"<<endl;
	cout<<"16. Zmień rozmiar tablicy tekstowej"<<endl;
	cout<<"17. Zmień zawartość tablicy tekstowej"<<endl;
	cout<<"18. Zapisz tablicę tekstową do pliku"<<endl;
	cout<<"19. Zamknij program"<<endl;
}


void przetworz_wybor(int wybor, Tablica *arr){
	int w_komorka=0;
	int k_komorka=0;
	int zmiana=0;
	string zmiana_tekst="0";
	int Nowe_wier=0;
	int Nowe_kol=0;
	int nr_w=0;
	int nr_k=0;
	int err=0;
	switch(wybor){
		case 1: 
			cout<<"Wybrałeś wczytanie tablicy z pliku"<<endl;
			err=arr->Tab_z_pliku();
			if(err){
				cout<<"Brak dostępu do pliku"<<endl;
			}
		break;
		case 14: 
			cout<<"Wybrałeś wczytanie tablicy tekstowej z pliku"<<endl;
			err=arr->Tab_z_pliku_tekst();
			if(err){
				cout<<"Brak dostępu do pliku"<<endl;
			}
		break;
		case 2:
			cout<<"Wybrałeś Zmianę rozmiaru tablicy"<<endl;
			cin>>Nowe_wier;
			cin>>Nowe_kol;
			arr->zmien_rozmiar(Nowe_wier, Nowe_kol);
		break;
		case 16:
			cout<<"Wybrałeś Zmianę rozmiaru tablicy tekstowej"<<endl;
			cin>>Nowe_wier;
			cin>>Nowe_kol;
			arr->zmien_rozmiar_tekst(Nowe_wier, Nowe_kol);
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
			err=arr->zmien_zawartosc_komorki(w_komorka, k_komorka, zmiana);
			if(err){
				cout<<"Wskazano niepoprawną komórkę"<<endl;
			}
		break;
		case 17:
			cout<<"Wybrałeś zmianę zawartości tablicy tekstowej"<<endl;
			cout<<"W którym wierszu i w której kolumnie znajduje się pole?"<<endl;
			cout<<"Wiersz: ";
			cin>>w_komorka;
			cout<<"Kolumna: ";
			cin>>k_komorka;
			cout<<"Co wstawić w to pole?"<<endl;
			cin>>zmiana_tekst;
			err=arr->zmien_zawartosc_komorki_tekst(w_komorka, k_komorka, zmiana_tekst);
			if(err){
				cout<<"Wskazano niepoprawną komórkę"<<endl;
			}
		break;
		case 4:
			cout<<"Wybrałeś wyświetlenie tablicy"<<endl;
			arr->wyswietlanie_tablicy();
		break;
		case 15:
			cout<<"Wybrałeś wyświetlenie tablicy tekstowej"<<endl;
			arr->wyswietlanie_tablicy_tekst();
		break;
		case 5:
			cout<<"Wybrałeś sumowanie według kolumny"<<endl;
			cout<<"Wybierz kolumnę do sumowania"<<endl;
			cin>>nr_k;
			err=arr->Suma_K(nr_k);
			if(err){
				cout<<"Wskazano niepoprawną kolumnę"<<endl;
			}
		break;
		case 6:
			cout<<"Wybrałeś wartość najmniejszą w kolumnie"<<endl;
			cout<<"Wybierz kolumnę"<<endl;
			cin>>nr_k;
			err=arr->Min_K( nr_k);
			if(err){
				cout<<"Wskazano niepoprawną kolumnę"<<endl;
			}
		break;
		case 7:
			cout<<"Wybrałeś wartość największą w kolumnie"<<endl;
			cout<<"Wybierz kolumnę"<<endl;
			cin>>nr_k;
			err=arr->Max_K(nr_k);
			if(err){
				cout<<"Wskazano niepoprawną kolumnę"<<endl;
			}
		break;
		case 8:
			cout<<"Wybrałeś wartość średnią w kolumnie"<<endl;
			cout<<"Wybierz kolumnę"<<endl;
			cin>>nr_k;
			err=arr->Srednia_K(nr_k);
			if(err){
				cout<<"Wskazano niepoprawną kolumnę"<<endl;
			}
		break;
		case 9:
			cout<<"Wybrałeś sumowanie według wiersza"<<endl;
			cout<<"Wybierz wiersz do sumowania"<<endl;
			cin>>nr_w;
			err=arr->Suma_W( nr_w);
			if(err){
				cout<<"Wskazano niepoprawny wiersz"<<endl;
			}
		break;
		case 10:
			cout<<"Wybrałeś wartość najmniejszą w wierszu"<<endl;
			cout<<"Wybierz wiersz"<<endl;
			cin>>nr_w;
			err=arr->Min_W(nr_w);
			if(err){
				cout<<"Wskazano niepoprawny wiersz"<<endl;
			}

		break;
		case 11:
			cout<<"Wybrałeś wartość największą w wierszu"<<endl;
			cout<<"Wybierz wiersz"<<endl;
			cin>>nr_w;
			err=arr->Max_W(nr_w);
			if(err){
				cout<<"Wskazano niepoprawny wiersz"<<endl;
			}
		break;
		case 12:
			cout<<"Wybrałeś wartość średnią w wierszu"<<endl;
			cout<<"Wybierz wiersz"<<endl;
			cin>>nr_w;
			err=arr->Srednia_W(nr_w);
			if(err){
				cout<<"Wskazano niepoprawny wiersz"<<endl;
			}
		break;
		case 13:
			cout<<"Wybrałeś zapisanie tablicy do pliku"<<endl;
			arr->Tab_do_pliku();
		break;
		case 18:
			cout<<"Wybrałeś zapisanie tekstowej tablicy do pliku"<<endl;
			arr->Tab_do_pliku_tekst();
		break;
		case 19:
			cout<<"Zamknąłeś program"<<endl;
		}
}

void wybierz_funkcje(int *wybor){ 
	cout<<"Co chcesz zrobić?"<<endl;
	cin>>*wybor;
	}

void petla_menu(Tablica *arr){
	int wybor = 0;
	while(wybor!=19){
	wyswietlanie_menu();
	wybierz_funkcje(&wybor);
	przetworz_wybor(wybor, arr);
	}
}
