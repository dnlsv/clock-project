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
					throw Exception("Неверный ввод! Введите заново, используя только латинский алфавит, заглавные и прописные символы!");
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
					throw Exception("Неверный ввод! Введите заново, используя только латинский алфавит, заглавные, прописные символы и цифры!");
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
				throw ExceptionInput(1, "Неверный ввод! Введите заново, используя только цифры!");
			if (num < min || num > max)
				throw ExceptionInput(2, "Неверный ввод! Выход за пределы допустимых значений!");
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
			cout << "Возникло неожиданное исклюение!" << endl;
		}
	} while (flag);
	return num;
}