#pragma once

#include "Exception.h"

class ExceptionInput : public Exception
{
	int kod;
public:
	ExceptionInput(int n, const char* ss)
	{
		strcpy_s(mess, ss);
		kod = n;
	}
	void showKod()
	{
		cout << "Код ошибки: " << kod << endl;
		cout << mess << endl;
	}
};

char* validationCheckStr(istream& in);
char* validationCheckPas(istream& in);
int validationCheckInt(istream& in, int min, int max);