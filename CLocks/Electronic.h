#pragma once

#include "Clock.h"

class Electronic : public Clock
{
private:
	char type[RESERVESIZE]; //тип часов
	char platform[RESERVESIZE]; //платформа
public:
	Electronic();
	~Electronic();
	void set_type(char*);
	char* get_type();
	void set_platform(char*);
	char* get_platform();
	friend ostream& operator <<(ostream& out, Electronic obj);
	friend istream& operator >> (istream& in, Electronic& obj);
	friend fstream& operator <<(fstream& fout, Electronic obj);
	friend fstream& operator >> (fstream& fin, Electronic& obj);
	void tableCap();
	void edit();
	//friend void operator ~(Electronic ob);
	static string getNameOfClass();
	friend fstream& operator <<(fstream& fout, Electronic obj);
	friend fstream& operator >> (fstream& fin, Electronic& obj);

	bool operator == (Electronic ob);
	friend bool operator <(const Electronic& ob1, const Electronic& ob2);
	friend bool operator >(const Electronic& ob1, const Electronic& ob2);
};

