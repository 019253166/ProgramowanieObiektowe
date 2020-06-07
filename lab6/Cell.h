#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <string>
using namespace std;
class Cell
{
public:
	virtual int zwroc_liczba()=0;
	virtual string zwroc_tekst()=0;
	virtual int ustaw_wartosc(int nowa_wartosc)=0;
	virtual int ustaw_wartosc(string nowa_wartosc)=0;
	
};
	

class Cell_Int: public Cell
{
private:
	int liczba;
public:
	virtual int zwroc_liczba(){
		return liczba;
	}
	virtual string zwroc_tekst(){
		return to_string(liczba);
	}
	virtual int ustaw_wartosc(int nowa_wartosc){
		liczba=nowa_wartosc;
		return 0;
	}
	virtual int ustaw_wartosc(string nowa_wartosc){
		return -1;
	}
	Cell_Int(){
		liczba=0;
	}
};

class Cell_String: public Cell
{
private:
	string tekst;
public:
	virtual int zwroc_liczba(){
		return 0;
	}
	virtual string zwroc_tekst(){
		return tekst;
	}
	virtual int ustaw_wartosc(int nowa_wartosc){
		return 0;
	}
	virtual int ustaw_wartosc(string nowa_wartosc){
		tekst=nowa_wartosc;
		return -1;
	}
	Cell_String(){
		tekst="pusto";
	}
};
#endif
