/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHO_APA_HEAPSORT_H
#define TRABALHO_APA_HEAPSORT_H

#include <vector>
#include <time.h>

#include "FileHandler.h"

using namespace std;

class HeapSort
{
	public:
	static void sort(vector<unsigned long int> &vec);

	private:
	static void Heapify(vector<unsigned long int> &vec, int rootIndex, int length);
};


#endif //TRABALHOAPAHUMBERTO_HEAPSORT_H
