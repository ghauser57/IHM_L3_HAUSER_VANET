#pragma once
#include <sstream>
using namespace std;

template <class T>
class PElement
{
public:
	T* v;
	PElement<T> * s;

	PElement(T* v, PElement<T> * s) :v(v), s(s){}

	static int taille(const PElement<T> * l);

	static const string toString(const PElement<T> *p,
		const char * debut = "( ",
		const char * separateur = ", ",
		const char * fin = " )");

	static void insertionOrdonnee(T * a,
		PElement<T> * & l,
		bool(*estPlusPetitOuEgal)(const T * a1, const T * a2));
};

template <class T>
int PElement<T>::taille(const PElement<T> * l)
{
	if (l == NULL)
		return 0;
	else
		return 1 + taille(l->s);
}

template <class T>
const string PElement<T>::toString(const PElement<T> *p,
	const char * debut = "( ",
	const char * separateur = ", ",
	const char * fin = " )")
{
	ostringstream flux;
	flux << debut;
	if (p != NULL)
	{
		while (p->s != NULL)
		{
			flux << *p->v << separateur;
			p = p->s;
		}
		flux << *p->v;
	}
	flux << fin;
	return flux.str();
}

template <class T>
void PElement<T>::insertionOrdonnee(T * a,
	PElement<T> * & l,
	bool(*estPlusPetitOuEgal)(const T * a1, const T * a2))
{
	if (l == NULL)
	{
		l = new PElement<T>(a, l);
	}
	else
	{
		if (estPlusPetitOuEgal(a, l->v))
			l = new PElement<T>(a, l);
		else
			insertionOrdonnee(a, l->s, estPlusPetitOuEgal);
	}
}

template <class T>
ostream & operator << (ostream & os, const PElement<T> * p)
{
	os << p->toString(p);
	return os;
}

bool comparaison(const double * a1, const double * a2)
{
	return *a1 <= *a2;
}

bool comparaison(const string * a1, const string * a2)
{
	return a1->compare(*a2) <= 0;
}