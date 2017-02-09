#include "GElement.h"

GElement::GElement()
{
}


GElement::~GElement()
{
}

GElement::operator string() const
{
	return "Graphe-Element : " + clef;
}