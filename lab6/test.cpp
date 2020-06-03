#include<iostream>
#include<fstream>
#include "Cell.h"
#include<string>
using namespace	std;

int main(){
	const string tekst="tekst";
	Cell ***tablica;
	tablica=new Cell **[3];
	for(int i=0; i<3;i++){
		tablica[i]=new Cell*[3];
	}

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(j==0){
				tablica[i][j]=new Cell_Int;
			}
			else
				tablica[i][j]= new Cell_String;
		}
	}
	
	for(int i=0; i<3;i++){
		for(int j=0;j<3;j++){
			if(j==0){
			tablica[i][j]->ustaw_wartosc(to_string(0));
			}
			else{ 
				tablica[i][j]->ustaw_wartosc(tekst);
			}
		}
	}
	for(int i=0; i<3;i++){
		for(int j=0;j<3;j++){
			cout<<tablica[i][j]->zwroc_wartosc()<<"\t";
		}
		cout<<endl;
	}
	
	return 0;
}
