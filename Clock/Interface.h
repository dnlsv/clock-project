#pragma once

#include "Electronic.h"
#include "Wall.h"
#include "Wrist.h"
#include "FileText.cpp"
#include "FileBinary.cpp"
#include<set>
#include<algorithm>
#include<iterator>

template <class T>
class Interface
{
private:
	T element;
public:
	Interface() {}; //конструктор без параметров
	~Interface() {}; //деструктор без параметров
	void menu(); //меню выбора данных для работы с ними
	void fun(string text_file, string binary_file); //меню работы с данными выбранного типа
	//friend bool operator <(const T& obj, const T& obj1);
	//void addElement(Container<T>& obj); //добавление элемента
	//void deleteElement(Container<T>& obj); //удаление елемента
	void viewElements(const multiset<T>& mult); //просмотр таблицы элементов
	//void editElement(Container<T>& obj, Algoritm<T>& alg); //редактирование елемента
};