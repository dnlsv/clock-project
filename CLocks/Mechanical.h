#pragma once

#include "Clock.h"

class Mechanical : public Clock
{
protected:
	char face[RESERVESIZE]; //тип циферблата
	char glass[RESERVESIZE]; //стекло
public:
	Mechanical();
	~Mechanical();
	void set_face(char*);
	char* get_face();
	void set_glass(char*);
	char* get_glass();
	friend ostream& operator <<(ostream& out, Mechanical& obj);
	friend istream& operator >> (istream& in, Mechanical& obj);
	friend fstream& operator <<(fstream& fout, Mechanical& obj);
	friend fstream& operator >> (fstream& fin, Mechanical& obj);
};
