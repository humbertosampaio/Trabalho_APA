/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "HeapSort.h"


void HeapSort::sort(vector<int> &vet)
{
	clock_t start = clock();

	int length = vet.size();
	for (int i = (length / 2) - 1; i >= 0; i--)
	{
		Heapify(vet, i, length);
	}

	while (length > 0)
	{
		int maior = vet[0];
		vet[0] = vet[length - 1];
		vet[length - 1] = maior;
		Heapify(vet, 0, --length);
	}

	TimeCounter::printTimeSpent("Heap Sort", start, clock());
}

void HeapSort::Heapify(vector<int> & v, int rootIndex, int length)
{
	int childIndex;
	int rootValue = v[rootIndex];
	while (rootIndex < length / 2)
	{
		childIndex = (rootIndex * 2) + 1;

		if ((childIndex < length - 1) && (v[childIndex] < v[childIndex + 1]))
			++childIndex;

		int childValue = v[childIndex];
		if (rootValue >= childValue)
			break;

		v[rootIndex] = childValue;
		rootIndex = childIndex;
	}
	v[rootIndex] = rootValue;
}