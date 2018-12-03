/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHO_APA_QUICKSORT_CPP
#define TRABALHO_APA_QUICKSORT_CPP

#include "QuickSort.h"

template<class T> void QuickSort::sort(vector<T> &vect, bool showTimeSpent)
{
	clock_t start = clock();
	quickSortRec(vect, 0, vect.size());

	// Quando o Quick Sort é chamado pelo algoritmo de Kruskal,
	// não é desejado que ele gere saídas
	if (showTimeSpent)
		FileHandler::printTimeSpent(vect.size(), start, clock());
}

template<class T> void QuickSort::quickSortRec(vector<T> &vect, int start, int end)
{
	int i, j;
	i = start;
	j = end - 1;
	T pivot = vect[(start + end) / 2];

	// Particionamento
	while (i <= j)
	{
		while (vect[i] < pivot && i < end)
			i++;

		while (vect[j] > pivot && j > start)
			j--;

		if (i <= j)
		{
			T aux = vect[i];
			vect[i] = vect[j];
			vect[j] = aux;
			i++;
			j--;
		}
	}

	///Chamadas recursivas
	if (j > start)
		quickSortRec(vect, start, j + 1);
	if (i < end)
		quickSortRec(vect, i, end);
}

#endif

