#pragma once
#include "Camera.h"
#include "OplicationDevEx.h"
class NotAuto : public Camera
{
protected:
	char* addMit; // дополнительный материал
public:
	NotAuto();
	NotAuto(char*, char*, char*, float, float, float, int, int, char*, int, char*);
	NotAuto(const NotAuto&);
	virtual ~NotAuto();

	char* getAddMit() const;

	void setAddMit(char*);

	virtual void Print();
	virtual void readFromFile(char*);
	virtual void writeToFile(char*);
	void enterFormKeyboard();
};