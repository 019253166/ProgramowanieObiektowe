#ifndef MENU_H
#define MENU_H
#include "tablica.h"

/**
* funkcja wyswietlajaca menu programu */
void wyswietlanie_menu();

/** funkcja przetwarzajaca wybor uzytkownika
* @param wybor numer wybrany przez uzytkownika */
void wybierz_funkcje(int *wybor);

/** funkcja wczytujaca wybor uzytkownika
* @param wybor wybor uzytkownika */
void pretworz_wybor(int wybor, Tablica arr);

/** funkcja petli dla menu
* @param arr tablica na ktorej program bedzie pracowac */
void petla_menu(Tablica arr);

#endif
