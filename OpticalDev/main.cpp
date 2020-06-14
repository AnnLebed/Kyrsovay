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
bool SortPrice(const T& c1, const T& c2)
{
	if (c1->getCost() < c2->getCost()) return true;
	else false;
}

template <class T>
bool SortName(const T& c1, const T& c2)
{
	if (c1->getName() < c2->getName()) return true;
	else false;
}

template <class T>
bool SortPover(const T& val1, const T& val2)
{
	if (val1->getPover() < val2->getPover()) return true;
	else false;
}

template <class T>
bool FindName(string val, const T& tmp)
{
	if (val == tmp->getName()) return true;
	return false;
}

int main()
{
	setlocale(0, "");
	int ch1, ch2;
	string tmp;
	cout << "������� ������ �����: ";
	cin >> ch1;
	Stack <OpticalDevInterFace* > st (ch1);
	while (true)
	{
			cout << "�������� ��������: " << endl;
			cout << "1 - �������� ������" << endl << "2 - ������� ��������� ������" << endl << "3 - ����� ������ ���������� �� ������� " << endl << "4 - ���������� ��������" << endl << "5 - ����� ������� �� �����" << endl << "6 - ������ � ����" << endl << "7 - ����� �� ���������" << endl;
			cin >> ch1;
			try {
				if (ch1 <= 0 || ch1 > 7) throw OpticalDevEx::OpticalDevEx("������ �������� �� ����������.");
			system("cls");
			switch (ch1)
			{ 
			case 1:
				cout << "�������� ������ ����������: " << endl;
				cout << "1 - ���� �� �����" << endl << "2 - �������� ������������ �������" << endl << "3 - ���� � ����������" << endl << "4 - �����" << endl;
				cin >> ch1;
				switch (ch1)
				{
				case 1:
					cout << "������� ���� �� �����: ";
					cin >> tmp;
					cout << "������ �����, � �������� ����������� ����:" << endl;
					cout << "1 - ��������� �������" << endl << "2 - ���������� ������� �������� �������� " << endl << "3 - ���������� " << endl << "4 - ���� " << endl << "5 - ���������� ������� �������� ��������" << endl << "6 - �������� " << endl << "7 - �����������" << endl << "8 - ���������������� �����������  " << endl << "9 - �������������� ������������" << endl << "10 - ����� " << endl;
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
					cout << "������ �����, � �������� ����������� ����:" << endl;
					cout << "1 - ��������� �������" << endl << "2 - ���������� ������� �������� �������� " << endl << "3 - ���������� " << endl << "4 - ���� " << endl << "5 - ���������� ������� �������� ��������" << endl << "6 - �������� " << endl << "7 - �����������" << endl << "8 - ���������������� �����������  " << endl << "9 - �������������� ������������" << endl << "10 - ����� " << endl;
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
					cout << "�������� ����� ��� ������: " << endl;
					cout << "1 - ��������� �������" << endl << "2 - ���������� ������� �������� �������� " << endl << "3 - ���������� " << endl << "4 - ���� " << endl << "5 - ���������� ������� �������� ��������" << endl << "6 - �������� " << endl << "7 - �����������" << endl << "8 - ���������������� �����������  " << endl << "9 - �������������� ������������" << endl << "10 - ����� " << endl;
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
				cout << "����: " << endl;
				for (int i = 0; i < st.Length(); i++)
				{
					cout << "[" << i+1  << "] - " << st[i]->getName() << endl;
				}
				cout << "����� �����: " << st.Length() << endl;
				break;
			case 3:
				cout << "����� � ����� " << st.Length() << " ���������. ������� ����� ������� �������: ";
				cin >> ch1;
				try
				{
					if (ch1 < 0 || ch1 > st.Length()) throw OpticalDevEx("������ ������ ������� �� ����������");
					st[ch1 - 1]->Print();
				}
				catch (OpticalDevEx(e)) { cout << "������: " << e.GetError() << endl; }
				cout << endl << endl;
				break;
			case 4:
				cout << "�������� ������ ����������: " << endl;
				cout << "1 - �� ��������" << endl << "2 - �� ����" << endl << "3 - �� �������������� �����������" << endl << "4 - �����" << endl;
				cin >> ch2;
				switch (ch2)
				{
				case 1:
					st.Sort(SortName);
					cout << "����: " << endl;
					for (int i = 0; i < st.Length(); i++)
					{
						cout << st[i]->getName() << endl;
					}
					break;
				case 2:
					st.Sort(SortPrice);
					cout << "����: " << endl;
					for (int i = 0; i < st.Length(); i++)
					{
						cout << st[i]->getCost() << endl;
					}
					break;
				case 3:
					st.Sort(SortPover);
					cout << "����: " << endl;
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
			{cout << "������� �������� ��� ������ (����� ������� �����������): ";
			cin >> tmp;
			OpticalDevInterFace** temp = st.Search(tmp, FindName);
			if (temp == nullptr) cout << "������� �������� �� �������" << endl;
			else { cout << "������� ������: " << endl; (*temp)->Print(); }}
			cout << endl << endl;
			break;
			case 6:
				cout << "������� ����� �������, ������� ���������� �������� � ����: ";
				cin >> ch1;
				try
				{
					if ((ch1-1) < 0 || (ch1-1) > st.Length()) throw OpticalDevEx("������ ������ ������� �� ����������");
					st[ch1 - 1]->Print();
					cout << "������� ���� ��� ���������� �����: ";
					cin >> tmp;
					st[ch1 - 1]->writeToFile((char*)tmp.c_str());
					cout << "���� �������!" << endl << endl;
				}
				catch (OpticalDevEx(e)) { cout << "������: " << e.GetError() << endl; }
				break;
			case 7:
				exit(0);
			}
		}
		catch (OpticalDevEx(e)) { cout << "������: " << e.GetError() << endl; }
	}
}