/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "TimeCounter.h"

void TimeCounter::printTimeSpent(string algorithmName, clock_t start, clock_t end)
{
	cout << endl << algorithmName << " -> Tempo gasto na execucao: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl << endl;
}

 void TimeCounter::printTimeSpent(unsigned long int size, clock_t start, clock_t end)
 {
	 stringstream ss;
	 ss << endl << "Tamanho da instancia: " << size;
	 ss << endl << "Tempo gasto na execucao: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl << endl;
	 cout << ss.str();
 }
