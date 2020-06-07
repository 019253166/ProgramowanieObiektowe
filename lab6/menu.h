#ifndef MENU_H
#define MENU_H
#include "tablica.h"

/**
* funkcja wyswietlajaca menu programu */
void wyswietlanie_menu();

/** funkcja przetwarzajaca wybor uzytkownika
* @param[in,out] wybor - numer funkcji wybrany przez uzytkownika */
void wybierz_funkcje(int *wybor);

/** funkcja wczytujaca wybor uzytkownika
* @param[in] wybor - wybor uzytkownika 
* @param[in,out] Tablica arr - tablica na której pracują podprogramy 
*/
void pretworz_wybor(int wybor, Tablica *arr);

/** funkcja petli dla menu
* @param[in,out] Tablica *arr - wskaźnik na obiekt klasy na ktorej program bedzie pracowac */
void petla_menu(Tablica *arr);

#endif
