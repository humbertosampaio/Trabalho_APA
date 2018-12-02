/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "QuickSort.h"

#ifndef TRABALHO_APA_QUICKSORT_CPP
#define TRABALHO_APA_QUICKSORT_CPP

template<class T> void QuickSort::sort(vector<T> &vect, bool showTimeSpent)
{
	clock_t start = clock();
	quickSortRec(vect, 0, vect.size());

	if (showTimeSpent)
		TimeCounter::printTimeSpent(vect.size(), start, clock());
}

template<class T> void QuickSort::quickSortRec(vector<T> &vect, int ini, int fim)
{
	int i, j;
	i = ini;
	j = fim - 1;
	T pivot = vect[(ini + fim) / 2];

	// Particionamento
	while (i <= j)
	{
		while (vect[i] < pivot && i < fim)
			i++;

		while (vect[j] > pivot && j > ini)
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
	if (j > ini)
		quickSortRec(vect, ini, j + 1);
	if (i < fim)
		quickSortRec(vect, i, fim);
}

#endif

