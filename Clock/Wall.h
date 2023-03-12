#pragma once

#include "Mechanical.h"

class Wall : public Mechanical
{
private:
    char form[kReservedSize]; //форма
    int value; //цена деления циферблата
public:
    Wall();
    ~Wall();
    void SetForm(char*);
    char* GetForm();
    void SetValue(int);
    int GetValue();
    friend ostream& operator <<(ostream& out, Wall obj);
    friend istream& operator >> (istream& in, Wall& obj);
    friend fstream& operator <<(fstream& fout, Wall obj);
    friend fstream& operator >> (fstream& fin, Wall& obj);
    void TableHeader();
    void Edit();
    //friend void operator ~(Wall ob);
    static string GetNameOfClass();

    bool operator == (Wall ob);
    friend bool operator <(const Wall& ob1, const Wall& ob2);
    friend bool operator >(const Wall& ob1, const Wall& ob2);
};
