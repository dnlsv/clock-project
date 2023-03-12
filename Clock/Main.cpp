#include<iostream>

#include "Interface.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF8");

    Interface<int> obj;
    obj.Menu();

    system("pause");
    return 0;
}
