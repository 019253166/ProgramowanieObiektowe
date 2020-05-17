#ifndef TABLICA_H
#define TABLICA_H
/** Struktura przechowująca tablicę, ilość wierszy oraz ilość kolumn
*/
struct Tablica{
	int **tablica;
	int wiersze;
	int kolumny;
};


/** Funkcja zmieniająca rozmiar tablicy
* @param[in,out]Tablica & arr - obiekt tablica której rozmiar zmieniamy 
* @param[in] Nowe_wier - nowa liczba wierszy
* @param[in] Nowe_kol - nowa liczba kolumn
*/
void zmien_rozmiar(Tablica & arr, int Nowe_wier, int Nowe_kol);

/** Funkcja zmieniająca zawartość wybranej komórki
* @param[in,out]Tablica arr - aktualizowana tablica
* @param[in] w_komorka - nr wiersza aktualizowanej komorki
* @oaram[in] k_komorka - nr kolumny aktualizowanej komorki
* @param[in] zmiana - nowa wartosc wpisywana do komorki
* @return - 0 w przypadku powodzenia lub -1 w przypadku nieistniejącego wiersza lub kolumny
*/
int zmien_zawartosc_komorki(Tablica arr, int w_komorka, int k_komorka, int zmiana);


/** Funkcja wczytująca dane z pliku
* @param[in,out] Tablica * arr - tablica do której wczytujemy dane
* @return 0 w przypadku powodzenia lub -1 w przypadku błędu w otworzeniu pliku
*/
int Tab_z_pliku(Tablica * arr);

/** Funkcja zapisująca zawartość tablicy do pliku
* @param[in] Tablica arr - tablica z której zapisujemy dane
* @return - 0 w przypadku powodzenia lub -1 w przypadku błędy w otworzeniu pliku
*/
int Tab_do_pliku(Tablica arr);

/** Poniższe funkcje wykonują obliczenia na wierszach i kolumnach
* @param Tablica arr tablica wraz z jej rozmiarem - liczbą wierszy i kolumn
* @return - 0 w przypadku powodzenia lub -1 w przypadku podania nieistniejącego wiersza lub kolumny
*/
int Suma_W(Tablica arr, int nr_w);

int Suma_K(Tablica arr, int nr_k);

int Min_K(Tablica arr, int nr_k);

int Max_K(Tablica arr, int nr_k);

int Min_W(Tablica arr, int nr_w);

int Max_W(Tablica arr, int nr_w);

int Srednia_K(Tablica arr, int nr_k);

int Srednia_W(Tablica arr, int nr_w);


#endif
