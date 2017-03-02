#pragma once
#include "DessinGraphe.h"
#include "Graphe.h"

using namespace std;
/**
définit les outils nécessaires pour dessiner un graphe représentant une carte routière.
But : Application de l'algorithme du recuit simulé à la recherche du problème du voyageur de commerce

cette classe définit les outils qui ne sont pas déjà dans DessinGraphe (cf. classe DessinGraphe)
*/
template <class S, class T>
class DessinGrapheRecuitSimule
{
public:
	/**S

	rayonSommet est le rayon des sommets sur l'écran
	*/
	static void ecritSommets(ofstream & of, const Graphe<S, T> & graphe, const double & rayonSommet, const string & couleur);

	static void ecritAretes(ofstream & of, const Graphe<S, T> & graphe, const string & couleur);


	/**
	écrit le graphe-carte routière sur le fichier texte de dessin of.
	suppose of déjà ouvert en écriture seule

	rayonSommet est le rayon des sommets sur l'écran
	*/
	static void ecritGraphe(ofstream & of, Graphe<S, T> & graphe,
		const Vecteur2D & coinBG, const Vecteur2D & coinHD,
		const string & couleurRepere,
		const double & rayonSommet,
		const string & couleurSommets,
		const string & couleurAretes);
};



/**

rayonSommet est le rayon des sommets sur l'écran
*/
template <class S, class T>
/*static*/ void DessinGrapheRecuitSimule<S, T>::ecritSommets(ofstream & of, const Graphe<S, T> & graphe,
	const double & rayonSommet, const string & couleur)
{
	PElement<Sommet<T>> * l;

	for (l = graphe.lSommets; l; l = l->s)
	{
		T * info = &(l->v->v);
		of << "point remarquable = " << rayonSommet << " " << couleur << " " << l->v->v << " " << l->v->nom << l->v->v << endl;
	}


}

template <class S, class T>
/*static*/ void DessinGrapheRecuitSimule<S, T>::ecritAretes(ofstream & of, const Graphe<S, T> & graphe, const string & couleur)
{
	PElement<Arete<S, T>> * l;

	for (l = graphe.lAretes; l; l = l->s)
	{
		of << "couleur =  " << couleur << endl;
		of << "nombre de points = 2" << endl;
		of << l->v->debut->v << endl;
		of << l->v->fin->v << endl;
	}
}


/**
écrit le graphe-carte routière sur le fichier texte de dessin of.
suppose of déjà ouvert en écriture seule

rayonSommet est le rayon des sommets sur l'écran
*/
template <class S, class T>
/*static*/ void DessinGrapheRecuitSimule<S, T>::ecritGraphe(ofstream & of, Graphe<S, T> & graphe,
	const Vecteur2D & coinBG, const Vecteur2D & coinHD,
	const string & couleurRepere,
	const double & rayonSommet,
	const string & couleurSommets,
	const string & couleurAretes)
{
	string resume;

	resume = "carte routière";

	DessinGraphe::ecrireEntete(of, "carte routière", "carte routière simplifiée représentée par un graphe", resume, coinBG, coinHD);

	DessinGraphe::ecritNombrePointsRemarquables(of, 3 + graphe.nombreSommets());
	DessinGraphe::ecritRepere(of, couleurRepere);
	ecritSommets(of, graphe, rayonSommet, couleurSommets);

	DessinGraphe::ecritNombreCourbes(of, graphe.nombreAretes());
	ecritAretes(of, graphe, couleurAretes);
}
