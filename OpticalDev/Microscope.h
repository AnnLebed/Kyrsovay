#pragma once
#include "OplicationDevEx.h"
#include "Near.h"
class Microscope : public Near
{
protected:
	char* light; // система освещения
	char* screw; // винт фокусировки

public:
	Microscope();
	Microscope(char*, char*, char*, float, float, float, float, char*, char*);
	Microscope(const Microscope&);
	virtual ~Microscope();

	char* getLight() const;
	char* getScrew() const;

	void setLight(char*);
	void setScrew(char*);

	virtual void Print();
	virtual void readFromFile(char*);
	virtual void writeToFile(char*);
	void enterFormKeyboard();
};