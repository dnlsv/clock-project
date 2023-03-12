#include "Wrist.h"

Wrist::Wrist()
{
    strapMaterial[0] = '\0';
    water = 0;
}

Wrist::	~Wrist()
{

}

void Wrist::SetStrapMaterial(char* buf)
{
    strcpy_s(strapMaterial, kReservedSize, buf);
}

char* Wrist::GetStrapMaterial()
{
    return strapMaterial;
}

void Wrist::SetWater(bool buf)
{
    buf = water;
}

bool Wrist::GetWater()
{
    return water;
}

ostream& operator <<(ostream& out, Wrist obj)
{
    out << dynamic_cast <Mechanical&>(obj);
    out << setw(18) << obj.strapMaterial << setw(12) << obj.water << endl;
    return out;
}

istream& operator >> (istream& in, Wrist& obj)
{
    in >> dynamic_cast<Mechanical&>(obj);
    cout << "Материал ремешка: ";
    strcpy_s(obj.strapMaterial, CheckStr(in));
    cout << "Водозащита (1 - Есть, 0 - Нет): ";
    in >> obj.water;
    return in;
}

fstream& operator <<(fstream& fout, Wrist obj)
{
    fout << dynamic_cast <Mechanical&>(obj);
    fout << obj.strapMaterial << "!" << obj.water;
    return fout;
}

fstream& operator >> (fstream& fin, Wrist& obj)
{
    fin >> dynamic_cast<Mechanical&>(obj);
    fin.getline(obj.strapMaterial, 20, '!');
    fin >> obj.water;
    return fin;
}

void Wrist::TableHeader()
{
    cout << " " << "№  " << "Производитель  " << "Материал  " << "Цена  " << "Тип циферблата  "
        << "Тип стекла  " << "Материал ремешка  " << "Водозащита  " << endl;
}

void Wrist::Edit()
{
    int num;
    cout << endl << "\tКакие данные изменить?" << endl << endl << "1 - Производитель" << endl
        << "2 - Материал" << endl << "3 - Цена" << endl << "4 - Тип циферблата"
        << endl << "5 - Тип стекла" << endl << "6 - Материал ремешка" << endl << "7 - Водозащита" << endl;
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
        cin >> strapMaterial;
        break;
    case 7:
        cin >> water;
        break;
    }
}

string Wrist::GetNameOfClass()
{
    return "Wrist";
}

bool Wrist::operator == (Wrist ob)
{
    if ((strcmp(producer, ob.producer) == 0) && (strcmp(material, ob.material) == 0) && (cost == ob.cost) && (strcmp(face, ob.face) == 0) && (strcmp(glass, ob.glass) == 0) && (strcmp(strapMaterial, ob.strapMaterial) == 0) && (water == ob.water))
        return true;
    else
        return false;
}

bool operator <(const Wrist& ob1, const Wrist& ob2)
{
    if (ob1.cost < ob2.cost)
        return true;
    else
        return false;
}

bool operator >(const Wrist& ob1, const Wrist& ob2)
{
    if (ob1.cost > ob2.cost)
        return true;
    else
        return false;
}
