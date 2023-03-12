#include "Interface.h"

template<class T>
void Interface<T>::Menu()
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
            Interface<Electronic> electronic;
            electronic.Fun(Electronic::GetNameOfClass());
            break;
        }
        case 2:
        {
            Interface<Wrist> wrist;
            wrist.Fun(Wrist::GetNameOfClass());
            break;
        }
        case 3:
        {
            Interface<Wall> wall;
            wall.Fun(Wall::GetNameOfClass());
            break;
        }
        case 0:
            return;
        }
    }
}

template <class T>
void Interface<T>::Fun(string file_name)
{
    FileText<T>text(file_name);
    FileBinary<T>binary(file_name);

    multiset<T> clocks;
    typename multiset <T> ::iterator it;
    it = clocks.begin();

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
            clocks.insert(element);
            cout << endl << "Запись добавлена!" << endl;
            break;
        case 2:
            this->ViewElements(clocks);
            if (!clocks.empty()) {
                cout << endl << "Введите номер записи для удаления:" << endl;
                cin >> num;
                it = clocks.begin();
                for (int i = 0; i < num - 1; i++)
                    it++;
                clocks.erase(it);
                cout << endl << "Запись удалена!" << endl;
            }
            break;
        case 3:
            this->ViewElements(clocks);
            break;
        case 4:
            this->ViewElements(clocks);
            if (!clocks.empty()) {
                cout << endl << "Введите номер записи для редактирования:" << endl;
                cin >> num;
                it = clocks.begin();
                for (int i = 0; i < num - 1; i++)
                    it++;
                element = (*it);
                element.Edit();
                clocks.erase(it);
                clocks.insert(element);
                cout << endl << "Запись отредактирована!" << endl;
            }
            break;
        case 5:
            if (clocks.empty())
                cout << endl << "\tКонтейнер пуст!" << endl;
            else {
                cout << endl;
                cin >> element;
                cout << endl;
                if (clocks.find(element) == clocks.end())
                    cout << "\tЭлемент не найден!" << endl;
                else
                {
                    element.TableHeader();
                    cout << "    " << element;
                }
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
                text.Clear();
                for (it = clocks.begin(); it != clocks.end(); it++)
                {
                    element = (*it);
                    text.WriteText(element, i, (int)clocks.size());
                    i++;
                }
                cout << endl << "Данные записаны в текстовый файл!" << endl;
                break;
            case 2:
                binary.CleanBinaryFile();
                binary.Clear();
                for (it = clocks.begin(); it != clocks.end(); it++)
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
                clocks.clear();
                text.Clear();
                while (!text.EndFile())
                {
                    i++;
                    text.ReadText(element, i);
                    clocks.insert(element);
                }
                cout << endl << "Данные считаны из текстового файла!" << endl;
                break;
            case 2:
                clocks.clear();
                binary.Clear();
                while (binary.EndFile())
                {
                    binary.ReadBinary(element);
                    clocks.insert(element);
                }
                cout << endl << "Данные считаны из бинарного файла!" << endl;
                break;
            }
            break;
        }
        case 8:
            clocks.clear();
            cout << endl << "\tКонтейнер очищен!" << endl;
            break;
        case 0:
            flag = false;
            break;
        }
    }
}

template <class T>
void Interface<T>::ViewElements(const multiset<T>& clocks)
{
    if (clocks.empty())
        cout << endl << "\tКонтейнер пуст!" << endl;
    else
    {
        int i = 0;
        typename multiset <T> ::iterator it;
        cout << endl;
        element.TableHeader();
        for (it = clocks.begin(); it != clocks.end(); it++)
            cout << " " << setw(3) << left << ++i << *it;
    }
}
