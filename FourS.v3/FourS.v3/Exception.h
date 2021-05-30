#pragma once

#include <iostream>
#include <string>

using namespace std;

class Exception
{
protected:
	char mess[200];
public:
	Exception()
	{
		mess[0] = '\0';
	}
	Exception(const char* ss)
	{
		strcpy_s(mess, ss);
	}
	void show()
	{
		cout << mess << endl;
	}
};