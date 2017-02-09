#pragma once
#include <iostream>
#include <math.h>
using namespace std;

double tirageAleatoire()
{
	double x = rand();

	return x / RAND_MAX;
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
			s = changementAleatoire(s);
			if (cout1(s) < cout1(sPrecedente))
			{
				nombreSucces--;
				if (cout1(s) < cout1(sBest))
					sBest = s;
			}
			else
			{
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
