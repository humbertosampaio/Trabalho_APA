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

#include "TimeCounter.h"
#include "QuickSort.h"
#include "QuickSort.cpp"

using namespace std;

typedef pair<int, int> IPair;
typedef pair<int, IPair> Edge;

class Graph
{
	public:
	Graph(int V);
	void addEdge(int nodeFrom, int nodeTo, int weigth);
	int generateKruskalMST();

	private:
	int V, E;
	vector<Edge> edges;
};

class DisjointSets
{
	public:
	DisjointSets(int n);
	int find(int node);
	void merge(int nodeA, int nodeB);

	private:
	int* parent, *rank;
	int n;
};

#endif
