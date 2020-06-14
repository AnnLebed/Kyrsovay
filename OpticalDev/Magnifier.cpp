#include "Magnifier.h"

Magnifier::Magnifier()
{
	form = new char[2];
	strcpy(form, "-");
	materialLinz = new char[2];
	strcpy(materialLinz, "-");
	
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
Magnifier::Magnifier(char* n, char* c, char* m, float cos, float v, float p, float r, char* f, char*mlinz)
{
	try
	{
		form = nullptr;
		materialLinz = nullptr;
		form = new char[strlen(f) + 1];
		strcpy(form, f);
		materialLinz = new char[strlen(mlinz) + 1];
		strcpy(materialLinz, mlinz);

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
Magnifier::Magnifier(const Magnifier& val)
{
	form = new char[strlen(val.form) + 1];
	strcpy(form, val.form);
	materialLinz = new char[strlen(val.materialLinz) + 1];
	strcpy(materialLinz, val.materialLinz);

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
Magnifier::~Magnifier()
{
	if (form != nullptr) delete[] form;
	if (materialLinz != nullptr) delete[] materialLinz;
}
char* Magnifier::getForm() const { return form; }
char* Magnifier::getMatLinz() const { return materialLinz; }
void Magnifier::setForm(char* val)
{
	form = new char[strlen(val) + 1];
	strcpy(form, val);
}
void Magnifier::setMatLinz(char* val)
{
	materialLinz = new char[strlen(val) + 1];
	strcpy(materialLinz, val);
}
void Magnifier::readFromFile(char* val)
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

		delete[] form;
		getline(File, tmp);
		form = new char[strlen(tmp.c_str()) + 1];
		strcpy(form, tmp.c_str());
		delete[] materialLinz;
		getline(File, tmp);
		materialLinz = new char[strlen(tmp.c_str()) + 1];
		strcpy(materialLinz, tmp.c_str());
		File.close();
	}
}
void Magnifier::writeToFile(char* val)
{
	ofstream a;
	a.open(val);
	if (a.is_open())
	{
		a << "Название: " << name << endl << "Производитель: " << manufacturer << endl << "Цвет: " << color << endl << "Увеличение (раз): " << pover << endl << "Вес (кг): " << veight << endl << "Цена (руб): " << cost << endl;
		a << "Разрешающая спостобность: " << resolution << endl;
		a << "Форма линзы: " << form << endl << "Материал линзы:  " << materialLinz << endl;
		a << "____________________________________________________________" << endl;
	}
}
void Magnifier::enterFormKeyboard()
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
		cout << "Форма линзы: ";
		cin >> form; 
		cout << "Материал линзы: ";
		cin >> materialLinz;	
	}
	catch (OpticalDevEx(e)) { cout << "Ошибка: " << e.GetError() << endl; }
	cout << "____________________________________________________________" << endl;
}
void Magnifier::Print()
{
	char* n = name;
	OemToCharA(name, n);
	char* m = manufacturer;
	OemToCharA(manufacturer, m);
	char* c = color;
	OemToCharA(color, c);
	char* f = form;
	OemToCharA(form, f);
	char* ml = materialLinz;
	OemToCharA(materialLinz, ml);

	cout << "Название: " << name << endl;
	cout << "Производитель: " << manufacturer << endl;
	cout << "Цвет: " << color << endl;
	cout << "Увеличение (раз): " << pover << endl;
	cout << "Вес (кг): " << veight << endl;
	cout << "Цена (руб): " << cost << endl;
	cout << "Разрешающая спостобность: " << resolution << endl;
	cout << "Форма линзы: " << form << endl;
	cout << "Материал линзы: " << materialLinz << endl;
	cout << "____________________________________________________________" << endl;
}