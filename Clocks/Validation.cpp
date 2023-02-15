#include "ExceptionInput.h"

char* validationCheckStr(istream& in)
{
	rewind(stdin);
	char* str = new char[20];
	bool flag;
	do
	{
		try
		{
			flag = false;
			in.getline(str, 20);
			//in >> str;
			for (int i = 0; str[i]; i++)
				if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] == ' '))
					throw Exception("�������� ����! ������� ������, ��������� ������ ��������� �������, ��������� � ��������� �������!");
		}
		catch (Exception ob)
		{
			flag = true;
			ob.show();
			rewind(stdin);
		}

	} while (flag);
	return str;
}

char* validationCheckPas(istream& in)
{
	rewind(stdin);
	char* str = new char[20];
	bool flag;
	do
	{
		try
		{
			flag = false;
			//in >> str;
			in.getline(str, 20);
			for (int i = 0; str[i]; i++)
				if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9'))
					throw Exception("�������� ����! ������� ������, ��������� ������ ��������� �������, ���������, ��������� ������� � �����!");
		}
		catch (Exception ob)
		{
			flag = true;
			ob.show();
			rewind(stdin);
		}
	} while (flag);
	return str;
}

int validationCheckInt(istream& in, int min, int max)
{
	int num;
	bool flag;
	do
	{
		try
		{
			flag = false;
			in >> num;
			if (!in || (in.peek()) != '\n')
				throw ExceptionInput(1, "�������� ����! ������� ������, ��������� ������ �����!");
			if (num < min || num > max)
				throw ExceptionInput(2, "�������� ����! ����� �� ������� ���������� ��������!");
		}
		catch (ExceptionInput ob)
		{
			flag = true;
			in.clear();
			rewind(stdin);
			ob.showKod();
		}
		catch (...)
		{
			flag = true;
			cout << "�������� ����������� ���������!" << endl;
		}
	} while (flag);
	return num;
}