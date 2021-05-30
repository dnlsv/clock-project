#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include "ExceptionInput.h"

using namespace std;
const int RESERVESIZE = 20;

class Clock
{
protected:
	char producer[RESERVESIZE]; //производитель
	char material[RESERVESIZE]; //материал
	int cost; //стоимость
public:
	Clock();
	~Clock();
	void set_producer(char*);
	char* get_producer();
	void set_material(char*);
	char* get_material();
	void set_cost(int);
	int get_cost();
	friend ostream& operator <<(ostream& out, Clock& obj);
	friend istream& operator >> (istream& in, Clock& obj);
	friend fstream& operator <<(fstream& fout, Clock& obj);
	friend fstream& operator >> (fstream& fin, Clock& obj);
};

