#pragma once
#include <iostream>
#include <fstream>
#include "OplicationDevEx.h"
/*
Класс-интерфейс, состоящий только из чисто виртуальных методов.
Предназначен для того, чтобы наследники данного класса гарантированно реализовывали его методы.
*/
using namespace std;
class OpticalDevInterFace
{
public:
	virtual char* getName() const =0;
	virtual char* getColor() const = 0;
	virtual char* getManuf() const = 0;
	virtual float getVeight() const = 0;
	virtual float getPover() const = 0;
	virtual float getCost() const = 0;

	virtual void setName(char*) = 0;
	virtual void setColor(char*)  = 0;
	virtual void setManuf(char*)  = 0;
	virtual void setVeight(float) = 0;
	virtual void setPover(float)  = 0;
	virtual void setCost(float)  = 0;

	virtual void Print() = 0;
	virtual void readFromFile(char*) = 0;
	virtual void writeToFile(char*) = 0;
	virtual void enterFormKeyboard() = 0;
};
