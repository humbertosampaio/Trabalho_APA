/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHOAPAHUMBERTO_HEAPSORT_H
#define TRABALHOAPAHUMBERTO_HEAPSORT_H

#include <vector>

using namespace std;

class HeapSort {
public:
    static void sort(vector<int> &vet);

private:

    static void makeHeapForOneRamification(vector<int> &vet, int rootIndex, int length);
    static void makeHeap(vector<int> &vet, int rootIndex, int length);
};


#endif //TRABALHOAPAHUMBERTO_HEAPSORT_H
