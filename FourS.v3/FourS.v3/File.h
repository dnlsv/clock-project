#pragma once

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class File
{
protected:
	string file_name;
	fstream file_stream;
public:
	File(string name)
	{
		file_name = name;
	}
};