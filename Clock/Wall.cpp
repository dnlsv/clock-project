#include "Wall.h"

Wall::Wall()
{
	form[0] = '\0';
	value = 0;
}

Wall::~Wall()
{

}

void Wall::set_form(char* buf)
{
	strcpy_s(form, RESERVESIZE, buf);
}

char* Wall::get_form()
{
	return form;
}

void Wall::set_value(int buf)
{
	buf = value;
}

int Wall::get_value()
{
	return value;
}

ostream& operator <<(ostream& out, Wall obj)
{
	out << dynamic_cast <Mechanical&>(obj);
	out << setw(13) << obj.form << setw(14) << obj.value << endl;
	return out;
}

istream& operator >> (istream& in, Wall& obj)
{
	in >> dynamic_cast<Mechanical&>(obj);
	cout << "Форма часов: ";
	strcpy_s(obj.form, validationCheckStr(in));
	cout << "Цена деления циферблата (от 6 до 24): ";
	obj.value = validationCheckInt(in, 6, 24);
	return in;
}

fstream& operator <<(fstream& fout, Wall obj)
{
	fout << dynamic_cast <Mechanical&>(obj);
	fout << obj.form << "!" << obj.value;
	return fout;
}

fstream& operator >> (fstream& fin, Wall& obj)
{
	fin >> dynamic_cast<Mechanical&>(obj);
	fin.getline(obj.form, 20, '!');
	fin >> obj.value;
	return fin;
}

void Wall::tableCap()
{
	cout << " " << setw(3) << left << "№" << setw(15) << "Производитель" << setw(10) << "Материал" << setw(6) << "Цена"
		<< setw(16) << "Тип циферблата" << setw(12) << "Тип стекла" << setw(13) << "Форма часов"
		<< setw(14) << "Цена деления циферблата" << endl;
}

void Wall::edit()
{
	int num;
	cout << endl << "\tКакие данные изменить?" << endl << endl << "1 - Производитель" << endl
		<< "2 - Материал" << endl << "3 - Цена" << endl << "4 - Тип циферблата"
		<< endl << "5 - Тип стекла" << endl << "6 - Форма часов" << endl << "7 - Цена деления циферблата" << endl;
	cin >> num;
	cout << endl << "\tВведите новые данные" << endl << endl;
	switch (num)
	{
	case 1:
		cin >> producer;
		break;
	case 2:
		cin >> material;
		break;
	case 3:
		cin >> cost;
		break;
	case 4:
		cin >> face;
		break;
	case 5:
		cin >> glass;
		break;
	case 6:
		cin >> form;
		break;
	case 7:
		cin >> value;
		break;
	}
}

string Wall::getNameOfClass()
{
	return "Wall";
}

bool Wall::operator == (Wall ob)
{
	if ((strcmp(producer, ob.producer) == 0) && (strcmp(material, ob.material) == 0) && (cost == ob.cost) && (strcmp(face, ob.face) == 0) && (strcmp(glass, ob.glass) == 0) && (strcmp(form, ob.form) == 0) && (value == ob.value))
		return true;
	else
		return false;
}

bool operator <(const Wall& ob1, const Wall& ob2)
{
	if (ob1.cost < ob2.cost)
		return true;
	else
		return false;
}

bool operator >(const Wall& ob1, const Wall& ob2)
{
	if (ob1.cost > ob2.cost)
		return true;
	else
		return false;
}