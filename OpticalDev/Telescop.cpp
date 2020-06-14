#include "Telescop.h"

Telescop::Telescop()
{
	type = new char[2];
	strcpy(type, "-");
	tripod = new char[2];
	strcpy(tripod, "-");
	eyep = 0; // ���������� ��������

	dLens = 0;
	focus = 0;

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
Telescop::Telescop(char* n, char* c, char* m, float cos, float v, float p, int dl, int f, char* typ, char* t, int e)
{
	try
	{
		type = nullptr;
		tripod = nullptr;
		if (eyep < 0) throw  OpticalDevEx("���������� �������� �� ����� ���� ������ 0!");
		type = new char[strlen(typ) + 1];
		strcpy(type, n);
		tripod = new char[strlen(t) + 1];
		strcpy(tripod, c);
		eyep = e;

		if (dLens < 0) throw OpticalDevEx("������� ����� �� ����� ���� ������ 0!");
		if (focus < 0) throw OpticalDevEx("����� �� ����� ���� ������ 0!");
		dLens = dl;
		focus = f;

		name = nullptr;
		color = nullptr;
		manufacturer = nullptr;
		if (cos < 0) throw OpticalDevEx("���� �� ����� ���� ������ 0!");
		if (v < 0) throw OpticalDevEx("��� �� ����� ���� ������ 0!");
		if (p < 0) throw OpticalDevEx("���� ���������� �� ����� ���� ������ 0!");
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
	catch (OpticalDevEx(e)) { cout << "������: " << e.GetError() << endl; }
}
Telescop::Telescop(const Telescop& val)
{
	type = new char[strlen(val.type) + 1];
	strcpy(type, val.type);
	tripod = new char[strlen(val.tripod) + 1];
	strcpy(tripod, val.tripod);
	eyep = val.eyep;

	dLens = val.dLens;
	focus = val.focus;

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
Telescop::~Telescop()
{
	if (type != nullptr) delete[] type;
	if (tripod != nullptr) delete[] tripod;
}
char* Telescop::getType() const { return type; }
char* Telescop::getTripod() const { return tripod; }
int Telescop::getEyep() const { return eyep; }

void Telescop::setType(char* val)
{
	type = new char[strlen(val) + 1];
	strcpy(type, val);
}
void Telescop::setTripod(char* val)
{
	tripod = new char[strlen(val) + 1];
	strcpy(tripod, val);
}
void Telescop::setEyep(int val)
{
	try
	{
		if (val <= 0) throw OpticalDevEx("���������� �������� �� ����� ���� ������ 0!");
		eyep = val;
	}
	catch (OpticalDevEx(e)) { cout << "������: " << e.GetError() << endl; }
}

void Telescop::readFromFile(char* val)
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

		File >> dLens;
		File >> focus;

		delete[] type;
		getline(File, tmp);
		type = new char[strlen(tmp.c_str()) + 1];
		strcpy(type, tmp.c_str());
		delete[] tripod;
		getline(File, tmp);
		tripod = new char[strlen(tmp.c_str()) + 1];
		strcpy(tripod, tmp.c_str());
		File >> eyep;
		File.close();
	}
}
void Telescop::writeToFile(char* val)
{
	ofstream a;
	a.open(val);
	if (a.is_open())
	{
		a << "��������: " << name << endl << "�������������: " << manufacturer << endl << "����: " << color << endl << "���������� (���): " << pover << endl << "��� (��): " << veight << endl << "���� (���): " << cost << endl;
		a << "������� ����� (��): " << dLens << endl << "�����: " << focus << endl;
		a << "��� ���������: " << type << endl << "������: " << tripod << endl << "���������� ��������: " << eyep << endl;
		a << "____________________________________________________________" << endl;
	}
}
void Telescop::enterFormKeyboard()
{
	cout << "��������: ";
	cin >> name;
	cout << "�������������: ";
	cin >> manufacturer;
	cout << "����: ";
	cin >> color;
	try
	{
		cout << "����������(���): ";
		cin >> pover;
		if (pover < 0) throw OpticalDevEx("�������������� ����������� �� ����� ���� ������ 0!");
		cout << "��� (��): ";
		cin >> veight;
		if (veight < 0) throw OpticalDevEx("��� �� ����� ���� ������ 0!");
		cout << "���� (���): ";
		cin >> cost;
		if (cost < 0) throw OpticalDevEx("���� �� ����� ���� ������ 0!");
		cout << "������� ����� (��): ";
		cin >> dLens;
		if (dLens < 0) throw OpticalDevEx("������� ����� �� ����� ���� ������ 0!");
		cout << "�����: ";
		cin >> focus;
		if (focus < 0) throw OpticalDevEx("����� �� ����� ���� ������ 0!");
		cout << "��� ���������: ";
		cin >> type;
		cout << "������: ";
		cin >> tripod;
		cout << "���������� ��������: ";
		cin >> eyep;
		if (focus < 0) throw OpticalDevEx("���������� �������� �� ����� ���� ������ 0!");
	}
	catch (OpticalDevEx(e)) { cout << "������: " << e.GetError() << endl; }
	
	cout << "____________________________________________________________" << endl;
}
void Telescop::Print()
{
	char* n = name;
	OemToCharA(name, n);
	char* m = manufacturer;
	OemToCharA(manufacturer, m);
	char* c = color;
	OemToCharA(color, c);
	char* typ = type;
	OemToCharA(type, typ);
	char* t = tripod;
	OemToCharA(tripod, t);

	cout << "��������: " << name << endl;
	cout << "�������������: " << manufacturer << endl;
	cout << "����: " << color << endl;
	cout << "���������� (���): " << pover << endl;
	cout << "��� (��): " << veight << endl;
	cout << "���� (���): " << cost << endl;
	cout << "������� ����� (��): " << dLens << endl;
	cout << "�����: " << focus << endl;
	cout << "��� ���������: "<< type << endl;
	cout << "������: " << tripod << endl;
	cout << "���������� ��������: " << eyep << endl;
	cout << "____________________________________________________________" << endl;
}