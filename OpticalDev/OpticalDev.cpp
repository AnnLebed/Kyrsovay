#include "OpticalDev.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// базовый класс Оптические приборы.  Предназначен для работы с оптическими приборами

OpticalDev::OpticalDev()
{
	name = new char[2];
	strcpy(name, "-");
	color = new char[2];
	strcpy(color, "-");
	manufacturer = new char[2];
	strcpy(manufacturer, "-");
	cost = 0;
	veight = 0;
	pover = 0;
}

OpticalDev::OpticalDev(char* n, char* c, char* m, float cos, float v, float p)
{
	try
	{
		name = nullptr;
		color = nullptr;
		manufacturer = nullptr;
		if (cos < 0) throw OpticalDevEx("Цена не может быть меньше 0!");
		if (v < 0) throw OpticalDevEx("Вес не может быть меньше 0!");
		if (p < 0) throw OpticalDevEx("Сила увеличения не может быть меньше 0!");
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		color = new char[strlen(c) + 1];
		strcpy(color, c);
		manufacturer = new char[strlen(m) + 1];
		strcpy(manufacturer, m);
		cost = cos;
		veight = v;
		pover = p;
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
}

OpticalDev::OpticalDev(const OpticalDev& val)
{
	name = new char[strlen(val.name) + 1];
	strcpy(name, val.name);
	color = new char[strlen(val.color) + 1];
	strcpy(color, val.color);
	manufacturer = new char[strlen(val.manufacturer) + 1];
	strcpy(manufacturer, val.manufacturer);
	cost = val.cost;
	veight = val.veight;
	pover = val.pover;
}

OpticalDev::~OpticalDev()
{
	if (name != nullptr) delete[] name;
	if (color != nullptr) delete[] color;
	if (manufacturer != nullptr) delete[] manufacturer;
}

char* OpticalDev::getName() const { return name; }
char* OpticalDev::getColor() const { return color; }
char* OpticalDev::getManuf() const { return manufacturer; }
float OpticalDev::getCost() const { return cost; }
float OpticalDev::getVeight() const { return veight; }
float OpticalDev::getPover() const { return pover; }

void OpticalDev::setName(char* val)
{
	name = new char[strlen(val) + 1]; 
	strcpy(name, val);
}
void OpticalDev::setColor(char* val)
{
	color = new char[strlen(val) + 1];
	strcpy(color, val);
}
void OpticalDev::setManuf(char* val)
{
	manufacturer = new char[strlen(val) + 1];
	strcpy(manufacturer, val);
}
void OpticalDev::setCost(float val)
{
	try 
	{
		if(val < 0) throw OpticalDevEx ("Цена не может быть меньше 0!");
		cost = val;
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
}
void OpticalDev::setVeight(float val)
{
	try
	{
		if (val < 0) throw OpticalDevEx("Вес не может быть меньше 0!");
		veight = val;
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
}
void OpticalDev::setPover(float val)
{
	try
	{
		if (val < 0) throw OpticalDevEx("Увеличительная способность не может быть меньше 0!");
		pover = val;
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
}

void OpticalDev::readFromFile(char* val)
{
	ifstream File;
	File.open(val);
	if (File.is_open())
	{
		string tmp;
		delete[] name;
		getline(File, tmp);
		name = new char[strlen(tmp.c_str()) + 1];
		strcpy(name, tmp.c_str());

		delete[] manufacturer;
		getline(File, tmp);
		manufacturer = new char[strlen(tmp.c_str()) + 1];
		strcpy(manufacturer, tmp.c_str());

		delete[] color;
		getline(File, tmp);
		color = new char[strlen(tmp.c_str()) + 1];
		strcpy(color, tmp.c_str());
		
		File >> pover;
		File >> veight;
		File >> cost;
		File.close();
	}
}
void OpticalDev::writeToFile(char* val)
{
	ofstream a;
	a.open(val);
	if (a.is_open())
	{
		a << "Название: " <<  name << endl << "Производитель: " << manufacturer << endl << "Цвет: " << color << endl <<"Увеличение (раз): "<< pover << endl <<  "Вес (кг): " << veight << endl  << "Цена (руб): "<< cost << endl;
		a << "____________________________________________________________" << endl;
	}
}
void OpticalDev::enterFormKeyboard()
{
	cout << "Название: ";
	cin >> name;
	cout << "Производитель: ";
	cin >> manufacturer;
	cout << "Цвет: ";
	cin >> color;
	try
	{
		cout << "Увеличение(раз): ";
		cin >> pover;
		if (pover < 0) throw OpticalDevEx("Увеличительная способность не может быть меньше 0!");
		cout << "Вес (кг): ";
		cin >> veight;
		if (veight < 0) throw OpticalDevEx("Вес не может быть меньше 0!");
		cout << "Цена (руб): ";
		cin >> cost;
		if (cost < 0) throw OpticalDevEx("Цена не может быть меньше 0!");
		
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
	cout << "____________________________________________________________" << endl;
}
void OpticalDev::Print()
{
	char* n = name;
	OemToCharA(name,n);
	char* m = manufacturer;
	OemToCharA(manufacturer, m);
	char* c = color;
	OemToCharA(color, c);
	
	cout << "Название: " << name << endl;
	cout << "Производитель: " << manufacturer << endl;
	cout << "Цвет: " << color << endl;
	cout << "Увеличение: " << pover << endl;
	cout << "Вес: " << veight << endl;
	cout << "Цена: " << cost << endl;
	cout << "____________________________________________________________" << endl;
}