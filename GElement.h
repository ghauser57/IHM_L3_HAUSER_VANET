#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class GElement
{
public:

	GElement();

	int clef;

	GElement(int c) : clef(c){}

	operator string() const;


};

ostream & operator << (ostream & f, GElement & g){
	f << g.operator string();
	return f;
}
