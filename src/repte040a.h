/*
 * repte040a.h
 *
 */

#ifndef REPTE040A_H_
#define REPTE040A_H_

#include <iostream>
using namespace std;

#include "jornada.h"

void Repte040a(ostream& os);

CJornada CarregaFitxer(const char* nomFitxer);

void MostraJornada(ostream& os, CJornada jornada);



#endif /* REPTE040A_H_ */
