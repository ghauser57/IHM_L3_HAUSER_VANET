#include "GElement.h"

GElement::operator string() const
{
	ostringstream flux;
	flux << "Graphe : " << clef;
	return flux.str();
}

ostream & operator << (ostream & o, const GElement & g)
{
	o << g.operator std::string();
	return o;
}