#pragma once

#include "Clock.h"

class Mechanical : public Clock
{
protected:
    char face[kReservedSize]; //тип циферблата
    char glass[kReservedSize]; //стекло
public:
    Mechanical();
    ~Mechanical();
    void SetFace(char*);
    char* GetFace();
    void SetGlass(char*);
    char* GetGlass();
    friend ostream& operator <<(ostream& out, Mechanical& obj);
    friend istream& operator >> (istream& in, Mechanical& obj);
    friend fstream& operator <<(fstream& fout, Mechanical& obj);
    friend fstream& operator >> (fstream& fin, Mechanical& obj);
};
