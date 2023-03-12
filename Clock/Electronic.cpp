#include "Electronic.h"

Electronic::Electronic()
{
    type[0] = '\0';
    platform[0] = '\0';
}

Electronic::~Electronic()
{

}

void Electronic::SetType(char* buf)
{
    strcpy_s(type, kReservedSize, buf);
}

char* Electronic::GetType()
{
    return type;
}

void Electronic::SetPlatform(char* buf)
{
    strcpy_s(platform, kReservedSize, buf);
}

char* Electronic::GetPlatform()
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
    cout << "Тип часов: ";
    strcpy_s(obj.type, CheckStr(in));
    cout << "Платформа: ";
    strcpy_s(obj.platform, CheckStr(in));
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

void Electronic::TableHeader()
{
    cout << " " << "№  " << "Производитель  " << "Материал  " << "Цена  " << "Тип часов  "
        << "Платформа  " << endl;
}

void Electronic::Edit()
{
    int num;
    cout << endl << "\tКакие данные изменить?" << endl << endl << "1 - Производитель" << endl
        << "2 - Материал" << endl << "3 - Цена" << endl << "4 - Тип часов"
        << endl << "5 - Платформа" << endl;
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
        cin >> type;
        break;
    case 5:
        cin >> platform;
        break;
    }
}

string Electronic::GetNameOfClass()
{
    return "Electronic";
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
