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
	Interface() {}; //����������� ��� ����������
	~Interface() {}; //���������� ��� ����������
	void menu(); //���� ������ ������ ��� ������ � ����
	void fun(string text_file, string binary_file); //���� ������ � ������� ���������� ����
	//friend bool operator <(const T& obj, const T& obj1);
	//void addElement(Container<T>& obj); //���������� ��������
	//void deleteElement(Container<T>& obj); //�������� ��������
	void viewElements(const multiset<T>& mult); //�������� ������� ���������
	//void editElement(Container<T>& obj, Algoritm<T>& alg); //�������������� ��������
};