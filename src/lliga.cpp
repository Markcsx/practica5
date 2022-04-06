/*
 * lliga.cpp
 *
 */

#include "lliga.h"

#include <fstream>
using namespace std;


CLliga::CLliga() {
	// Defineix aquí el constructor per defecte
	// Ha d'inicialitzar:
	//	- el nom de la lliga a "indefinit"
	m_nomLliga = "indefinit";
	//	- la quantitat de jornades a 0.
	m_numJornadasLliga=0;
	//	- l'apuntador de l'array dinàmic per mantenir les jornades apuntant a l'adreça 0.
	m_jornadas=0;
}

CLliga::~CLliga() {
	// Defineix aquí el destructor
	// Ha d'alliberar la memòria dinàmica que es pugui tenir reservada
	if(m_jornadas!=0){
			delete[] m_jornadas;
	}
}


CLliga::CLliga(const CLliga& obj){
	int i;
	m_numJornadasLliga = obj.m_numJornadasLliga;
	m_jornadas = obj.m_jornadas;

	if(m_jornadas>0){
		m_jornadas = new CJornada[m_numJornadasLliga];

		for (i=0;i<m_numJornadasLliga;i++){
			m_jornadas[i]=obj.m_jornadas[i];
		}
	}else {
		m_jornadas=0;
	}
}


CLliga&
CLliga::operator=(const CLliga& obj){
	if (this != &obj){
		int i;
		if(m_jornadas!=0){
			delete[] m_jornadas;
		}
		m_numJornadasLliga=obj.m_numJornadasLliga;
		m_jornadas=obj.m_jornadas;
		if(m_jornadas>0){
			m_jornadas = new CJornada[m_numJornadasLliga];
			for (i=0;i<m_numJornadasLliga;i++){
				m_jornadas[i]=obj.m_jornadas[i];
			}
		}else {
			m_jornadas=0;
		}
	}
	return (*this);
}

void
CLliga::MostraResultatsEquip(const CCadena& nomEquip, ostream& os){
	CPartit partit;

	os << "Partits disputats per l'equip: " <<  nomEquip <<  endl;

	for(int i=0;i<m_numJornadasLliga;i++){
		if(m_jornadas[i].GetPartitEquip(nomEquip, partit)==true){
		}
			os << partit << endl;
		}

}

void
CLliga::MostraResumPartits(const CCadena& nomEquip, ostream& os){
	int a=0;
	int b=0;
	int c=0;
	for(int i=0;i<m_numJornadasLliga;i++){
		a = a + m_jornadas[i].partitsguanyats(nomEquip);
		b = b + m_jornadas[i].partitsempatats(nomEquip);
		c = c + m_jornadas[i].partitsperduts(nomEquip);
	}

	os << "Resum dels partits de l'equip " <<  nomEquip <<  endl;
	os << "Partits jugats: " << a + b + c <<endl;
	os << "Partits guanyats: " << a <<endl;
	os << "Partits empatats: " << b <<endl;
	os << "Partits perduts: " << c <<endl;

}

bool
CLliga::GetPartitMesGols(CPartit& partit, int& numJornada){

	bool value = false;
	for(int i=0;i<m_numJornadasLliga;i++){
		if(m_jornadas[i].PartitGolsMaxim(partit)==true){
			value=true;
			numJornada=m_jornadas[i].GetNumJornada();
		}
	}
	return value;
}

istream& operator>> (istream &is, CLliga& obj){
	is >> obj.m_nomLliga;
	is >> obj.m_numJornadasLliga;
	obj.m_jornadas= new CJornada[obj.m_numJornadasLliga];//assigna memoria dinamica
	for (int i=0 ; i<obj.m_numJornadasLliga; i++)//contador de los array
	{
		is >> obj.m_jornadas[i];
	}
	return is;
}


ostream& operator<< (ostream &os, const CLliga& obj){
	os << "Lliga ";
	os << obj.m_nomLliga << endl;
	for (int i=0 ; i<obj.m_numJornadasLliga; i++)
	{
		os << obj.m_jornadas[i] << endl;
	}
	return os;
}

