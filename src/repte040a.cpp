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
	// Estudi de la necessitat de l'operador d'assignaci�
	// en classes que gestionen mem�ria din�mica
	//
	// A les l�nies (1) i (2) s'utilitza l'assignaci� per
	// copiar l'objecte que retorna 'CarregaFitxer'
	// als objecte 'jornadaA' i 'jornadaB'. Un cop feta l'assignaci�,
	// l'objecte 'jornada' de 'CarregaFitxer' es destrueix
	// alliberant la mem�ria din�mica que cont�.
	//
	// Si CJornada no t� la sobrec�rrega de l'operador =
	// que faci c�pia de la mem�ria din�mica, el programa
	// no funcionar� correctament.

	os << "Carrega dels fitxers A i B" << endl;
	jornadaA = CarregaFitxer(c_fitxerA); //(1)
	jornadaB = CarregaFitxer(c_fitxerB); //(2)

	os << "Dades a l'objecte jornadaA" << endl;
	os << jornadaA << endl;
	os << "Dades a l'objecte jornadaB" << endl;
	os << jornadaB << endl;

	// [PAS 2]
	// Estudi de la necessitat del constructor de c�pia
	// en classes que gestionen mem�ria din�mica
	//
	// A la linia (3) es fa un pas per valor de l'objecte
	// 'jornadaA', que es c�pia en el par�metre 'jornada'
	// de la funci� 'MostraJornada'. Quan aquesta funci�
	// finalitza l'objecte 'jornada' es destrueix, destruint
	// la seva mem�ria din�mica. Aix� provoca que 'jornadaA'
	// perdi les seves dades.
	//
	// Cal definir un constructor de c�pia perqu� quan
	// es crei el par�metre 'jornada' a la funci� 'MostraJornada'
	// es faci una c�pia de la mem�ria din�mica de 'jornadaA',
	// de manera que quan 'jornada' es destrueixi elimini
	// la seva pr�pia mem�ria din�mica, no la de 'jornadaA'.

	MostraJornada(os, jornadaA); //(3)

	// Aqu� es demana mem�ria din�mica
	int* pInt = new int;
	delete pInt;

	MostraJornada(os, jornadaA); //(4)

	// Test de les funcions a afegir a CJornada
	// Implementa-les un cop certifiquis que recuperes i mostres les dades del fitxer correctament
	// Descomenta el seg�ent bloc de codi per provar les funcions a implementar



	jornadaA = CarregaFitxer(c_fitxerC);

	os << jornadaA << endl << endl;

	os << "El percentatge de partits de la jornada " << jornadaA.GetNumJornada();
	os << " en que l'equip local �s guanyador �s el ";
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






