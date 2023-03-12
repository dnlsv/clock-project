#pragma once

#include <set>
#include <algorithm>
#include <iterator>

#include "Electronic.h"
#include "Wall.h"
#include "Wrist.h"
#include "FileText.cpp"
#include "FileBinary.cpp"

template <class T>
class Interface
{
private:
    T element;
public:
    Interface() {}; //конструктор без параметров
    ~Interface() {}; //деструктор без параметров
    void Menu(); //меню выбора данных для работы с ними
    void Fun(string file_name); //меню работы с данными выбранного типа
    //friend bool operator <(const T& obj, const T& obj1);
    //void addElement(Container<T>& obj); //добавление элемента
    //void deleteElement(Container<T>& obj); //удаление елемента
    void ViewElements(const multiset<T>& clocks); //просмотр таблицы элементов
    //void editElement(Container<T>& obj, Algoritm<T>& alg); //редактирование елемента
};
