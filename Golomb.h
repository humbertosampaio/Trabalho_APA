/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHOAPAHUMBERTO_GOLOMB_H
#define TRABALHOAPAHUMBERTO_GOLOMB_H

#include <iostream>
#include <time.h>
#include <vector>

#include "TimeCounter.h"

using namespace std;

class Golomb
{
	public:
	// Gera os maxIndex primeiros numeros a Sequencia de Golombs
	static void golombSequence(vector<unsigned long int>& vec, unsigned long n);
};


#endif
