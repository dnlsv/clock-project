#pragma once

#include <cstdio>

#include "File.h"

template<class T>
class FileBinary : public File
{
public:
    FileBinary(string name);
    ~FileBinary();
    void Clear();
    void WriteBinary(T& object);
    void ReadBinary(T& object);
    bool EndFile();
    void CleanBinaryFile();
};
