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
	PElement(const PElement<T> & pe);

	PElement<T> * operator = (const PElement<T> & Pelem);

	static int taille(const PElement<T> * l);

	static const string toString(const PElement<T> *p,
		const char * debut = "( ",
		const char * separateur = ", ",
		const char * fin = " )");

	static void insertionOrdonnee(T * a,
		PElement<T> * & l,
		bool(*estPlusPetitOuEgal)(const T * a1, const T * a2));

	/**
	* efface toute la liste l
	* et efface toutes les données *v
	*
	* */
	bool isIn(const T* elem);

	static void efface2(PElement<T>* & l);
};

template <class T>
bool PElement<T>::isIn(const T* elem)
{
	PElement<T> * temp = this;
	/*if (this == NULL)
		temp = NULL;
	else
		temp = new PElement<T>(this->v, this->s);*/
	while (temp != NULL)
	{
		if (elem == temp->v)
			return true;
		temp = temp->s;
	}
	return false;
}

template <class T>
PElement<T>::PElement(const PElement<T> & pe) :v(NULL), s(NULL)
{
	PElement<T> * temp = new PElement<T>(pe.v,pe.s);
	PElement<T> * temp2 = NULL;
	
	v = new T(*temp->v);
	while (temp->s != NULL)
	{
		temp = temp->s;
		temp2 = new PElement<T>(new T(*temp->v), temp2);
	}
	s = temp2;
}
/*
template <class T>
PElement<T> * PElement<T>::operator = (const PElement<T> & Pelem){
	PElement<T> * temp = &Pelem;
	PElement<T> * val = NULL;

	if (this != &pelem){
		for (int i = 0; i < PElement<T>::taille(&Pelem); i++){
			val = new PElement<T>(temp->v, val);
			temp = temp->s;
		}
	}

	return val;
}*/

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

template <class T>
/* static */ void PElement<T>::efface2(PElement<T>* & l)
{
	if (l)
	{
		PElement<T>::efface2(l->s);
		delete l->v; delete l; l = NULL;
	}
}