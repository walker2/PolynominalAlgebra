#ifndef POLYNOM
#define POLYNOM


#include <iostream>
#include <vector>
#include <string>
#include <cctype>   
#include <cstdlib>
#include <sstream>
#include "Mod.h"

class Polynom
{
public:
	Polynom();
	Polynom(int size, int f = 0);
	Polynom(std::string polynom, int f = 0);
	Polynom(std::vector<int>& v, int f = 0);
	Polynom(const Polynom& p);
	~Polynom();
	Polynom& operator=(const Polynom& p);

	Polynom operator+(const Polynom& p);
	Polynom operator-(Polynom& p);
	Polynom operator*(Polynom& p);
	Polynom operator/(Polynom& p);
	void shift(int num);
    bool isZero();
	
	Polynom& undefinedCoef(Polynom& divider);
	
	std::vector<int>& getRemainder() { return remainder; }
	void setField(int f) { field = f; }
	int getField() { return field; }

	friend std::ostream& operator<<(std::ostream& o, Polynom& p);

private:
	std::vector<int> data;
	std::vector<int>::iterator iter;
	std::vector<int> remainder;
	int field;
};

#endif // !POLYNOM