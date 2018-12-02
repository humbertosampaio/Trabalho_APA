/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHO_APA_TIMECOUNTER_H
#define TRABALHO_APA_TIMECOUNTER_H

#include <iostream>
#include <time.h>
#include <string>
#include <sstream>

#include "FileHandler.h"

using namespace std;

class TimeCounter
{
	public:
	string outputPath;

	static void printTimeSpent(string algorithmName, clock_t start, clock_t end);
	static void printTimeSpent(unsigned long int size, clock_t start, clock_t end);
};

#endif