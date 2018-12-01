/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "TimeCounter.h"

void TimeCounter::printTimeSpent(string algorithmName, clock_t start, clock_t end)
{
	cout << endl << algorithmName << " -> Tempo gasto na execucao: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl << endl;
}