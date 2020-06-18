#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "OplicationDevEx.h"
#include "OptocalDevInterFace.h"
using namespace std;
class OpticalDev : public OpticalDevInterFace
{
	
protected:
	friend class Search;
	friend class sort;
	char* name;
	char* manufacturer; // производитель
	char* color;
	float veight;
	float pover; 
	float cost; // цена

public:
	OpticalDev();
	OpticalDev(char*, char*, char*, float, float, float);
	OpticalDev(const OpticalDev&);
	 ~OpticalDev();
	char* getName() const override;
	char* getColor() const override;
	char* getManuf() const override;
	float getVeight() const override;
	float getPover() const override;
	float getCost() const override;

	void setName(char* ) override;
	void setColor(char*) override;
	void setManuf(char*) override;
	void setVeight(float) override;
	void setPover(float) override;
	void setCost(float) override;

	void Print() override;
	void readFromFile(char*) override;
	void writeToFile(char*) override;
	void enterFormKeyboard() override;
};