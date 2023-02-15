#include "Interface.h"

template<class T>
void Interface<T>::menu()
{
	int num;

	while (1)
	{
		cout << "\t����" << endl << endl;
		cout << "1 - ����������� ����" << endl << "2 - �������� ����" << endl << "3 - ��������� ����" << endl << "0 - ���������" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
		{
			Interface<Electronic> obj;
			obj.fun("ElectronicText.txt", "ElectronicBinary.txt");
			break;
		}
		case 2:
		{
			Interface<Wrist> obj1;
			obj1.fun("WristText.txt", "WristBinary.txt");
			break;
		}
		case 3:
		{
			Interface<Wall> obj2;
			obj2.fun("WallText.txt", "WallBinary.txt");
			break;
		}
		case 0:
			return;
		}
	}
}

template <class T>
void Interface<T>::fun(string text_file, string binary_file)
{
	FileText<T>text(text_file);
	FileBinary<T>binary(binary_file);

	multiset<T> mult;
	typename multiset <T> ::iterator it;
	it = mult.begin();

	int num;
	bool flag = true;
	while (flag)
	{
		cout << endl << "1 - ��������" << endl << "2 - �������" << endl << "3 - ��������" << endl << "4 - �������������" << endl
			<< "5 - �����" << endl << "6 - ������ � ����" << endl << "7 - ������ �� �����" << endl 
			<< "8 - �������� ���������" << endl << "0 - ���������" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << endl;
			cin >> element;
			mult.insert(element);
			cout << endl << "������ ���������!" << endl;
			break;
		case 2:
			this->viewElements(mult);
			cout << endl << "������� ����� ������ ��� ��������:" << endl;
			cin >> num;
			it = mult.begin();
			for (int i = 0; i < num - 1; i++)
				it++;
			mult.erase(it);
			cout << endl << "������ �������!" << endl;
			break;
		case 3:
			this->viewElements(mult);
			break;
		case 4:
			this->viewElements(mult);
			cout << endl << "������� ����� ������ ��� ��������������:" << endl;
			cin >> num;
			it = mult.begin();
			for (int i = 0; i < num - 1; i++)
				it++;
			element = (*it);
			element.edit();
			mult.erase(it);
			mult.insert(element);
			cout << endl << "������ ���������������!" << endl;
			break;
		case 5:
			cout << endl;
			cin >> element;
			cout << endl;
			if (mult.find(element) == mult.end())
				cout << "\t������� �� ������!" << endl;
			else
			{
				element.tableCap();
				cout << "    " << element;
			}
			break;
		case 6:
		{
			int num, i = 0;
			cout << endl << "1 - ������ � ��������� ����" << endl << "2 - ������ � �������� ����" << endl;
			cin >> num;
			switch (num)
			{
			case 1:
				text.CleanTextFile();
				text.Remote();
				for (it = mult.begin(); it != mult.end(); it++)
				{
					element = (*it);
					text.WriteText(element, i, (int)mult.size());
					i++;
				}
				cout << endl << "������ �������� � ��������� ����!" << endl;
				break;
			case 2:
				binary.CleanBinaryFile();
				binary.Remote();
				for (it = mult.begin(); it != mult.end(); it++)
				{
					element = (*it);
					binary.WriteBinary(element);
				}
				cout << endl << "������ �������� � �������� ����!" << endl;
				break;
			}
			break;
		}
		case 7:
		{
			int num, i = 0;
			cout << endl << "1 - ������ �� ���������� �����" << endl << "2 - ������ �� ��������� �����" << endl;
			cin >> num;
			switch (num)
			{
			case 1:
				mult.clear();
				text.Remote();
				while (!text.EndFile())
				{
					i++;
					text.ReadText(element, i);
					mult.insert(element);
				}
				cout << endl << "������ ������� �� ���������� �����!" << endl;
				break;
			case 2:
				mult.clear();
				binary.Remote();
				while (binary.EndFile())
				{
					binary.ReadBinary(element);
					mult.insert(element);
				}
				cout << endl << "������ ������� �� ��������� �����!" << endl;
				break;
			}
			break;
		}
		case 8:
			mult.clear();
			cout << endl << "\t��������� ������!" << endl;
			break;
		case 0:
			flag = false;
			break;
		}
	}
}

template <class T>
void Interface<T>::viewElements(const multiset<T>& mult)
{
	if (mult.empty())
		cout << endl << "\t��������� ����!" << endl;
	else
	{
		int i = 0;
		typename multiset <T> ::iterator it;
		cout << endl;
		element.tableCap();
		for (it = mult.begin(); it != mult.end(); it++)
			cout << " " << setw(3) << left << ++i << *it;
	}
}