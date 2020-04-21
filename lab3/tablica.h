#ifndef TABLICA_H
#define TABLICA_H


/** Funkcja zmieniająca rozmiar tablicu
* @param tablica tablica której rozmiar zmieniamy
* @param rozmiar aktualny rozmiar tablicy
* @param NowyRozmiar nowy rozmiar tablicy
* @return tablica o nowym rozmiarze
*/
int** zmien_rozmiar(int** tablica, int & wiersze,int & kolumny, int Nowe_wier, int Nowe_kol);
/** Funkcja zmieniająca zawartość wybranej komórki
* @param tablica aktualizowana tablica
* @param komorka aktualizowana komorka tablicy
* @param zmiana nowa wartosc wpisywana do komorki
*/
void zmien_zawartosc_komorki(int** tablica, int w_komorka, int k_komorka, int zmiana);

/** Funkcja wyswietlajaca tablice
* @param tablica wyswietlana tablica
* @param rozmiar rozmiar wyswietlanej tablicy
*/
void wyswietlanie_tablicy(int** tablica, int wiersze, int kolumny);

void Tab_z_pliku(int ** &tablica, int *wiersze, int *kolumny);

void Tab_do_pliku(int wiersze, int kolumny, int ** tablica);

#endif
