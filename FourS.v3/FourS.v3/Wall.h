#pragma once

#include "Mechanical.h"

class Wall : public Mechanical
{
private:
	char form[RESERVESIZE]; //форма
	int value; //цена деления циферблата
public:
	Wall();
	~Wall();
	void set_form(char*);
	char* get_form();
	void set_value(int);
	int get_value();
	friend ostream& operator <<(ostream& out, Wall obj);
	friend istream& operator >> (istream& in, Wall& obj);
	friend fstream& operator <<(fstream& fout, Wall obj);
	friend fstream& operator >> (fstream& fin, Wall& obj);
	void tableCap();
	void edit();
	//friend void operator ~(Wall ob);
	static string getNameOfClass();

	bool operator == (Wall ob);
	friend bool operator <(const Wall& ob1, const Wall& ob2);
	friend bool operator >(const Wall& ob1, const Wall& ob2);
};

