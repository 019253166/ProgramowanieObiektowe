#ifndef TABLICA_H
#define TABLICA_H
#include<iostream>
#include<fstream>
#include "Cell.h"
using namespace std;
/** Klasa przechowująca tablicę dwuwymiarową, ilość wierszy i ilość kolumn oraz funkcje operujące na tablicy
*/
class Tablica{
public:

Tablica();
/** Funkcja zmieniająca rozmiar tablicy
* @param[in,out]Tablica & arr - obiekt tablica której rozmiar zmieniamy 
* @param[in] Nowe_wier - nowa liczba wierszy
* @param[in] Nowe_kol - nowa liczba kolumn
*/
void zmien_rozmiar(int Nowe_wier, int Nowe_kol);

/** Funkcja zmieniająca zawartość wybranej komórki
* @param[in,out]Tablica arr - aktualizowana tablica
* @param[in] w_komorka - nr wiersza aktualizowanej komorki
* @oaram[in] k_komorka - nr kolumny aktualizowanej komorki
* @param[in] zmiana - nowa wartosc wpisywana do komorki
* @return - 0 w przypadku powodzenia lub -1 w przypadku nieistniejącego wiersza lub kolumny
*/
int zmien_zawartosc_komorki(int w_komorka, int k_komorka, int zmiana);


/** Funkcja wczytująca dane z pliku
* @return 0 w przypadku powodzenia lub -1 w przypadku błędu w otworzeniu pliku
*/
int Tab_z_pliku();

/** Funkcja zapisująca zawartość tablicy do pliku
* @return - 0 w przypadku powodzenia lub -1 w przypadku błędy w otworzeniu pliku
*/
int Tab_do_pliku();

/** Poniższe funkcje wykonują obliczenia na wierszach i kolumnach
* @param[in] nr_w - numer wiersza
* @param[in] nr_k - numer kolumny
* @return - 0 w przypadku powodzenia lub -1 w przypadku podania nieistniejącego wiersza lub kolumny
*/
int Suma_W(int nr_w);

int Suma_K(int nr_k);

int Min_K(int nr_k);

int Max_K(int nr_k);

int Min_W(int nr_w);

int Max_W(int nr_w);

int Srednia_K(int nr_k);

int Srednia_W(int nr_w);

/** Funkcja wyświetlająca tablicę
*/
void wyswietlanie_tablicy();


int zmien_zawartosc_komorki_tekst(int w_komorka, int k_komorka, string zmiana);

int Tab_z_pliku_tekst();

int Tab_do_pliku_tekst();

void wyswietlanie_tablicy_tekst();

/** Metoda tworząca nową tablicę o zadanych rozmiarach
@param[in] Nowe_wier - liczba wierszy
@param[in] Nowe_kol - liczba kolumn
*/
void utworz_tablice(int Nowe_wier, int Nowe_kol);

/* destruktor klasy usuwający z pamięci obiekty utworzone dynamicznie */
~Tablica();
private:
	
	Cell ***tablica;
	string* jaka_kolumna;
	int wiersze;
	int kolumny;
};


#endif
