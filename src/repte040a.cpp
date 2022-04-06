/*
 * repte040a.cpp
 *
 */

#include "repte040a.h"
#include "jornada.h"

#include <fstream>
using namespace std;

void
Repte040a(ostream& os)
{
	os << endl;
	os << "Repte040a: Classe CJornada - Operador = i constructor de copia" << endl;
	os << "======================================================================" << endl;

	// Carrega de les dades d'un fitxer 
	const char* c_fitxerA = "./data/jornada_a.txt";
	const char* c_fitxerB = "./data/jornada_b.txt";
	const char* c_fitxerC = "./data/jornada_c.txt";

	CJornada jornadaA;
	CJornada jornadaB;

	// [PAS 1]
	// Estudi de la necessitat de l'operador d'assignació
	// en classes que gestionen memòria dinàmica
	//
	// A les línies (1) i (2) s'utilitza l'assignació per
	// copiar l'objecte que retorna 'CarregaFitxer'
	// als objecte 'jornadaA' i 'jornadaB'. Un cop feta l'assignació,
	// l'objecte 'jornada' de 'CarregaFitxer' es destrueix
	// alliberant la memòria dinàmica que conté.
	//
	// Si CJornada no té la sobrecàrrega de l'operador =
	// que faci còpia de la memòria dinàmica, el programa
	// no funcionarà correctament.

	os << "Carrega dels fitxers A i B" << endl;
	jornadaA = CarregaFitxer(c_fitxerA); //(1)
	jornadaB = CarregaFitxer(c_fitxerB); //(2)

	os << "Dades a l'objecte jornadaA" << endl;
	os << jornadaA << endl;
	os << "Dades a l'objecte jornadaB" << endl;
	os << jornadaB << endl;

	// [PAS 2]
	// Estudi de la necessitat del constructor de còpia
	// en classes que gestionen memòria dinàmica
	//
	// A la linia (3) es fa un pas per valor de l'objecte
	// 'jornadaA', que es còpia en el paràmetre 'jornada'
	// de la funció 'MostraJornada'. Quan aquesta funció
	// finalitza l'objecte 'jornada' es destrueix, destruint
	// la seva memòria dinàmica. Això provoca que 'jornadaA'
	// perdi les seves dades.
	//
	// Cal definir un constructor de còpia perquè quan
	// es crei el paràmetre 'jornada' a la funció 'MostraJornada'
	// es faci una còpia de la memòria dinàmica de 'jornadaA',
	// de manera que quan 'jornada' es destrueixi elimini
	// la seva pròpia memòria dinàmica, no la de 'jornadaA'.

	MostraJornada(os, jornadaA); //(3)

	// Aquí es demana memòria dinàmica
	int* pInt = new int;
	delete pInt;

	MostraJornada(os, jornadaA); //(4)

	// Test de les funcions a afegir a CJornada
	// Implementa-les un cop certifiquis que recuperes i mostres les dades del fitxer correctament
	// Descomenta el següent bloc de codi per provar les funcions a implementar



	jornadaA = CarregaFitxer(c_fitxerC);

	os << jornadaA << endl << endl;

	os << "El percentatge de partits de la jornada " << jornadaA.GetNumJornada();
	os << " en que l'equip local és guanyador és el ";
	os << jornadaA.PercentatgeVictoriesLocals() << "%" << endl;

}

CJornada
CarregaFitxer(const char* nomFitxer)
{
	CJornada jornada;

	ifstream fitxer(nomFitxer);

	if (fitxer.is_open())
	{
		fitxer >> jornada;
	}
	fitxer.close();

	return jornada;
}

void
MostraJornada(ostream& os, CJornada jornada)
{
	os << jornada << endl;
}






