#include "Clock.h"

Clock::Clock()
{
	producer[0] = '\0';
	material[0] = '\0';
	cost = 0;
}

Clock::~Clock()
{

}

void Clock::set_producer(char* buf)
{
	strcpy_s(producer, RESERVESIZE, buf);
}

char* Clock::get_producer()
{
	return producer;
}

void Clock::set_material(char* buf)
{
	strcpy_s(material, RESERVESIZE, buf);
}

char* Clock::get_material()
{
	return material;
}

void Clock::set_cost(int buf)
{
	buf = cost;
}

int Clock::get_cost()
{
	return cost;
}

ostream& operator <<(ostream& out, Clock& obj)
{
	out << setw(15) << obj.producer << setw(10) << obj.material << setw(6) << obj.cost;
	return out;
}

istream& operator >> (istream& in, Clock& obj)
{
	cout << "Введите" << endl << "Производителя: ";
	strcpy_s(obj.producer, validationCheckStr(in));
	cout << "Материал: ";
	strcpy_s(obj.material, validationCheckStr(in));
	cout << "Цену (от 1 до 100): ";
	obj.cost = validationCheckInt(in, 1, 100);
	return in;
}

fstream& operator <<(fstream& fout, Clock& obj)
{
	fout << obj.producer << "!" << obj.material << "!" << obj.cost << " ";
	return fout;
}

fstream& operator >> (fstream& fin, Clock& obj)
{
	fin.getline(obj.producer, 40, '!');
	fin.getline(obj.material, 40, '!');
	fin >> obj.cost;
	return fin;
}