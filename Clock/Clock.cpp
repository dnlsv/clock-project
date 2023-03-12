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

void Clock::SetProducer(char* buf)
{
    strcpy_s(producer, kReservedSize, buf);
}

char* Clock::GetProducer()
{
    return producer;
}

void Clock::SetMaterial(char* buf)
{
    strcpy_s(material, kReservedSize, buf);
}

char* Clock::GetMaterial()
{
    return material;
}

void Clock::SetCost(int buf)
{
    buf = cost;
}

int Clock::GetCost()
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
    strcpy_s(obj.producer, CheckStr(in));
    cout << "Материал: ";
    strcpy_s(obj.material, CheckStr(in));
    cout << "Цену (от 1 до 100): ";
    obj.cost = CheckInt(in, 1, 100);
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
