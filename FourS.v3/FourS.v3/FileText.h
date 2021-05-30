#pragma once
#include "File.h"

template<class T>
class FileText : public File
{
public:
	FileText(string name);
	~FileText();
	void WriteText(T& object, int i, int count);
	void ReadText(T& object, int i);
	bool EndFile();
	void Remote();
	void CleanTextFile();
};