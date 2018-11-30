/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHOAPAHUMBERTO_QUICKSORT_H
#define TRABALHOAPAHUMBERTO_QUICKSORT_H

#include <vector>

using namespace std;

class QuickSort {
public:

    static void sort(vector<int> &vect);
private:
    static void quickSortRec(vector<int> &vect, int ini, int fim);
};


#endif //TRABALHOAPAHUMBERTO_QUICKSORT_H
