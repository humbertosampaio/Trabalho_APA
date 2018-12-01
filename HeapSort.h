/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHO_APA_HEAPSORT_H
#define TRABALHO_APA_HEAPSORT_H

#include <vector>

using namespace std;

class HeapSort
{
	public:
	static void sort(vector<int> &vet);

	private:
	static void Heapify(vector<int> &vet, int rootIndex, int length);
};


#endif //TRABALHOAPAHUMBERTO_HEAPSORT_H
