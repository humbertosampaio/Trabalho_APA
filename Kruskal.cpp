/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "Kruskal.h"

Graph::Graph(int V)
{
	this->V = V;
}

unsigned long int Graph::readMSTInstance(Graph& graph, string path)
{
	srand(time(NULL));
	ifstream file(path);
	unsigned long int V = 0, cont = 0;
	int nodeA, nodeB, weigth;
	if (file.is_open())
	{
		file >> V;
		while (file >> nodeA >> nodeB >> weigth)
		{
			graph.addEdge(nodeA, nodeB, weigth);
		}
		file.close();
	}

	return V;
}
void Graph::addEdge(int from, int to, int weigth)
{
	edges.push_back({ weigth, {from, to} });
}

int Graph::generateKruskalMST(bool outputResult)
{
	clock_t start = clock();
	int mstWeigth = 0;

	// Ordenação em ordem crescente com base no peso
	QuickSort::sort(this->edges, false);

	DisjointSet disjointSet(V);
	unsigned long int edgesInSolution = 0;
	vector<Edge>::iterator it = this->edges.begin();
	while ((it != this->edges.end() && edgesInSolution < V - 1))
	{
		NodePair nodePair = it->second;
		int nodeA = nodePair.first;
		int nodeB = nodePair.second;

		int rootFromSetA = disjointSet.findSetRoot(nodeA);
		int rootFromSetB = disjointSet.findSetRoot(nodeB);

		// Se true, os nos pertencem a conjuntos diferentes 
		if (rootFromSetA != rootFromSetB)
		{
			// Adiciona o peso da aresta entre esses nos no peso da AGM
			mstWeigth += it->first;

			// Aresta estara na solucao
			this->mstEdges.push_back(*it);

			// Inclui aresta na solucao
			disjointSet.merge(rootFromSetA, rootFromSetB);
		}

		++it;
	}

	FileHandler::printTimeSpent(V, start, clock());

	return mstWeigth;
}


DisjointSet::DisjointSet(int size)
{
	this->size = size;
	this->parent = new int[size + 1];
	this->rank = new int[size + 1];

	// Inicializa com vertices em conjuntos diferentes e ranque = 0
	for (int i = 0; i <= size; i++)
	{
		this->rank[i] = 0;
		this->parent[i] = i;
	}
}

// Encontra o pai de um nó usando Path Compression
int DisjointSet::findSetRoot(int node)
{
	// Define o pai dos nos no caminho ate a raiz
	// para todos apontarem diretamente para ela
	if (node != this->parent[node])
		this->parent[node] = findSetRoot(this->parent[node]);

	return this->parent[node];
}

// Une dois conjuntos disjuntos
void DisjointSet::merge(int nodeA, int nodeB)
{
	nodeA = findSetRoot(nodeA), nodeB = findSetRoot(nodeB);

	// Define a raiz com menor ranque, a raiz de uma
	// sub-arvore da raiz com maior ranque
	if (this->rank[nodeA] > this->rank[nodeB])
		this->parent[nodeB] = nodeA;
	else // if rank[nodeA] <= rank[nodeB] 
		this->parent[nodeA] = nodeB;

	if (this->rank[nodeA] == this->rank[nodeB])
		this->rank[nodeB]++;
}
