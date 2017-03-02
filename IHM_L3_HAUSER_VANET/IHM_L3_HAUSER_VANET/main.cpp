#include "Graphe.h"
#include "Vecteur2D.h"
#include "RecuitSimule.h"
#include "DessinGrapheRecuitSimule.h"


int main()
{

	char ch;

	Vecteur2D v1(0, 0);
	Vecteur2D v2(0, 2);
	Vecteur2D v3(1, 2);
	Vecteur2D v4(2, 2);
	Vecteur2D v5(2, 0);
	Vecteur2D v6(1, 0);
	

	Graphe<double, Vecteur2D> g2;
	Sommet<Vecteur2D> *som1 = g2.creeSommet("s1", v1);
	Sommet<Vecteur2D> *som2 = g2.creeSommet("s2", v2);
	Sommet<Vecteur2D> *som3 = g2.creeSommet("s3", v3);
	Sommet<Vecteur2D> *som4 = g2.creeSommet("s4", v4);
	Sommet<Vecteur2D> *som5 = g2.creeSommet("s5", v5);
	Sommet<Vecteur2D> *som6 = g2.creeSommet("s6", v6);

	Arete<double, Vecteur2D> * arr1 = g2.creeArete(som1, som3, som1->v.distance(som3->v));
	g2.creeArete(som3, som5, som3->v.distance(som5->v));
	g2.creeArete(som5, som6, som5->v.distance(som6->v));
	g2.creeArete(som6, som4, som6->v.distance(som4->v));
	g2.creeArete(som4, som2, som4->v.distance(som2->v));
	g2.creeArete(som2, som1, som2->v.distance(som1->v));


	cout << "cout g2 = " << cout1(g2) << endl;
	
	Graphe<double, Vecteur2D> g = recuitSimule(2000.0,
		0.0,
		1000,
		500,
		g2,
		cout1,
		changementAleatoire,
		Succ);

	cout << "cout g = " << cout1(g) << endl;
	
	cout << "tapez un caractère, puis ENTER\n"; 

	cin >> ch;

	//----------------- on crée le fichier texte pour dessiner g1 ------------------------------


	string nomFichierDessin = "grapheHexagonalComplet.txt";
	ofstream f(nomFichierDessin);							// ouverture de f en écriture, en mode texte (cf. doc cplusplus.com)
	Vecteur2D coinBG(-1, -1), coinHD(5, 5);					// limites de la fenêtre à visualiser. calculées à partir des coordonnées des sommets
	string couleurRepere = "blue";
	int rayonSommet = 5;									// unité :  pixel
	string couleurSommets = "red";
	string couleurAretes = "blue";

	DessinGrapheRecuitSimule<double, Vecteur2D>::ecritGraphe(f, g, coinBG, coinHD, couleurRepere, rayonSommet, couleurSommets, couleurAretes);

	cout << "le fichier texte de  dessin " << nomFichierDessin << " a été créé" << endl;

	cin >> ch;


	return 0;
}