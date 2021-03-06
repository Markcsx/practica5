/*
 * Partit.cpp
 *
 * Pr?ctiques Fonaments d'Enginyeria del Software
 */

#include "partit.h"
#include "cadena.h"

// Defineix les funcions indicades a la declaraci? de la classe

// 3.1 El constructor per defecte, que inicialitza el nom dels equips local i
//	   visitant a la paraula "indefinit" i els seus gols a zero

CPartit::CPartit()
{
	m_nomlocal = "indefinit";
	m_nomvisit = "indefinit";
	m_GolsLocal = 0;
	m_GolsVisitant = 0;
	m_GolsTotal = 0;
};

// 3.2 El constructor que rep par?metres

CPartit::CPartit (CCadena nomlocal, CCadena nomvisit){
	m_nomlocal = nomlocal;
	m_nomvisit = nomvisit;
	m_GolsLocal = 0;
	m_GolsVisitant = 0;
	m_GolsTotal = 0;
};

// 3.3 Els 'getters' dels atributs de la classe
//	   - GetLocal
//	   - GetVisitant
//	   - GetGolsLocal
//	   - GetGolsVisitant

CCadena CPartit::GetLocal()
{
	return m_nomlocal;
};

CCadena CPartit::GetVisitant()
{
	return m_nomvisit;
};

int CPartit::GetGolsLocal()
{
	return m_GolsLocal;
};

int CPartit::GetGolsVisitant()
{
	return m_GolsVisitant;
};

int CPartit::GolsTotal()
{
	m_GolsTotal =  m_GolsLocal + m_GolsVisitant;
	return m_GolsTotal;
};

// 3.4 Les funcions:
//     - MarcaLocal
//     - MarcaVisitant


void CPartit::MarcaLocal(){
	m_GolsLocal++;
}
void CPartit::MarcaVisitant(){
	m_GolsVisitant++;
}



ostream& operator<< (ostream &os, const CPartit& partits){
	os << partits.m_nomlocal << " ";
	os << partits.m_GolsLocal << " : ";
	os << partits.m_GolsVisitant << " ";
	os << partits.m_nomvisit;
	return os;
}



istream& operator>> (istream &is, CPartit& partits){
	is >> partits.m_nomlocal;
	is >> partits.m_GolsLocal;
	is >> partits.m_nomvisit;
	is >> partits.m_GolsVisitant;
	return is;
}
