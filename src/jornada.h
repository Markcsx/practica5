/*
 * jornada.h
 *
 */

#ifndef JORNADA_H_
#define JORNADA_H_
#include <iostream>
#include "partit.h"
#include "data.h"
#include "cadena.h"

class CJornada{
public:
	CJornada();  // Constructor per defecte
	CJornada(const CJornada& obj); // Constructor copia
	virtual ~CJornada();	// Destructor

	// [PAS2]
	// Declara els operadors >> i << per CJornada
	friend istream& operator>> (istream &is, CJornada& jornada);
	friend ostream& operator<< (ostream &os, const CJornada& jornada);
	CJornada& operator=(const CJornada& obj);

	// [PAS3]
	// Quan els operadors et funcionin correctament, afegeix
	// les funcions requerides al punt 6 de l'enunciat

	bool PartitMajorDiferenciaGols(CPartit& partit);
	bool PartitGolsMaxim(CPartit& partit);
	void MostraVictoriesLocals(ostream& os);
	float PercentatgeVictoriesLocals();
	bool GetPartitEquip(const CCadena& nomEquip, CPartit& partit);

	int partitsguanyats(const CCadena& nomEquip);
	int partitsempatats(const CCadena& nomEquip);
	int partitsperduts(const CCadena& nomEquip);

	int GetNumJornada();

private:
	// [ PAS 1]
	// Declara les variables membre (o atributs) de la classe per matenir
	// - el número de jornada (una número sencer)
	// - la data d'inici de la jornada (una data)
	// - la quantitat de partits que recull la jornada (un número sencer)
	// - un array DINAMIC d'objectes del tipus CPartit, per guardar les dades
	//   dels diferents partits de la jornada.
	CData m_data;
	int m_numJornada;
	int m_partitsjornada;
	CPartit *m_objectes;
	// Per guardar la data, utilitza el codi de la classe CData que has codificat
	// a les classes de teoria.
	friend CData CData(int dia, int mes, int any);

};

#endif /* JORNADA_H_ */
