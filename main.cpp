/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include <iostream>

#include "Golomb.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "FileReader.h"
#include "Kruskal.h"

using namespace std;

void showRootMenu(string sortPath, string graphPath, bool showHeader);
void showHeader();
void showParadigmOptions();
void execHeapSort(string &instancePath);
void execQuickSort(string &instancePath);
void execGolomb();
void execKruskal(string &instancePath);
void printVector(vector<int> &vet);

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		cout << "Argumentos invalidos! Os argumentos necessarios sao: " << endl;
		cout << "[path_instancia_ordenacao] [path_instancia_grafo_para_AGM]" << endl;
		return 0;
	}

	showRootMenu(argv[1], argv[2], true);
	return 0;
}

void showRootMenu(string sortPath, string graphPath, bool showHeaderString)
{
	//if (showHeaderString)
	//	showHeader();

	showParadigmOptions();
	int paradigm;
	cin >> paradigm;

	do
	{
		switch (paradigm)
		{
			case 1:
				execHeapSort(sortPath);
				break;
			case 2:
				execQuickSort(sortPath);
				break;
			case 3:
				execGolomb();
				break;
			case 4:
				execKruskal(graphPath);
				break;
			default:
				cout << "Opcao invalida. Por favor, insira um numero entre 1 e 4" << endl;
				showParadigmOptions();
				cin >> paradigm;
				break;
		}
	} while (paradigm < 1 || paradigm > 4);

	char yn;
	do
	{
		cout << "Executar novamente? (Y/N)" << endl;
		cin >> yn;

		if (yn == 'Y' || yn == 'y')
		{
			cout << endl;
			showRootMenu(sortPath, graphPath, false);
		}
		else if (yn == 'N' || yn == 'n')
		{
			cout << "Fechando sistema..." << endl;
			return;
		}

		cout << "Opcao invalida. Por favor, insira Y ou N" << endl;
	} while (yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n');

}

void showHeader()
{
	cout << "*********************************************************************" << endl;
	cout << "****************** ANALISE E PROJETO DE ALGORITMOS ******************" << endl;
	cout << "*********************************************************************" << endl;
	cout << "* Nome: Humberto de Oliveira Sampaio                                *" << endl;
	cout << "* Matricula: 201635012                                              *" << endl;
	cout << "*********************************************************************" << endl << endl;
}

void showParadigmOptions()
{
	cout << "Escolha o paradigma: " << endl;
	cout << "1 - Incremental" << endl << "2 - Divisao e conquista" << endl;
	cout << "3 - Programacao Dinamica" << endl << "4 - Algoritmo guloso" << endl << endl;
}

void execHeapSort(string &instancePath)
{
	cout << "** Heap sort: **" << endl;
	unsigned long int size = FileReader::readSortInstanceSize(instancePath);
	vector<int> vet(size);

	if (FileReader::readSortInstance(vet, instancePath) == 0)
		return;

	FileReader::readSortInstance(vet, instancePath);
	HeapSort::sort(vet);
	cout << "Vetor ordenado: " << endl;
	printVector(vet);
	vet.clear();
}

void execQuickSort(string &instancePath)
{
	cout << "** Quick sort: **" << endl;
	unsigned long int size = FileReader::readSortInstanceSize(instancePath);
	vector<int> vet(size);

	if (FileReader::readSortInstance(vet, instancePath) == 0)
		return;

	QuickSort::sort(vet);
	cout << "Vetor ordenado: " << endl;
	printVector(vet);
	vet.clear();
}

void execGolomb()
{
	cout << "**  Sequencia de Golomb **" << endl;
	cout << "Insira a quantidade de elementos da sequencia a ser mostrada: ";
	unsigned long int n;
	cin >> n;
	cout << "Sequencia de Golomb ate o " << n << "o digito:" << endl;
	Golomb::printGolomb(n);
}

void execKruskal(string &instancePath)
{
	cout << "** Alg. de Kruskal para Arvore Geradora Minima **" << endl;
	int V = FileReader::readMSTInstanceSize(instancePath);

	if (V == 0)
		return;

	Graph g = Graph(V);
	FileReader::readMSTInstance(g, instancePath);
	cout << "Nos em que existem arestas entre si:" << endl;
	g.generateKruskalMST();

}

void printVector(vector<int> &vet)
{
	for (int &it : vet)
		cout << it << " ";
	cout << endl << endl;
}