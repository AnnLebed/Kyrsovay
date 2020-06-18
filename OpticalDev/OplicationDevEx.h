#pragma once
#include <string>
using namespace std;
class OpticalDevEx
{
public:
	OpticalDevEx(string asd) { error = asd; }
	string GetError() { return this->error; }
private:
	string error;
};

