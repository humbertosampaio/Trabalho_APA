/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHO_APA_QUICKSORT_H
#define TRABALHO_APA_QUICKSORT_H

#include <vector>

using namespace std;

class QuickSort {
public:

    static void sort(vector<int> &vect);
private:
    static void quickSortRec(vector<int> &vect, int ini, int fim);
};


#endif
