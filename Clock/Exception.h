#pragma once

#include <iostream>
#include <string>

using namespace std;

class Exception
{
protected:
    char msg[200];
public:
    Exception()
    {
        msg[0] = '\0';
    }
    Exception(const char* message)
    {
        strcpy_s(msg, message);
    }
    void ShowMsg()
    {
        cout << msg << endl;
    }
};
