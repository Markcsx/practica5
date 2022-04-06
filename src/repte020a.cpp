/*
 * repte020a.cpp
 *
 */

#include "repte020a.h"
#include "partit.h"

#include <fstream>
using namespace std;

void Repte020a(ostream& os)
{
	os << endl;
	os << "Repte020a: Operadors >> i << per la classe CPartit" << endl;
	os << "=========================================================" << endl;

	// Prova objecte construit per defecte

	CPartit	partit;

	os << "Objecte de CPartit construit amb el constructor per defecte" << endl;
	os << partit << endl;

	os << "Total de gols al partit: " << partit.GolsTotal() << endl << endl;

	// Carrega de les dades d'un fitxer a l'objecte 'partit'
	const char* c_fitxerPartit = "./data/partit_a.txt";
	os << "Carregant dades del fitxer " << c_fitxerPartit << endl;
	ifstream fitxer(c_fitxerPartit);

	if (fitxer.is_open())
	{
		fitxer >> partit;
		os << "Fitxer carregat!" << endl ;
	}else{
		os << "Problemes al carregar el fitxer" << endl;
	}
	fitxer.close();

	os << endl;
	os << "Objecte de CPartit amb les dades del fitxer " << c_fitxerPartit << " carregades" << endl;
	os << partit << endl;

	os << "Total de gols al partit: " << partit.GolsTotal() << endl << endl;

}



