#include "Graphe.h"
#include "Vecteur2D.h"

int main()
{
	/*
	GElement e(5);

	cout << "e = " << e << endl << endl;

	Sommet<double> s1(13, 3.1416);
	Sommet<string> s2(25, "aubergine");

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl << endl;


	Sommet<double> * debut = new Sommet<double>(23, 2.71);
	Sommet<double> * fin = new Sommet<double>(47, 1.41);

	Arete<string, double> a1(18, debut, fin, "melon");

	cout << "a1 = " << a1 << endl << endl;

	Graphe<string, char> g;
	Sommet<char> * so1 = g.creeSommet('A');
	Sommet<char> * so2 = g.creeSommet('B');
	Sommet<char> * so3 = g.creeSommet('C');

	g.creeArete(so1, so2, "myrtille");
	g.creeArete(so2, so3, "champignon");

	cout << "g = " << g << endl;

	Graphe<string, char> g2;
	Sommet<char> *som1 = g2.creeSommet('A');
	Sommet<char> *som2 = g2.creeSommet('B');
	Sommet<char> *som3 = g2.creeSommet('C');

	Arete<string, char> * arr1 = g2.creeArete(som1, som2, "machin");
	g2.creeArete(som2, som3, "truc");
	g2.creeArete(som3, som1, "bidule");

	cout << "cout g2 = " << g2.cout() << endl;

	cout << *(g2.adjacences(som1)->s->v->second) << endl;	
	*/

	Vecteur2D v1(0, 0);
	Vecteur2D v2(0, 2);
	Vecteur2D v3(1, 2);
	Vecteur2D v4(2, 2);
	Vecteur2D v5(2, 0);
	Vecteur2D v6(1, 0);
	

	Graphe<double, Vecteur2D> g2;
	Sommet<Vecteur2D> *som1 = g2.creeSommet(v1);
	Sommet<Vecteur2D> *som2 = g2.creeSommet(v2);
	Sommet<Vecteur2D> *som3 = g2.creeSommet(v3);
	Sommet<Vecteur2D> *som4 = g2.creeSommet(v4);
	Sommet<Vecteur2D> *som5 = g2.creeSommet(v5);
	Sommet<Vecteur2D> *som6 = g2.creeSommet(v6);

	Arete<double, Vecteur2D> * arr1 = g2.creeArete(som1, som2, som1->v.distance(som2->v));
	g2.creeArete(som2, som3, som2->v.distance(som3->v));
	g2.creeArete(som3, som4, som3->v.distance(som4->v));
	g2.creeArete(som4, som5, som4->v.distance(som5->v));
	g2.creeArete(som5, som6, som5->v.distance(som6->v));
	g2.creeArete(som6, som1, som6->v.distance(som1->v));

	cout << "cout g2 = " << g2.cout() << endl;

	//cout << "distance s1 s5 = " << som1->v.distance(som5->v) << endl;

	//cout << "arr = " << *arr1 << endl;

	//cout << "g = " << g2 << endl;

	g2.changementAleatoire();

	cout << "cout g2 = " << g2.cout() << endl;

	char ch; cin >> ch;
	return 0;
}