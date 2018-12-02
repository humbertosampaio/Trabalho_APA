/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "HeapSort.h"


void HeapSort::sort(vector<unsigned long int> &vec)
{
	clock_t start = clock();

	int length = vec.size();
	for (int i = (length / 2) - 1; i >= 0; i--)
	{
		Heapify(vec, i, length);
	}

	while (length > 0)
	{
		int maior = vec[0];
		vec[0] = vec[length - 1];
		vec[length - 1] = maior;
		Heapify(vec, 0, --length);
	}

	FileHandler::printTimeSpent(vec.size(), start, clock());
}

void HeapSort::Heapify(vector<unsigned long int> & v, int rootIndex, int length)
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