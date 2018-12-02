/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHO_APA_QUICKSORT_H
#define TRABALHO_APA_QUICKSORT_H

#include <vector>
#include <time.h>

#include "FileHandler.h"

using namespace std;

class QuickSort
{
	public:
	template<class T> static void sort(vector<T> &vect, bool showTimeSpent);

	private:
	template<class T> static void quickSortRec(vector<T> &vect, int ini, int fim);
};


#endif
