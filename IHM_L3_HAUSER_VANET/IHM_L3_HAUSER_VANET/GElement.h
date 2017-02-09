#pragma once
#include <sstream>
#include <string>
#include <string.h>
using namespace std;

class GElement
{
public:
	int clef;

	GElement(int c) :clef(c){}

	operator string() const;
};

ostream & operator << (ostream & o, const GElement & g);