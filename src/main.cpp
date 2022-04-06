
/*
 * main.cpp
 *

 */

// Programa principal

// C++ headers
#include <iostream>
#include <fstream>
#include <cstdlib> // EXIT_SUCCESS
using namespace std;

// Llista de includes a afegir

#include "repte050a.h"

int
main(int argc, char const *argv[])
{
	ofstream fitxer;

	fitxer.open("repte050a.txt");
	Repte050a(cout);
	Repte050a(fitxer);
	fitxer.close();

	return EXIT_SUCCESS;
}
