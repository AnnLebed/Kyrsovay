#include "NotAuto.h"

NotAuto::NotAuto()
{
	addMit = new char[2];
	strcpy(addMit, "-");
	
	outBreak = new char[2];
	strcpy(outBreak, "-");
	exposure = 0;

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
NotAuto::NotAuto(char* n, char* c, char* m, float cos, float v, float p, int dl, int f, char* ob, int ex, char* a)
{
	try
	{
		addMit = nullptr;
		addMit = new char[strlen(a) + 1];
		strcpy(addMit, a);
		
		outBreak = nullptr;
		if (exposure < 0) throw  OpticalDevEx("�������� �� ����� ���� ������ 0!");
		outBreak = new char[strlen(ob) + 1];
		strcpy(outBreak, ob);
		exposure = ex;

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
NotAuto::NotAuto(const NotAuto& val)
{
	addMit = new char[strlen(val.addMit) + 1];
	strcpy(addMit, val.addMit);
	
	outBreak = new char[strlen(val.outBreak) + 1];
	strcpy(outBreak, val.outBreak);
	exposure = val.exposure;

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
NotAuto::~NotAuto()
{
	if (addMit != nullptr) delete[] addMit;
}
char* NotAuto::getAddMit() const { return addMit; }

void NotAuto::setAddMit(char* val)
{
	addMit = new char[strlen(val) + 1];
	strcpy(addMit, val);
}
void NotAuto::readFromFile(char* val)
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

		delete[] outBreak;
		getline(File, tmp);
		outBreak = new char[strlen(tmp.c_str()) + 1];
		strcpy(outBreak, tmp.c_str());
		File >> exposure;

		delete[] addMit;
		getline(File, tmp);
		addMit = new char[strlen(tmp.c_str()) + 1];
		strcpy(addMit, tmp.c_str());
		File.close();

	}
}
void NotAuto::writeToFile(char* val)
{
	ofstream a;
	a.open(val);
	if (a.is_open())
	{
		a << "��������: " << name << endl << "�������������: " << manufacturer << endl << "����: " << color << endl << "���������� (���): " << pover << endl << "��� (��): " << veight << endl << "���� (���): " << cost << endl;
		a << "������� ����� (��): " << dLens << endl << "�����: " << focus << endl;
		a << "�������: " << outBreak << endl << "��������: " << exposure << endl;
		a << "�������������� ���������: " << addMit << endl;
		a << "____________________________________________________________" << endl;
	}
}
void NotAuto::enterFormKeyboard()
{
	try
	{
		cout << "��������: ";
		cin >> name;
		cout << "�������������: ";
		cin >> manufacturer;
		cout << "����: ";
		cin >> color;
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
		cout << "�������: ";
		cin >> outBreak;
		cout << "��������: ";
		cin >> exposure;
		if (exposure < 0) throw OpticalDevEx("�������� �� ����� ���� ������ 0!");
		cout << "�������������� ���������: ";
		cin >> addMit;
	}
	catch (OpticalDevEx(e)) { cout << "������: " << e.GetError() << endl; }
	cout << "____________________________________________________________" << endl;

}
void NotAuto::Print()
{
	char* n = name;
	OemToCharA(name, n);
	char* m = manufacturer;
	OemToCharA(manufacturer, m);
	char* c = color;
	OemToCharA(color, c);



	cout << "��������: " << name << endl;
	cout << "�������������: " << manufacturer << endl;
	cout << "����: " << color << endl;
	cout << "����������: " << pover << endl;
	cout << "���: " << veight << endl;
	cout << "����: " << cost << endl;
	cout << "������� �����: " << dLens << endl;
	cout << "�����: " << focus << endl;
	cout << "�������: " << outBreak << endl;
	cout << "��������: " << exposure << endl;
	cout << "�������������� ���������: " << addMit << endl;
	cout << "____________________________________________________________" << endl;
}