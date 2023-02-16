#include "Interface.h"

template<class T>
void Interface<T>::menu()
{
	int num;

	while (1)
	{
		cout << "\tЧАСЫ" << endl << endl;
		cout << "1 - Электронные часы" << endl << "2 - Наручные часы" << endl << "3 - Настенные часы" << endl << "0 - Вернуться" << endl;
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
		cout << endl << "1 - Добавить" << endl << "2 - Удалить" << endl << "3 - Просмотр" << endl << "4 - Редактировать" << endl
			<< "5 - Поиск" << endl << "6 - Запись в файл" << endl << "7 - Чтение из файла" << endl 
			<< "8 - Очистить контейнер" << endl << "0 - Вернуться" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << endl;
			cin >> element;
			mult.insert(element);
			cout << endl << "Запись добавлена!" << endl;
			break;
		case 2:
			this->viewElements(mult);
			cout << endl << "Введите номер записи для удаления:" << endl;
			cin >> num;
			it = mult.begin();
			for (int i = 0; i < num - 1; i++)
				it++;
			mult.erase(it);
			cout << endl << "Запись удалена!" << endl;
			break;
		case 3:
			this->viewElements(mult);
			break;
		case 4:
			this->viewElements(mult);
			cout << endl << "Введите номер записи для редактирования:" << endl;
			cin >> num;
			it = mult.begin();
			for (int i = 0; i < num - 1; i++)
				it++;
			element = (*it);
			element.edit();
			mult.erase(it);
			mult.insert(element);
			cout << endl << "Запись отредактирована!" << endl;
			break;
		case 5:
			cout << endl;
			cin >> element;
			cout << endl;
			if (mult.find(element) == mult.end())
				cout << "\tЭлемент не найден!" << endl;
			else
			{
				element.tableCap();
				cout << "    " << element;
			}
			break;
		case 6:
		{
			int num, i = 0;
			cout << endl << "1 - Запись в текстовый файл" << endl << "2 - Запись в бинарный файл" << endl;
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
				cout << endl << "Данные записаны в текстовый файл!" << endl;
				break;
			case 2:
				binary.CleanBinaryFile();
				binary.Remote();
				for (it = mult.begin(); it != mult.end(); it++)
				{
					element = (*it);
					binary.WriteBinary(element);
				}
				cout << endl << "Данные записаны в бинарный файл!" << endl;
				break;
			}
			break;
		}
		case 7:
		{
			int num, i = 0;
			cout << endl << "1 - Чтение из текстового файла" << endl << "2 - Чтение из бинарного файла" << endl;
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
				cout << endl << "Данные считаны из текстового файла!" << endl;
				break;
			case 2:
				mult.clear();
				binary.Remote();
				while (binary.EndFile())
				{
					binary.ReadBinary(element);
					mult.insert(element);
				}
				cout << endl << "Данные считаны из бинарного файла!" << endl;
				break;
			}
			break;
		}
		case 8:
			mult.clear();
			cout << endl << "\tКонтейнер очищен!" << endl;
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
		cout << endl << "\tКонтейнер пуст!" << endl;
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