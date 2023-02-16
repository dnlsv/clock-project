#include"FileText.h"

template<class T>
FileText<T>::FileText(string name) :File(name)
{
	file_stream.open(file_name, ios::out | ios::in);
}

template<class T>
FileText<T>::~FileText()
{
	file_stream.close();
}

template<class T>
void FileText<T>::WriteText(T& object, int i, int count)
{
	file_stream << object;
	if (i < count - 1)
		file_stream << endl;
}

template<class T>
void FileText<T>::ReadText(T& object, int i)
{
	if (i > 1)
		file_stream.ignore(255, '\n');
	file_stream >> object;
}

template<class T>
bool FileText<T>::EndFile()
{
	if (file_stream.peek() == '!' && file_stream.peek() + 1 == EOF)
		return true;
	if (file_stream.eof())
		return true;
	else
		return false;
}

template<class T>
void FileText<T>::Remote()
{
	file_stream.seekg(0, ios::beg);
	file_stream.seekp(0, ios::beg);
	file_stream.clear();
}

template<class T>
void FileText<T>::CleanTextFile()
{
	file_stream.close();
	file_stream.open(file_name, ios::out | ios::in | ios::trunc);
}