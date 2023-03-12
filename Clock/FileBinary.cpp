#include"FileBinary.h"

template<class T>
FileBinary<T>::FileBinary(string name) :File(name)
{
    file_stream.open(kOutPath + file_name + "Bin.txt", ios::in | ios::out | ios::binary);
}

template<class T>
FileBinary<T>::~FileBinary()
{
    file_stream.close();
}

template<class T>
void FileBinary<T>::WriteBinary(T& object)
{
    file_stream.write(reinterpret_cast<char*> (&object), sizeof(T));
}

template<class T>
void FileBinary<T>::ReadBinary(T& object)
{
    file_stream.read(reinterpret_cast<char*> (&object), sizeof(T));
}

template<class T>
bool FileBinary<T>::EndFile()
{
    if (file_stream.peek() != EOF)
        return true;
    else
        return false;
}

template<class T>
void FileBinary<T>::Clear()
{
    file_stream.seekg(0, ios::beg);
    file_stream.seekp(0, ios::beg);
    file_stream.clear();
}

template<class T>
void FileBinary<T>::CleanBinaryFile()
{
    file_stream.close();
    file_stream.open(kOutPath + file_name + "Bin.txt", ios::in | ios::out | ios::binary | ios::trunc);
}
