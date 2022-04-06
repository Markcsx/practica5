/*
 * repte030a.cpp
 *
 */

#include "repte030a.h"
#include "jornada.h"

#include <fstream>
using namespace std;

void Repte030a(ostream& os)
{
	os << endl;
	os << "Repte030a: Classe CJornada" << endl;
	os << "==========================" << endl;

	// Prova objecte construit per defecte

	CJornada	jornada;

	os << "Objecte de CJornada construit amb el constructor per defecte" << endl << endl;
	os << jornada << endl;

	// Carrega de les dades d'un fitxer
	const char* c_fitxerA = "./data/jornada_a.txt";
	const char* c_fitxerB = "./data/jornada_b.txt";
	const char* c_fitxerActiu = c_fitxerA;

	os << "Carregant dades del fitxer " << endl;
	ifstream fitxer(c_fitxerActiu);

	if (fitxer.is_open())
	{
		fitxer >> jornada;
		os << "Fitxer carregat!" << endl ;
	}else{
		os << "Problemes al carregar el fitxer" << endl;
	}
	fitxer.close();

	os << endl;
	os << "Objecte de CJornada amb les dades del fitxer carregades" << endl << endl;
	os << jornada << endl;

	//Test de la funció a afegir a CJornada
	//Implementa-la un cop certifiquis que recuperes i mostres les dades del fitxer correctament
	//Descomenta el següent bloc de codi per provar la funcio a implementar


	CJornada jornadaBuida;
	CPartit	partit;

	os << "Partit amb major diferencia de gols de la jornada: " << jornadaBuida.GetNumJornada() << endl;
	if(jornadaBuida.PartitMajorDiferenciaGols(partit) == true)
	{
		os << " > " << partit << endl;
	}else{

		os << " > La jornada no conte partits." << endl;
	}
	os << endl;

	os << "Partit amb major diferencia de gols de la jornada: " << jornada.GetNumJornada() << endl;
	if(jornada.PartitMajorDiferenciaGols(partit))
	{
		os << " > " << partit << endl;
	}else{

		os << " > La jornada no conte partits." << endl;
	}
	os << endl;

	os << "Victories locals de la jornada " << jornada.GetNumJornada() << endl;
	jornada.MostraVictoriesLocals(os);

}



