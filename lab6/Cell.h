#ifndef Cell_H
#define Cell_H
#include <iostream>
#include <string>
using namespace std;
class Cell
{

public:

	enum Type{
		UNKNOWN, INT, STRING
	};
	virtual string zwroc_wartosc()=0;
	Type get_type(){
		return cell_type;
	}
	Cell(){
		cell_type=UNKNOWN;
	}
	virtual void ustaw_wartosc(const string & nowa_wartosc) =0;
protected:
	Type cell_type;

	
};	

class Cell_Int: public Cell {
public:
	Cell_Int(){
		liczba=0;
		cell_type = INT;
	}
	virtual string zwroc_wartosc(){
		return to_string(liczba);
	}
	void ustaw_wartosc(const string & nowa_wartosc){
		liczba=stoi(nowa_wartosc);
	}
private: 
	int liczba;
};

class Cell_String:public Cell {
public:
	Cell_String(){
		tekst=" ";
		cell_type=STRING;
	}
	virtual string zwroc_wartosc(){
		return tekst;
	}
	void ustaw_wartosc(const string & nowa_wartosc){
		tekst=nowa_wartosc;
	}
private:
	string tekst;
};
#endif
