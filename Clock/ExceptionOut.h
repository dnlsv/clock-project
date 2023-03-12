#pragma once

#include "Exception.h"

class ExceptionOut : public Exception
{
    int code;
public:
    ExceptionOut(int n, const char* message) : Exception(message)
    {
        code = n;
    }
    void ShowCode()
    {
        cout << "Код ошибки: " << code << endl;
        ShowMsg();
    }
};
