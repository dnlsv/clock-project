#include "Mechanical.h"

Mechanical::Mechanical()
{
	face[0] = '\0';
	glass[0] = '\0';
}

Mechanical::~Mechanical()
{

}

void Mechanical::set_face(char* buf)
{
	strcpy_s(face, RESERVESIZE, buf);
}

char* Mechanical::get_face()
{
	return face;
}

void Mechanical::set_glass(char* buf)
{
	strcpy_s(glass, RESERVESIZE, buf);
}

char* Mechanical::get_glass()
{
	return glass;
}

ostream& operator <<(ostream& out, Mechanical& obj)
{
	out << dynamic_cast <Clock&>(obj);
	out << setw(16) << obj.face << setw(12) << obj.glass;
	return out;
}

istream& operator >> (istream& in, Mechanical& obj)
{
	in >> dynamic_cast<Clock&>(obj);
	cout << "Тип циферблата: ";
	strcpy_s(obj.face, validationCheckStr(in));
	cout << "Тип стекла: ";
	strcpy_s(obj.glass, validationCheckStr(in));
	return in;
}

fstream& operator <<(fstream& fout, Mechanical& obj)
{
	fout << dynamic_cast <Clock&>(obj);
	fout << obj.face << "!" << obj.glass << "!";
	return fout;
}

fstream& operator >> (fstream& fin, Mechanical& obj)
{
	fin >> dynamic_cast<Clock&>(obj);
	fin.ignore(255, ' ');
	fin.getline(obj.face, 20, '!');
	fin.getline(obj.glass, 20, '!');
	return fin;
}