#pragma once
#include "OpticalDev.h"
#include "OplicationDevEx.h"
class Near : public OpticalDev
{
protected:
	float resolution; // разрешающая способность
public:
	Near();
	Near(char*, char*, char*, float, float, float, float);
	Near(const Near&);
	virtual ~Near();

	float getResolution() const;

	void setResolution(float);

	virtual void Print();
	virtual void readFromFile(char*);
	virtual void writeToFile(char*);
	void enterFormKeyboard();
};
