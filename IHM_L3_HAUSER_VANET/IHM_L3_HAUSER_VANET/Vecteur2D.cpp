#include <sstream>
#include "Vecteur2D.h"

Vecteur2D::operator string() const
{
	ostringstream oss;

	oss << "( " << x << ", " << y << ")";

	return oss.str();
}


ostream & operator << (ostream & os, const Vecteur2D & u)
{
	os << (string)u;
	return os;
}


void fusionne(const double x[], const double y[], int m, Vecteur2D v[])
{
	int i;
	for (i = 0; i <= m; ++i)
		v[i] = Vecteur2D(x[i], y[i]);
}

double Vecteur2D::distance(const Vecteur2D & u)
{
	return sqrt(pow(u.x - this->x, 2) + pow(u.y - this->y, 2));
}

bool Vecteur2D::operator == (const Vecteur2D & v) const
{
	return (this->x == v.x && this->y == v.y);
}

bool Vecteur2D::operator != (const Vecteur2D & v) const
{
	return !(*this == v);
}