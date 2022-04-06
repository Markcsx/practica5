/*
 * jornada.cpp
 *
 */

#include "jornada.h"
#include "partit.h"


CJornada::CJornada() {
	// Defineix aquí el constructor per defecte
	// Ha d'inicialitzar:
	//	- el numero de jornada al valor zero
	//	- la data d'inici de la jornada al 1 de gener del 2000
	//	- la quantitat d'àlbums al valor zero
	//	- l'apuntador de l'array dinàmic apuntant a l'adreça 0.
	m_numJornada = 0;
	m_data.SetData(1,1,2000);
	m_partitsjornada = 0;
	m_objectes = 0;
}

CJornada::~CJornada() {
	// Defineix aquí el destructor
	// Ha d'alliberar la memòria dinàmica que es pugui tenir reservada
	if(m_objectes!=0){
			delete[] m_objectes;
	}
};

istream& operator>> (istream &is, CJornada& jornadas)
	{
		//delete[] jornadas.m_objectes;
		is >> jornadas.m_numJornada;
		is >> jornadas.m_data;
		is >> jornadas.m_partitsjornada;
		jornadas.m_objectes= new CPartit [jornadas.m_partitsjornada];//assigna memoria dinamica
		for (int i=0 ; i<jornadas.m_partitsjornada; i++)//contador de los array
		{
			is >> jornadas.m_objectes[i];
		}
		return is;
	}
ostream& operator<< (ostream &os, const CJornada& jornadas)
	{
		os << "Jornada ";
		os << jornadas.m_numJornada << " ";
		os << jornadas.m_data << " " << endl;
		for (int i=0 ; i<jornadas.m_partitsjornada; i++)
		{
			os << jornadas.m_objectes[i] << endl;
		}
		return os;
	}

bool
CJornada::PartitMajorDiferenciaGols(CPartit& partit)
{
	bool retValor=false;
	if(m_partitsjornada==0)
	{
		 retValor=false;
	} else
	{
		int total=m_objectes[0].GolsTotal();
		for(int i=0;i<m_partitsjornada;i++)
		{
				if(total<m_objectes[i].GolsTotal())
				{
					total=m_objectes[i].GolsTotal();
					partit=m_objectes[i];
				}
		}
		retValor=true;
	}
	return retValor;
}

bool
CJornada::PartitGolsMaxim(CPartit& partit)
{
	bool retValor=false;
	if(m_partitsjornada==0)
	{
		 retValor=false;
	} else
	{
		int total=m_objectes[0].GolsTotal();
		for(int i=0;i<m_partitsjornada;i++)
		{
			if(total<m_objectes[i].GolsTotal()) // Esto compara el valor del total con los partidos
			{
				total=m_objectes[i].GolsTotal(); //LE asigna los goles al total
				partit=m_objectes[i];//asigna el partido con esos goles
			}
		}
		retValor=true;
	}
	return retValor;
}

void
CJornada::MostraVictoriesLocals(ostream& os)
{

	for(int i=0;i<m_partitsjornada;i++)
	{
		int locales=m_objectes[i].GetGolsLocal();
		int visitantes=m_objectes[i].GetGolsVisitant();
		if(locales>visitantes)
		{
			os<<m_objectes[i]<< endl;
		}
	}
}


int
CJornada::GetNumJornada()
{
	return m_numJornada;
}

float
CJornada::PercentatgeVictoriesLocals(){
	float valor=0;
	float ganalocal=0;
	for(int i=0;i<m_partitsjornada;i++)
		{
			int locales=m_objectes[i].GetGolsLocal();
			int visitantes=m_objectes[i].GetGolsVisitant();
			if(locales>visitantes)
			{
				ganalocal++;
				valor=(ganalocal/m_partitsjornada)*100;
			}
		}
	return valor;
}

bool
CJornada::GetPartitEquip(const CCadena& nomEquip, CPartit& partit)
{
	bool retValor;
	for(int i=0; i<m_partitsjornada; i++)
	{
		if(m_objectes[i].GetLocal()==nomEquip || m_objectes[i].GetVisitant()==nomEquip){
			partit=m_objectes[i];
			retValor=true;
		} else {
			retValor=false;
		}
	}
	return retValor;
}


int
CJornada::partitsguanyats(const CCadena& nomEquip){
	int valor=0;
	int total=0;
	for(int i=0;i<m_partitsjornada;i++)
		{
			int local=m_objectes[i].GetGolsLocal();
			int visit=m_objectes[i].GetGolsVisitant();
			if(m_objectes[i].GetLocal()==nomEquip){
				if(local>visit){
					total = total + 1;
				}
			} else if (m_objectes[i].GetVisitant()==nomEquip){
				if(local<visit){
					total = total + 1;
				}
			}
			valor = total;
		}
	return valor;
}

int
CJornada::partitsempatats(const CCadena& nomEquip){
	int total=0;
	for(int i=0;i<m_partitsjornada;i++)
		{
			if(m_objectes[i].GetLocal()==nomEquip || m_objectes[i].GetVisitant()==nomEquip){
				if(m_objectes[i].GetGolsLocal()==m_objectes[i].GetGolsVisitant()){
					total = total +1;
				}
			}
		}
	return total;
}

int
CJornada::partitsperduts(const CCadena& nomEquip){
	int total=0;
	for(int i=0;i<m_partitsjornada;i++)
		{
			int gollocal = m_objectes[i].GetGolsLocal();
			int golvisit = m_objectes[i].GetGolsVisitant();
			if(m_objectes[i].GetLocal()==nomEquip){
				if(gollocal<golvisit){
					total = total +1;
				}
			} else if (m_objectes[i].GetVisitant()==nomEquip){
				if(gollocal>golvisit){
					total = total +1;
				}
			}
		}
	return total;
}


CJornada::CJornada(const CJornada& obj){
	int i;
	m_numJornada=obj.m_numJornada;
	m_data=obj.m_data;
	m_partitsjornada = obj.m_partitsjornada;
	m_objectes = obj.m_objectes;

	if(m_objectes>0){
		m_objectes = new CPartit[m_partitsjornada];

		for (i=0;i<m_partitsjornada;i++){
			m_objectes[i]=obj.m_objectes[i];
		}
	}else {
		m_objectes=0;
	}
}



CJornada&
CJornada::operator=(const CJornada& obj){
	if (this != &obj){
		int i;
		if(m_objectes!=0){
			delete[] m_objectes;
		}
		m_numJornada=obj.m_numJornada;
		m_data=obj.m_data;
		m_partitsjornada=obj.m_partitsjornada;
		m_objectes=obj.m_objectes;

		if(m_objectes>0){
			m_objectes = new CPartit[m_partitsjornada];
			for (i=0;i<m_partitsjornada;i++){
				m_objectes[i]=obj.m_objectes[i];
			}
		}else {
			m_objectes=0;
		}
	}
	return (*this);

}

