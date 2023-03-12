#pragma once

#include "Clock.h"

class Electronic : public Clock
{
private:
    char type[kReservedSize]; //тип часов
    char platform[kReservedSize]; //платформа
public:
    Electronic();
    ~Electronic();
    void SetType(char*);
    char* GetType();
    void SetPlatform(char*);
    char* GetPlatform();
    friend ostream& operator <<(ostream& out, Electronic obj);
    friend istream& operator >> (istream& in, Electronic& obj);
    friend fstream& operator <<(fstream& fout, Electronic obj);
    friend fstream& operator >> (fstream& fin, Electronic& obj);
    void TableHeader();
    void Edit();
    //friend void operator ~(Electronic ob);
    static string GetNameOfClass();
    friend fstream& operator <<(fstream& fout, Electronic obj);
    friend fstream& operator >> (fstream& fin, Electronic& obj);

    bool operator == (Electronic ob);
    friend bool operator <(const Electronic& ob1, const Electronic& ob2);
    friend bool operator >(const Electronic& ob1, const Electronic& ob2);
};
