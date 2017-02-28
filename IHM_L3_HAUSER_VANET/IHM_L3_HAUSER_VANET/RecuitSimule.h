#include <stdlib.h>
#include <time.h> 
#include <math.h>
#include "Graphe.h"

double tirageAleatoire()
{
	double x = rand();

	return x / RAND_MAX;
}

double Succ(const double & x){
	return x - 1;
}

template <class S, class T>
double cout1(const Graphe<S, T> & g)
{
	S temp{};
	PElement<Arete<S, T>> * a = g.lAretes;
	while (a != NULL)
	{
		temp = temp + a->v->v;
		a = a->s;
	}
	//printf("cout exec\n");
	return temp;
}

template <class S, class T>
Graphe<S,T> changementAleatoire(const Graphe<S,T> & g)
{
	Graphe<S, T> * temp = new Graphe<S,T>(g);
	srand(time(NULL));
	int max = temp->nombreSommets() - 1;
	int min = 0;
	int nbTemp;
	int nbA, nbB;
	Sommet<T> * A;
	Sommet<T> * B;
	PElement<Sommet<T>> * parcours;
	PElement< pair< Sommet<T> *, Arete<S, T>* > >  * paire1;
	PElement< pair< Sommet<T> *, Arete<S, T>* > >  * paire2;
	do
	{
		parcours = temp->lSommets;
		nbA = (rand() % (max - min + 1)) + min;
		nbB = (rand() % (max - min + 1)) + min;
		if (nbA > nbB)
		{
			nbTemp = nbB;
			nbB = nbA;
			nbA = nbTemp;
		}
		for (int i = 0; i < nbA; i++)
		{
			parcours = parcours->s;
		}
		A = parcours->v;
		for (int j = nbA; j < nbB; j++)
		{
			parcours = parcours->s;
		}
		B = parcours->v;
	} while (temp->getAreteParSommets(A, B) != NULL || A == B);
	PElement< pair< Sommet<T> *, Arete<S, T>* > >  * paireAC = temp->adjacencesPlus(A);
	PElement< pair< Sommet<T> *, Arete<S, T>* > >  * paireBD = temp->adjacencesPlus(B);
	Sommet<T> * s = paireAC->v->first;
	paire2 = temp->adjacencesPlus(s);
	paireBD->v->second->debut = paireAC->v->first;
	paireAC->v->second->fin = B;
	paireBD->v->second->v = paireAC->v->first->v.distance(paireBD->v->first->v);
	paireAC->v->second->v = A->v.distance(B->v);
	do
	{
		paire1 = paire2;
		paire2 = temp->adjacencesPlus(paire1->v->first);
		paire1->v->second->debut = paire1->v->first;
		paire1->v->second->fin = s;
		s = paire1->v->first;
	} while (!(s == B));
	return *temp;
}

template <class S>
S recuitSimule(const double & tInitiale,
	const double & tFinale,
	const int & nombreTentativesMax,
	const int & nombreSuccesMax,
	const S & s0,
	double(*cout1)(const S & s),
	S(*changementAleatoire)(const S & s),
	double(*succ)(const double & t))
{
	double t = tInitiale;
	S s = s0;
	S sBest = s0;

	S sPrecedente;

	while (t > tFinale)
	{
		int nombreTentatives = 0;
		int nombreSucces = 0;
		while ((nombreTentatives < nombreTentativesMax) && (nombreSucces < nombreSuccesMax))
		{
			nombreTentatives++;
			sPrecedente = s;
			//printf("avant changement\n");
			s = changementAleatoire(s);
			//printf("après changement\n");
			if (cout1(s) < cout1(sPrecedente))
			{
				//printf("if\n");
				nombreSucces--;
				if (cout1(s) < cout1(sBest))
					sBest = s;
			}
			else
			{
				//printf("else\n");
				double v = tirageAleatoire();
				double dCout = cout1(s) - cout1(sPrecedente);
				if (v < exp(-(dCout / t)))
					nombreSucces++;
				else
					s = sPrecedente;
			}
		}
		if (nombreSucces == 0)
			return sBest;
		t = succ(t);
	}
	return sBest;
}