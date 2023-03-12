#include "Mechanical.h"

Mechanical::Mechanical()
{
    face[0] = '\0';
    glass[0] = '\0';
}

Mechanical::~Mechanical()
{

}

void Mechanical::SetFace(char* buf)
{
    strcpy_s(face, kReservedSize, buf);
}

char* Mechanical::GetFace()
{
    return face;
}

void Mechanical::SetGlass(char* buf)
{
    strcpy_s(glass, kReservedSize, buf);
}

char* Mechanical::GetGlass()
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
    strcpy_s(obj.face, CheckStr(in));
    cout << "Тип стекла: ";
    strcpy_s(obj.glass, CheckStr(in));
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
