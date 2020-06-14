#pragma once
#include "Near.h"
#include "OplicationDevEx.h"
class Magnifier : public Near
{
protected:
	char* form;
	char* materialLinz;

public:
	Magnifier();
	Magnifier(char*, char*, char*, float, float, float, float, char*, char*);
	Magnifier(const Magnifier&);
	virtual ~Magnifier();

	char* getForm() const;
	char* getMatLinz() const;

	void setForm(char*);
	void setMatLinz(char*);

	virtual void Print();
	virtual void readFromFile(char*);
	virtual void writeToFile(char*);
	void enterFormKeyboard();

};