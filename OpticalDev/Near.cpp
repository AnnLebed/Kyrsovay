#include "Near.h"

// класс Ближнего действия, унаследованный от Оптических приборов.  Предназначен для работы с оптическими приборами ближнего действия

Near::Near()
{
	resolution = 0;

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
Near::Near(char* n, char* c, char* m, float cos, float v, float p, float r)
{
	try
	{
		if (resolution <= 0) throw OpticalDevEx("Разрешающая способность не может быть меньше 0!");
		resolution = r;

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
Near::Near (const Near& val)
{
	resolution = val.resolution;

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
Near::~Near(){}

float Near::getResolution() const { return resolution; }

void Near::setResolution(float val)
{
	try
	{
		if (val <= 0) throw OpticalDevEx ("Разрешающая способность не может быть меньше 0!");
		resolution = val;
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
}
void Near::readFromFile(char* val)
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

		File >> resolution;
		File.close();
	}
}
void Near::writeToFile(char* val)
{
	ofstream a;
	a.open(val);
	if (a.is_open())
	{
		a << "Название: " << name << endl << "Производитель: " << manufacturer << endl << "Цвет: " << color << endl << "Увеличение (раз): " << pover << endl << "Вес (кг): " << veight << endl << "Цена (руб): " << cost << endl;
		a << "Разрешающая спостобность: " << resolution << endl;
		a << "____________________________________________________________" << endl;
	}
}
void Near::enterFormKeyboard()
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
		cout << "Разрешающая спостобность: ";
		cin >> resolution;
		if (resolution < 0) throw OpticalDevEx("Разрешающая способность не может быть меньше 0!");
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
	cout << "____________________________________________________________" << endl;
}
void Near::Print()
{
	char* n = name;
	OemToCharA(name, n);
	char* m = manufacturer;
	OemToCharA(manufacturer, m);
	char* c = color;
	OemToCharA(color, c);


	cout << "Название: " << name << endl;
	cout << "Производитель: " << manufacturer << endl;
	cout << "Цвет: " << color << endl;
	cout << "Увеличение (раз): " << pover << endl;
	cout << "Вес (кг): " << veight << endl;
	cout << "Цена (руб): " << cost << endl;
	cout << "Разрешающая спостобность: " << resolution << endl;
	cout << "____________________________________________________________" << endl;
}