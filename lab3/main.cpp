#include<iostream>
#include<fstream>
#include "menu.h"
#include "tablica.h"
using namespace std;

int main(){
	cout<< "Witaj w moim programie"<<endl<<endl;
	int ** tablica;
	int wiersze =0;
	int kolumny =0;
	
	petla_menu(tablica);	

	return 0;
}

