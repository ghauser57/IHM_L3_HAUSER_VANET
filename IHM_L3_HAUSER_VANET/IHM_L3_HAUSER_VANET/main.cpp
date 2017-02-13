#include "Graphe.h"


int main()
{
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

	char ch; cin >> ch;
	return 0;
}