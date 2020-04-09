#ifndef TABLICA_H
#define TABLICA_H

/** Funkcja zmieniająca rozmiar tablicu
* @param tablica tablica której rozmiar zmieniamy
* @param rozmiar aktualny rozmiar tablicy
* @param NowyRozmiar nowy rozmiar tablicy
* @return tablica o nowym rozmiarze
*/
int* zmien_rozmiar(int* tablica, int& rozmiar, int NowyRozmiar);

/** Funkcja zmieniająca zawartość wybranej komórki
* @param tablica aktualizowana tablica
* @param komorka aktualizowana komorka tablicy
* @param zmiana nowa wartosc wpisywana do komorki
*/
void zmien_zawartosc_komorki(int* tablica, int komorka, int zmiana);

/** Funkcja wyswietlajaca tablice
* @param tablica wyswietlana tablica
* @param rozmiar rozmiar wyswietlanej tablicy
*/
void wyswietlanie_tablicy(int* tablica, int rozmiar);

#endif
