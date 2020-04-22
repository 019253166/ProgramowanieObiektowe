#ifndef TABLICA_H
#define TABLICA_H
/** Struktura przechowująca tablicę, ilość wierszy oraz ilość kolumn
*/
struct Tablica{
	int **tablica;
	int wiersze;
	int kolumny;
};

/** Funkcja zmieniająca rozmiar tablicu
* @param *arr obiekt tablica której rozmiar zmieniamy 
* @param Nowe_wier nowa liczba wierszy
* @param Nowe_kol nowa liczba kolumn
* @return Tablica o nowym rozmiarze
*/
int** zmien_rozmiar(Tablica* arr, int Nowe_wier, int Nowe_kol);
/** Funkcja zmieniająca zawartość wybranej komórki
* @param Tablica* arr aktualizowana tablica
* @param w_komorka nr wiersza aktualizowanej komorki
* @oaram k_komorka nr kolumny aktualizowanej komorki
* @param zmiana nowa wartosc wpisywana do komorki
*/
void zmien_zawartosc_komorki(Tablica arr, int w_komorka, int k_komorka, int zmiana);

/** Funkcja wyswietlajaca tablice
* @param Tablica arr wyswietlana tablica
*/
void wyswietlanie_tablicy(Tablica arr);
/** Funkcja wczytująca dane z pliku
* @param Tablica * arr tablica do której wczytujemy dane
*/
void Tab_z_pliku(Tablica * arr);
/** Funkcja zapisująca zawartość tablicy do pliku
* @param Tablica arr tablica z której zapisujemy dane
*/

void Tab_do_pliku(Tablica arr);

/** Poniższe funkcje wykonują obliczenia na wierszach i kolumnach
* @param Tablica arr tablica wraz z jej rozmiarem - liczbą wierszy i kolumn
*/
void Suma_W(Tablica arr);

void Suma_K(Tablica arr);

void Min_K(Tablica arr);

void Max_K(Tablica arr);

void Min_W(Tablica arr);

void Max_W(Tablica arr);

void Srednia_K(Tablica arr);

void Srednia_W(Tablica arr);


#endif
