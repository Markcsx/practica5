/*
 * repte050a.cpp
 *
 */

#include "repte050a.h"
#include "lliga.h"

#include <fstream>
using namespace std;

void
Repte050a(ostream& os)
{
	os << endl;
	os << "Repte050a: Classe CLliga  " << endl;
	os << "==========================" << endl;

	// Prova objecte construit per defecte

	CLliga lliga;

	os << "Objecte de CLliga construit amb el constructor per defecte" << endl << endl;

	os << lliga << endl;

	// Carrega de les dades d'un fitxer
	const char* c_fitxerA = "./data/BBVA20082009.txt";
	const char* c_fitxerB = "./data/mini_lliga.txt";
	const char* c_fitxerActiu = c_fitxerB;
	ifstream fitxerA(c_fitxerActiu);

	os << "Carregant dades del fitxer " << endl;

	if (fitxerA.is_open())
	{
		fitxerA >> lliga;
		os << "Fitxer carregat!" << endl ;
	}else{
		os << "Problemes al carregar el fitxer" << endl;
	}
	fitxerA.close();

	os << endl;
	os << "Objecte de CLliga amb les dades del fitxer " << c_fitxerActiu << " carregades" << endl << endl;

// Descomenta aquesta linia si vols comprova si carregues correctament l'arxiu

	os << lliga << endl;


// Pas 1

	// Mostrar els partits que un equip a disputat en una lliga

	CCadena nomEquip("Barcelona");

	lliga.MostraResultatsEquip(nomEquip, os);
	os << endl;


// Pas 2 :

	lliga.MostraResumPartits(nomEquip,os);
	os << endl;


// Pas 3

	CPartit partit;
	int numJornada;

	os << "Partit de lliga on s'han marcat el màxim de gols:" << endl;
	if(lliga.GetPartitMesGols(partit, numJornada))
	{
		os << partit << endl;
		os << "a la jornada " << numJornada << endl;
	}else{

		os << "Cap. La lliga no té jornades registrades" << endl;
	}
	os << endl;

}


