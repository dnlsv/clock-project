#pragma once

#include "Mechanical.h"

class Wrist : public Mechanical
{
private:
    char strapMaterial[kReservedSize]; //материал ремешка
    bool water; //водозащита
public:
    Wrist();
    ~Wrist();
    void SetStrapMaterial(char*);
    char* GetStrapMaterial();
    void SetWater(bool);
    bool GetWater();
    friend ostream& operator <<(ostream& out, Wrist obj);
    friend istream& operator >> (istream& in, Wrist& obj);
    friend fstream& operator <<(fstream& fout, Wrist obj);
    friend fstream& operator >> (fstream& fin, Wrist& obj);
    void TableHeader();
    void Edit();
    //friend void operator ~(Wrist ob);
    static string GetNameOfClass();

    bool operator == (Wrist ob);
    friend bool operator <(const Wrist& ob1, const Wrist& ob);
    friend bool operator >(const Wrist& ob1, const Wrist& o);
};
