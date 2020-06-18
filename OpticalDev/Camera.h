#pragma once
#include "Long.h"
#include "OplicationDevEx.h"
class Camera : public Long
{
protected:
	char* outBreak; // вспышка
	int exposure; // выдержка
public:
	Camera();
	Camera(char*, char*, char*, float, float, float, int, int, char* , int);
	Camera(const Camera&);
	virtual ~Camera();

	char* getOutBreak() const;
	int getExposure() const;

	void setOutBreak(char*);
	void setExposure(int);

	virtual void Print();
	virtual void readFromFile(char*);
	virtual void writeToFile(char*);
	void enterFormKeyboard();
};