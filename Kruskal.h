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
#include <math.h>

#include "FileHandler.h"
#include "QuickSort.h"
#include "QuickSort.cpp"

using namespace std;

typedef pair<int, int> NodePair;
typedef pair<int, NodePair> Edge; // <PesoAresta, Nos>

class Node
{
	public:
	Node(unsigned long int id, int x, int y);
	unsigned long int getId();
	int getX();
	int getY();

	private:
	unsigned long int id;
	int x, y;
};

class Graph
{
	public:
	Graph(int V);

	// Retorna a quantidade de nos na instancia
	static unsigned long int readMSTInstanceSize(string path);
	static unsigned long int readMSTInstance(Graph& graph, string path);

	void addNode(unsigned long int id, int x, int y);
	void addEdge(int from, int to, int weigth);
	void addAllEdges();
	int generateKruskalMST();
	vector<Edge> mstEdges;		// Vetor de arestas do resultado

	private:
	int V, maxId;				// Quantidade de nos, maior id de um no
	vector<Edge> edges;			// Vetor de arestas
	vector<Node> nodes;			// Vetor de nos
};

// Representa as sub-arvores utilizadas no processo
// de criacao da AGM
class DisjointSet
{
	public:
	DisjointSet(int size);
	int findSetRoot(int node);			// Encontra a raiz de um conjunto usando Path Compression
	void merge(int nodeA, int nodeB);	// Une dois conjuntos disjuntos

	private:
	int* parent;
	int* rank;
	int size;
};

#endif
