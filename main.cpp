/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include <iostream>
#include <algorithm>

#include "Golomb.h"
#include "QuickSort.h"
#include "HeapSort.h"

#define RANDOM_SEED std::chrono::system_clock::now().time_since_epoch().count()

using namespace std;

void showRootMenu(bool showHeader);
void showHeader();
void showParadigmOptions();
void execQuickSort();
void execHeapSort();
void execGolomb();
void execKruskal();
vector<int> getRandomVector(unsigned long n);
void printVector(vector<int> &vet);

int main()
{
    showRootMenu(true);
    return 0;
}

void showRootMenu(bool showHeaderString)
{
//    if (showHeaderString)
//        showHeader();
    showParadigmOptions();
    int paradigm = 0;
    cin >> paradigm;
    while (paradigm < 1 || paradigm > 4)
    {
        cout << "teste" << endl;
        switch (paradigm)
        {
            case 1:
                execHeapSort();
                break;
            case 2:
                execQuickSort();
                break;
            case 3:
                execGolomb();
                break;
            case 4:
                execKruskal();
                break;
            default:
                cout << "Opcao invalida. Por favor, insira um numero entre 1 e 4" << endl;
                showParadigmOptions();
                cin >> paradigm;
                break;
        }
    }

    char yn;
    do
    {
        cout << "Executar novamente? (Y/N)" << endl;
        cin >> yn;

        if (yn == 'Y' || yn == 'y')
        {
            cout << endl;
            showRootMenu(false);
        }
        else if (yn == 'N' || yn == 'n')
            return;

        cout << "Opcao invalida. Por favor, insira Y ou N" << endl;
    } while (yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n');

}

void showHeader()
{
    cout << "****** ANALISE E PROJETO DE ALGORITMOS ******" << endl;
    cout << "Nome: Humberto de Oliveira Sampaio" << endl << "Matricula: 201635012" << endl << endl;
}

void showParadigmOptions()
{
    cout << "Escolha o paradigma: " << endl;
    cout << "1 - Incremental" << endl << "2 - Divisao e conquista" << endl;
    cout << "3 - Programacao Dinamica" << endl << "4 - Algoritmo guloso" << endl << endl;
}

void execHeapSort()
{
    cout << "** Heap sort: **" << endl;
    cout << "Insira o tamanho desejado para o vetor: ";
    unsigned long size;
    cin >> size;
    vector<int> vet = getRandomVector(size);
    HeapSort::sort(vet);
    vet.clear();
}

void execQuickSort()
{
    cout << "** Quick sort: **" << endl;
    cout << "Insira o tamanho desejado para o vetor: ";
    unsigned long size;
    cin >> size;
    vector<int> vet = getRandomVector(size);
    QuickSort::sort(vet);
    vet.clear();
}

void execGolomb()
{
    cout << "**  Sequencia de Golomb **";
    cout << "Insira a quantidade de elementos da sequencia a ser mostrada: ";
    unsigned long n;
    cin >> n;
    Golomb::printGolomb(n);
}

void execKruskal()
{

}

vector<int> getRandomVector(unsigned long n)
{
    vector<int> vet(n);
    for (unsigned long i = 0; i < n; ++i)
    {
        vet.push_back(i);
    }
    random_shuffle(vet.begin(), vet.end());
}

void printVector(vector<int> &vet)
{
    for (auto it = vet.begin(); it != vet.end(); it++)
    {
        cout << *it <<  " ";
    }
}