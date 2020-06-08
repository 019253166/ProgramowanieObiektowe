#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <string>
using namespace std;
/* Intefejs reprezentujący funkcje dla komórki w tablicy*/
class Cell
{
public:
	virtual int zwroc_liczba()=0;
	virtual string zwroc_tekst()=0;
	virtual int ustaw_wartosc(int nowa_wartosc)=0;
	virtual int ustaw_wartosc(string nowa_wartosc)=0;
	
};
	
/*Klasa reprezentująca komórkę zawierającą dane liczbowe*/
class Cell_Int: public Cell
{
private:/*wartość znajdująca się w komórce*/
	int liczba;
public:
/* metoda zwracająca zawartość liczbową komórki
*@return liczba - zawartość komórki */
	virtual int zwroc_liczba(){
		return liczba;
	}
/* metoda zwracająca tekstową zawartość komórki 
@return to_string(liczba) - zawartość komórki */
	virtual string zwroc_tekst(){
		return to_string(liczba);
	}
/* metoda zmieniająca zawartość komórki liczbowej
* @param[in] nowa_wartosc - wartość wstawiana do pola
* @return 0 w przypadku powodzenia
*/
	virtual int ustaw_wartosc(int nowa_wartosc){
		liczba=nowa_wartosc;
		return 0;
	}
/* metoda zmieniająca zawartość komórki tekstowej
@ param [in] nowa_wartosc - wartosc wstawiana do pola
* @return -1 ponieważ jest to komórka liczbowa więc nie można podstawić typu string
*/
	virtual int ustaw_wartosc(string nowa_wartosc){
		return -1;
	}
/*konstruktor klasy, ustawia wartość domyślną pola liczba jako 0 */
	Cell_Int(){
		liczba=0;
	}
};

/* klasa reprezentująca komórkę zawierającą dane tekstowe */
class Cell_String: public Cell
{
private:
/* wartość znajdująca się w w komórce */
	string tekst;
public:
/* metoda zwracająca zawartość liczbową komórki 
@return 0 ponieważ jest to komórka tekstowa */
	virtual int zwroc_liczba(){
		return 0;
	}
/* metoda zwracająca zawartość tekstową komórki
@return tekst - zawartość komórki */
	virtual string zwroc_tekst(){
		return tekst;
	}
/* metoda zmieniająca zawartość komórki
@param nowa_wartosc - wartosc wstawiana do pola
@return 0 - ponieważ jest to komórka tekstowa
*/
	virtual int ustaw_wartosc(int nowa_wartosc){
		return 0;
	}
/* metoda zmieniająca tekstową zawartość komórki
@param nowa_wartosc - wartość wstawiana do pola
@return 0 w przypadku powodzenia
*/
	virtual int ustaw_wartosc(string nowa_wartosc){
		tekst=nowa_wartosc;
		return 0;
	}
/*konstruktor klasy ustawiająca wartość pola tekst domyślnie na "pusto"
*/
	Cell_String(){
		tekst="pusto";
	}
};
#endif
