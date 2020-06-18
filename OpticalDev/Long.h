#pragma once
#include "OpticalDev.h"
#include "OplicationDevEx.h"
class Long : public OpticalDev
{
protected:
	int dLens; // диаметр объектива
	int focus; // фокус
public:
	Long();	
	Long(char*, char*, char*, float, float, float, int, int);
	Long(const Long&);
	virtual ~Long();
	
	int getDLens() const;
	int getFocus() const;

	void setDLens(int);
	void setFocus(int);

	virtual void Print();
	virtual void readFromFile(char*);
	virtual void writeToFile(char*);
	void enterFormKeyboard();
};