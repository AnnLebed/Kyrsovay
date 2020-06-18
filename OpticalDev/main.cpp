#include <locale.h>
#include <iostream>
#include "OptocalDevInterFace.h"
#include "Stack.h"
#include "OpticalDev.h"
#include "OplicationDevEx.h"
#include "Long.h"
#include "Telescop.h"
#include "Camera.h"
#include "Auto.h"
#include "NotAuto.h"
#include "Near.h"
#include "Magnifier.h"
#include "Microscope.h"
using namespace std;
template <class T>
bool SortPrice(const T& c1, const T& c2) // внешняя функция используемая для сортировки по цене
{
	if (c1->getCost() < c2->getCost()) return true;
	else false;
}

template <class T>
bool SortName(const T& c1, const T& c2) // внешняя функция используемая для сортировки по имени
{
	if (c1->getName() < c2->getName()) return true;
	else false;
}

template <class T>
bool SortPover(const T& val1, const T& val2) // внешняя функция используемая для сортировки по увеличительной способности
{
	if (val1->getPover() < val2->getPover()) return true;
	else false;
}

template <class T>
bool FindName(string val, const T& tmp) // внешнаяя функция, используема я для поиска объекта по имени 
{
	if (val == tmp->getName()) return true;
	return false;
}

int main()
{
	setlocale(0, "");
	int ch1, ch2;
	string tmp;
	cout << "Введите размер Стека: ";
	cin >> ch1;
	Stack <OpticalDevInterFace* > st (ch1);
	while (true)
	{
			cout << "Выберите действие: " << endl;
			cout << "1 - Добавить объект" << endl << "2 - Удалить последний объект" << endl << "3 - Вывод полной информации об объекте " << endl << "4 - Сортировка объектов" << endl << "5 - Поиск объекта по имени" << endl << "6 - Запись в файл" << endl << "7 - Выход из программы" << endl;
			cin >> ch1;
			try {
				if (ch1 <= 0 || ch1 > 7) throw OpticalDevEx::OpticalDevEx("Такого действия не существует.");
			system("cls");
			switch (ch1)
			{ 
			case 1:
				cout << "Выберите способ добавления: " << endl;
				cout << "1 - Ввод из файла" << endl << "2 - Создание стандартного объекта" << endl << "3 - Ввод с клавиатуры" << endl << "4 - Назад" << endl;
				cin >> ch1;
				switch (ch1)
				{
				case 1:
					cout << "Введите путь до файла: ";
					cin >> tmp;
					cout << "Вырите класс, к которому принадлежит файл:" << endl;
					cout << "1 - Оптичские приборы" << endl << "2 - Оптические приборы ближнего действия " << endl << "3 - Микроскопы " << endl << "4 - Лупа " << endl << "5 - Оптические приборы дальнего действия" << endl << "6 - Телескоп " << endl << "7 - Фотоаппарат" << endl << "8 - Неавтоматические фотоаппарты  " << endl << "9 - Автоматические фотоаппараты" << endl << "10 - Назад " << endl;
					cin >> ch2;
					switch (ch2)
					{
					case 1:
						st.push(new OpticalDev());
						st[st.Length() - 1]->readFromFile((char*)tmp.c_str());
						break;
					case 2:
						st.push(new Near());
						st[st.Length() - 1]->readFromFile((char*)tmp.c_str());
						break;
					case 3:
						st.push(new Microscope());
						st[st.Length() - 1]->readFromFile((char*)tmp.c_str());
						break;
					case 4:
						st.push(new Magnifier());
						st[st.Length() - 1]->readFromFile((char*)tmp.c_str());
						break;
					case 5:
						st.push(new Long());
						st[st.Length() - 1]->readFromFile((char*)tmp.c_str());
						break;
					case 6:
						st.push(new Telescop());
						st[st.Length() - 1]->readFromFile((char*)tmp.c_str());
						break;
					case 7:
						st.push(new Camera());
						st[st.Length() - 1]->readFromFile((char*)tmp.c_str());
						break;
					case 8:
						st.push(new NotAuto());
						st[st.Length() - 1]->readFromFile((char*)tmp.c_str());
						break;
					case 9:
						st.push(new Auto());
						st[st.Length() - 1]->readFromFile((char*)tmp.c_str());
						break;
					case 10:
						break;
					}
					break;
				case 2:
					cout << "Вырите класс, к которому принадлежит файл:" << endl;
					cout << "1 - Оптичские приборы" << endl << "2 - Оптические приборы ближнего действия " << endl << "3 - Микроскопы " << endl << "4 - Лупа " << endl << "5 - Оптические приборы дальнего действия" << endl << "6 - Телескоп " << endl << "7 - Фотоаппарат" << endl << "8 - Неавтоматические фотоаппарты  " << endl << "9 - Автоматические фотоаппараты" << endl << "10 - Назад " << endl;
					cin >> ch2;
					switch (ch2)
					{
					case 1:
						st.push(new OpticalDev());
						break;
					case 2:
						st.push(new Near());
						break;
					case 3:
						st.push(new Microscope());
						break;
					case 4:
						st.push(new Magnifier());
						break;
					case 5:
						st.push(new Long());
						break;
					case 6:
						st.push(new Telescop());
						break;
					case 7:
						st.push(new Camera());
						break;
					case 8:
						st.push(new NotAuto());
						break;
					case 9:
						st.push(new Auto());
						break;
					case 10:
						break;
					}
					break;
				case 3:
					cout << "Выберите класс для работы: " << endl;
					cout << "1 - Оптичские приборы" << endl << "2 - Оптические приборы ближнего действия " << endl << "3 - Микроскопы " << endl << "4 - Лупа " << endl << "5 - Оптические приборы дальнего действия" << endl << "6 - Телескоп " << endl << "7 - Фотоаппарат" << endl << "8 - Неавтоматические фотоаппарты  " << endl << "9 - Автоматические фотоаппараты" << endl << "10 - Назад " << endl;
					cin >> ch2;
					switch (ch2)
					{
					case 1:
						st.push(new OpticalDev());
						st[st.Length() - 1]->enterFormKeyboard();
						break;
					case 2:
						st.push(new Near());
						st[st.Length() - 1]->enterFormKeyboard();
						break;
					case 3:
						st.push(new Microscope());
						st[st.Length() - 1]->enterFormKeyboard();
						break;
					case 4:
						st.push(new Magnifier());
						st[st.Length() - 1]->enterFormKeyboard();
						break;
					case 5:
						st.push(new Long());
						st[st.Length() - 1]->enterFormKeyboard();
						break;
					case 6:
						st.push(new Telescop());
						st[st.Length() - 1]->enterFormKeyboard();
						break;
					case 7:
						st.push(new Camera());
						st[st.Length() - 1]->enterFormKeyboard();
						break;
					case 8:
						st.push(new NotAuto());
						st[st.Length() - 1]->enterFormKeyboard();
						break;
					case 9:
						st.push(new Auto());
						st[st.Length() - 1]->enterFormKeyboard();
						break;
					case 10:
						break;
					}
				case 4:
					break;
				}
				break;
			case 2:
				st.pop();
				cout << "Стек: " << endl;
				for (int i = 0; i < st.Length(); i++)
				{
					cout << "[" << i+1  << "] - " << st[i]->getName() << endl;
				}
				cout << "Длина стека: " << st.Length() << endl;
				break;
			case 3:
				cout << "Всего в стеке " << st.Length() << " элементов. Введите номер нужного объекта: ";
				cin >> ch1;
				try
				{
					if (ch1 < 0 || ch1 > st.Length()) throw OpticalDevEx("Такого номера объекта не существует");
					st[ch1 - 1]->Print();
				}
				catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
				cout << endl << endl;
				break;
			case 4:
				cout << "Выберите способ сортировки: " << endl;
				cout << "1 - По названию" << endl << "2 - По цене" << endl << "3 - По увеличительной способности" << endl << "4 - Назад" << endl;
				cin >> ch2;
				switch (ch2)
				{
				case 1:
					st.Sort(SortName);
					cout << "Стек: " << endl;
					for (int i = 0; i < st.Length(); i++)
					{
						cout << st[i]->getName() << endl;
					}
					break;
				case 2:
					st.Sort(SortPrice);
					cout << "Стек: " << endl;
					for (int i = 0; i < st.Length(); i++)
					{
						cout << st[i]->getCost() << endl;
					}
					break;
				case 3:
					st.Sort(SortPover);
					cout << "Стек: " << endl;
					for (int i = 0; i < st.Length(); i++)
					{
						cout << st[i]->getPover() << endl;
					}
					break;
				case 4:
					system("cls");
					break;
				}
				cout << endl << endl;
				break;
			case 5:
			{cout << "Введите название для поиска (вывод первого подходящего): ";
			cin >> tmp;
			OpticalDevInterFace** temp = st.Search(tmp, FindName);
			if (temp == nullptr) cout << "Данного элемента не найдено" << endl;
			else { cout << "Элемент найден: " << endl; (*temp)->Print(); }}
			cout << endl << endl;
			break;
			case 6:
				cout << "Укажите номер объекта, который необходимо записать в файл: ";
				cin >> ch1;
				try
				{
					if ((ch1-1) < 0 || (ch1-1) > st.Length()) throw OpticalDevEx("Такого номера объекта не существует");
					st[ch1 - 1]->Print();
					cout << "Укажите путь для сохранения файла: ";
					cin >> tmp;
					st[ch1 - 1]->writeToFile((char*)tmp.c_str());
					cout << "Файл сохранён!" << endl << endl;
				}
				catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
				break;
			case 7:
				exit(0);
			}
		}
		catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
	}
}