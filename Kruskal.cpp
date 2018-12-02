/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "Kruskal.h"

// Graph
Graph::Graph(int V)
{
	this->V = V;
	this->maxId = 1;
}

void Graph::addNode(unsigned long int id, int x, int y)
{
	this->nodes.emplace_back(id, x, y);
	if (this->maxId < id)
		this->maxId = id;
}

unsigned long int Graph::readMSTInstanceSize(string path)
{
	ifstream file(path);

	unsigned long int n = 0;
	if (file.is_open())
	{
		file >> n;
		file.close();
	}

	return n;
}

unsigned long int Graph::readMSTInstance(Graph& graph, string path)
{
	srand(time(NULL));
	ifstream file(path);
	unsigned long int V = 0, cont = 0;
	int x, y, weigth;
	if (file.is_open())
	{
		file >> V;
		while (file >> x >> y)
		{
			graph.addNode(++cont, x, y);
		}
		file.close();
		graph.addAllEdges();
	}

	return V;
}

void Graph::addEdge(int from, int to, int weigth)
{
	edges.push_back({ weigth, {from, to} });
}

void Graph::addAllEdges()
{
	auto itA = this->nodes.begin();
	while (itA != this->nodes.end())
	{
		auto itB = this->nodes.begin();
		itB++;
		while (itB != this->nodes.end())
		{
			unsigned long int idA = (*itA).getId(), idB = (*itB).getId();
			if (idA < idB)
			{
				long int x = (*itA).getX() - (*itB).getX();
				long int y = (*itA).getY() - (*itB).getY();
				float distance = sqrt(pow(x, 2) + pow(y, 2));
				addEdge(idA, idB, distance);
			}
			itB++;
		}

		itA++;
	}
}

int Graph::generateKruskalMST()
{
	this->mstEdges.clear();

	clock_t start = clock();
	int mstWeigth = 0;

	// Ordenação em ordem crescente com base no peso
	QuickSort::sort(this->edges, false);

	DisjointSet disjointSet(V);
	unsigned long int edgesInSolution = 0;
	vector<Edge>::iterator it = this->edges.begin();
	while ((it != this->edges.end()) && (edgesInSolution < V - 1))
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


// Node
Node::Node(unsigned long int id, int x, int y)
{
	this->id = id;
	this->x = x;
	this->y = y;
}

unsigned long int Node::getId()
{
	return this->id;
}

int Node::getX()
{
	return this->x;
}

int Node::getY()
{
	return this->y;
}


// DisjointSet
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

int DisjointSet::findSetRoot(int node)
{
	// Define o pai dos nos no caminho ate a raiz
	// para todos apontarem diretamente para ela
	if (node != this->parent[node])
		this->parent[node] = findSetRoot(this->parent[node]);

	return this->parent[node];
}

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
