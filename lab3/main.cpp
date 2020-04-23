#include<iostream>
#include<fstream>
#include "menu.h"
#include "tablica.h"
using namespace std;

int main(){
	cout<< "Witaj w moim programie"<<endl<<endl;
	Tablica arr;
	arr.wiersze=0;
	arr.kolumny=0;
	petla_menu(arr);	

	

	return 0;
}

