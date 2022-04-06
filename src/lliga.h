/*
 * lliga.h
 *
 */

#ifndef SRC_LLIGA_H_
#define SRC_LLIGA_H_

#include <iostream>
using namespace std;

#include "jornada.h"

class CLliga{
public:
	CLliga(); // Constructor per defecte
	virtual ~CLliga(); // Destructor
	// [PAS2]
	// Declara els constructor de còpia
	CLliga(const CLliga& obj);
	// [PAS3]
	// Declara l'operador d'assignació
	CLliga& operator=(const CLliga& obj);
	// [PAS4]
	// Declara els operadors >> i << per CRankingsPeriode
	friend istream& operator>> (istream &is, CLliga& obj);
	friend ostream& operator<< (ostream &os, const CLliga& obj);
	// [PAS5]
	// Quan els operadors et funcionin correctament, afegeix
	// les funcions demanades a l'enunciat o que necessitis

	void MostraResultatsEquip(const CCadena& nomEquip, ostream& os);
	void MostraResumPartits(const CCadena& nomEquip, ostream& os);
	bool GetPartitMesGols(CPartit& partit, int& numJornada);

private:
	// [ PAS 1]
	// Declara les variables membre (o atributs) de la classe per matenir
	// - el nom de la lliga (una cadena de caràcters)
	CCadena m_nomLliga;
	// - la quantitat de jornades agrupades a la lliga (un número sencer)
	int m_numJornadasLliga;
	// - un array DINAMIC d'objectes del tipus CJornada, per guardar les dades
	//   de les diferents jornades de lliga.
	CJornada *m_jornadas;

};

#endif /* SRC_LLIGA_H_ */
