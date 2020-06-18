#pragma once
#include "Long.h"
#include "OplicationDevEx.h"
class Telescop : public Long
{
protected:
	char* type; // тип 
	char* tripod; // штатив
	int eyep; // количество окуляров
	
public:
	Telescop();
	Telescop(char*, char*, char*, float, float, float, int, int, char*, char*, int);
	Telescop(const Telescop&);
	virtual ~Telescop();

	char* getType() const;
	char* getTripod() const;
	int getEyep() const;

	void setType(char*);
	void setTripod(char*);
	void setEyep(int);

	virtual void Print();
	virtual void readFromFile(char*);
	virtual void writeToFile(char*);
	void enterFormKeyboard();
};