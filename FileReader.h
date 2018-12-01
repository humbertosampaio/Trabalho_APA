/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHO_APA_FILEREADER_H
#define TRABALHO_APA_FILEREADER_H

#include <iostream>
#include <fstream>
#include <vector>

#include "Kruskal.h"

using namespace std;

class FileReader
{
	public:
	// Retorna o tamanho do vetor lido
	static unsigned long int readSortInstance(vector<int> &vet, string path);
	static unsigned long int readSortInstanceSize(string path);

	// Retorna a quantidade de nos no grafo
	static unsigned long int readMSTInstance(Graph& graph, string path);
	static unsigned long int readMSTInstanceSize(string path);

	static void printErrorMessage();
};


#endif //TRABALHOAPAHUMBERTO_FILEREADER_H
