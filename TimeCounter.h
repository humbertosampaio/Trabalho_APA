/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHO_APA_TIMECOUNTER_H
#define TRABALHO_APA_TIMECOUNTER_H

#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class TimeCounter
{
	public:
	static void printTimeSpent(string algorithmName, clock_t start, clock_t end);
};

#endif