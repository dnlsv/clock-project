#pragma once

#include "Mechanical.h"

class Wrist : public Mechanical
{
private:
	char materialrem[RESERVESIZE]; //материал ремешка
	bool water; //водозащита
public:
	Wrist();
	~Wrist();
	void set_materialrem(char*);
	char* get_materialrem();
	void set_water(bool);
	bool get_water();
	friend ostream& operator <<(ostream& out, Wrist obj);
	friend istream& operator >> (istream& in, Wrist& obj);
	friend fstream& operator <<(fstream& fout, Wrist obj);
	friend fstream& operator >> (fstream& fin, Wrist& obj);
	void tableCap();
	void edit();
	//friend void operator ~(Wrist ob);
	static string getNameOfClass();

	bool operator == (Wrist ob);
	friend bool operator <(const Wrist& ob1, const Wrist& ob);
	friend bool operator >(const Wrist& ob1, const Wrist& o);
};