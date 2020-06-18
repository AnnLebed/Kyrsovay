#pragma once
#include "Camera.h"
#include "OplicationDevEx.h"
class Auto : public Camera
{
protected:
	char* video; // видео
	float USB; 
	int speedShoot; // скорость съемки
public:
	Auto();
	Auto(char*, char*, char* , float , float, float , int , int , char* , int , char* , float , int);
	Auto(const Auto&);
	virtual ~Auto();

	char* getVideo() const;
	float getUSB() const;
	int getSpeedSh() const;

	void setVideo(char*);
	void setUSB(float);
	void setSpeedSh(int);

	virtual void Print();
	virtual void readFromFile(char*);
	virtual void writeToFile(char*);
	void enterFormKeyboard();
};