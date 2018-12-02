/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHO_APA_KRUSKAL_H
#define TRABALHO_APA_KRUSKAL_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>

#include "FileHandler.h"
#include "QuickSort.h"
#include "QuickSort.cpp"

using namespace std;

typedef pair<int, int> NodePair;

// <PesoAresta, No>
typedef pair<int, NodePair> Edge;

class Graph
{
	public:
	Graph(int V);

	// Retorna a quantidade de nos no grafo
	static unsigned long int readMSTInstanceSize(string path);
	static unsigned long int readMSTInstance(Graph& graph, string path);
	void addEdge(int from, int to, int weigth);
	int generateKruskalMST(bool outputResult);
	vector<Edge> mstEdges;		// Vetor de arestas do resultado

	private:
	int V;						// Quantidade de nos
	vector<Edge> edges;			// Vetor de arestas
};

// Representa as sub-arvores utilizadas no processo
// de criacao da AGM
class DisjointSet
{
	public:
	DisjointSet(int size);
	int findSetRoot(int node);
	void merge(int nodeA, int nodeB);

	private:
	int* parent;
	int* rank;
	int size;
};

#endif
