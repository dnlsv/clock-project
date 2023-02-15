#include "Electronic.h"

Electronic::Electronic()
{
	type[0] = '\0';
	platform[0] = '\0';
}

Electronic::~Electronic()
{

}

void Electronic::set_type(char* buf)
{
	strcpy_s(type, RESERVESIZE, buf);
}

char* Electronic::get_type()
{
	return type;
}

void Electronic::set_platform(char* buf)
{
	strcpy_s(platform, RESERVESIZE, buf);
}

char* Electronic::get_platform()
{
	return platform;
}

ostream& operator <<(ostream& out, Electronic obj)
{
	out << dynamic_cast <Clock&>(obj);
	out << setw(11) << obj.type << setw(11) << obj.platform << endl;
	return out;
}

istream& operator >> (istream& in, Electronic& obj)
{
	in >> dynamic_cast<Clock&>(obj);
	cout << "��� �����: ";
	strcpy_s(obj.type, validationCheckStr(in));
	cout << "���������: ";
	strcpy_s(obj.platform, validationCheckStr(in));
	return in;
}

fstream& operator <<(fstream& fout, Electronic obj)
{
	fout << dynamic_cast <Clock&>(obj);
	fout << obj.type << "!" << obj.platform << "!";
	return fout;
}


fstream& operator >> (fstream& fin, Electronic& obj)
{
	fin >> dynamic_cast<Clock&>(obj);
	fin.ignore(255, ' ');
	fin.getline(obj.type, 20, '!');
	fin.getline(obj.platform, 20, '!');
	//fin >> obj.platform;
	return fin;
}

void Electronic::tableCap()
{
	cout << " " << setw(3) << left << "�" << setw(15) << "�������������" << setw(10) << "��������" << setw(6) << "����"
		<< setw(11) << "��� �����" << setw(11) << "���������" << endl;
}

void Electronic::edit()
{
	int num;
	cout << endl << "\t����� ������ ��������?" << endl << endl << "1 - �������������" << endl
		<< "2 - ��������" << endl << "3 - ����" << endl << "4 - ��� �����"
		<< endl << "5 - ���������" << endl;
	cin >> num;
	cout << endl << "\t������� ����� ������" << endl << endl;
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
		cin >> type;
		break;
	case 5:
		cin >> platform;
		break;
	}
}

string Electronic::getNameOfClass()
{
	return "Electonic";
}

bool Electronic::operator == (Electronic ob)
{
	if ((strcmp(producer, ob.producer) == 0) && (strcmp(material, ob.material) == 0) && (cost == ob.cost) && (strcmp(type, ob.type) == 0) && (strcmp(platform, ob.platform) == 0))
		return true;
	else
		return false;
}

bool operator <(const Electronic& ob1, const Electronic& ob2)
{
	if (ob1.cost < ob2.cost)
		return true;
	else
		return false;
}

bool operator >(const Electronic& ob1, const Electronic& ob2)
{
	if (ob1.cost > ob2.cost)
		return true;
	else
		return false;
}