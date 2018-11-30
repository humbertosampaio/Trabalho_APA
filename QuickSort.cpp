/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "QuickSort.h"

void QuickSort::sort(vector<int> &vect)
{
    quickSortRec(vect, 0, vect.size());
}

void QuickSort::quickSortRec(vector<int> &vect, int ini, int fim)
{
    int i, j;
    i = ini;
    j = fim - 1;
    int pivot = vect[(ini + fim) / 2];

    // Particionamento
    while (i <= j) {
        while (vect[i] < pivot && i < fim) {
            i++;
        }
        while (vect[j] > pivot && j > ini) {
            j--;
        }
        if (i <= j) {
            int aux = vect[i];
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