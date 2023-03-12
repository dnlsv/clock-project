#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Validation.h"

using namespace std;
const int kReservedSize = 20;

class Clock
{
protected:
    char producer[kReservedSize]; //производитель
    char material[kReservedSize]; //материал
    int cost; //стоимость
public:
    Clock();
    ~Clock();
    void SetProducer(char*);
    char* GetProducer();
    void SetMaterial(char*);
    char* GetMaterial();
    void SetCost(int);
    int GetCost();
    friend ostream& operator <<(ostream& out, Clock& obj);
    friend istream& operator >> (istream& in, Clock& obj);
    friend fstream& operator <<(fstream& fout, Clock& obj);
    friend fstream& operator >> (fstream& fin, Clock& obj);
};
