#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <string>
using namespace std;
class Cell
{
private:
int liczba;
string tekst;
public:
	int zwroc_liczba(){return liczba;}
	string zwroc_tekst(){return tekst;}
	Cell(){
	liczba=0;
	tekst="";
	}
};	
#endif
