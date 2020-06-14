#include "Auto.h"

Auto::Auto()
{
	video = new char[2];
	strcpy(video, "-");
	USB = 0;
	speedShoot = 0;

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
Auto::Auto(char* n, char* c, char* m, float cos, float v, float p, int dl, int f, char* ob, int ex, char* vid, float U, int sSh)
{
	try
	{
		video = nullptr;
		if (USB < 0)throw  OpticalDevEx("USB �� ����� ���� ������ 0!");
		if (speedShoot < 0)throw  OpticalDevEx("�������� ������ �� ����� ���� ������ 0!");
		video = new char[strlen(vid) + 1];
		strcpy(video, vid);
		USB = U;
		speedShoot = sSh;

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
Auto::Auto(const Auto& val)
{
	video = new char[strlen(val.video) + 1];
	strcpy(video, val.video);
	USB = val.USB;
	speedShoot = val.speedShoot;

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
Auto::~Auto()
{
	if (video != nullptr) delete[] video;
}
char* Auto::getVideo() const { return video; }
float Auto::getUSB() const { return USB; }
int Auto::getSpeedSh() const { return speedShoot; }

void Auto::setVideo(char* val)
{
	video = new char[strlen(val) + 1];
	strcpy(video, val);
}
void Auto::setSpeedSh(int val)
{
	try
	{
		if (val <= 0) throw OpticalDevEx("�������� ������ �� ����� ���� ������ 0!");
		speedShoot = val;
	}
	catch (OpticalDevEx(e)) { cout << "������: " << e.GetError() << endl; }
}
void Auto::setUSB(float val)
{
	try
	{
		if (val <= 0) throw OpticalDevEx("�������� �� ����� ���� ������ 0!");
		USB = val;
	}
	catch (OpticalDevEx(e)) { cout << "������: " << e.GetError() << endl; }
}
void Auto::readFromFile(char* val)
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
		
		delete[] video;
		getline(File, tmp);
		video = new char[strlen(tmp.c_str()) + 1];
		strcpy(video, tmp.c_str());
		File >> speedShoot;
		File >> USB;
		File.close();
	}
}
void Auto::writeToFile(char* val)
{
	ofstream a;
	a.open(val);
	if (a.is_open())
	{
		a << "��������: " << name << endl << "�������������: " << manufacturer << endl << "����: " << color << endl << "���������� (���): " << pover << endl << "��� (��): " << veight << endl << "���� (���): " << cost << endl;
		a << "������� ����� (��): " << dLens << endl << "�����: " << focus << endl;
		a << "�������: " << outBreak << endl << "��������: " << exposure << endl;
		a << "�����: " << video << endl << "�������� ������ (����/���): " << speedShoot << endl << "USB: " << USB << endl;
		a << "____________________________________________________________" << endl;
	}
}
void Auto::enterFormKeyboard()
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
		cout << "�������: ";
		cin >> outBreak;
		cout << "��������: ";
		cin >> exposure;
		if (exposure < 0) throw OpticalDevEx("�������� �� ����� ���� ������ 0!");
		cout << "�����: ";
		cin >> video;
		cout << "�������� ������ (����/���): ";
		cin >> speedShoot;
		if (exposure < 0) throw OpticalDevEx("�������� ������ �� ����� ���� ������ 0!");
		cout << "USB: ";
		cin >> USB;
		if (exposure < 0) throw OpticalDevEx("USB �� ����� ���� ������ 0!");
	}
	catch (OpticalDevEx(e)) { cout << "������: " << e.GetError() << endl; }
	cout << "____________________________________________________________" << endl;
}
void Auto::Print()
{
	char* n = name;
	OemToCharA(name, n);
	char* m = manufacturer;
	OemToCharA(manufacturer, m);
	char* c = color;
	OemToCharA(color, c);
	char* ob = outBreak;
	OemToCharA(outBreak, ob);
	char* vid = video;
	OemToCharA(video, vid);

	cout << "��������: " << name << endl;
	cout << "�������������: " << manufacturer << endl;
	cout << "����: " << color << endl;
	cout << "���������� (���): " << pover << endl;
	cout << "��� (��): " << veight << endl;
	cout << "����: " << cost << endl;
	cout << "������� ����� (��): " << dLens << endl;
	cout << "�����: " << focus << endl;
	cout << "�������: " << outBreak << endl;
	cout << "��������: " << exposure << endl;
	cout << "�����: " << video << endl;
	cout << "�������� ������ (����/���): " << speedShoot << endl;
	cout << "USB: " << USB << endl;
	cout << "____________________________________________________________" << endl;
}