/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "Kruskal.h"

Graph::Graph(int V)
{
	this->V = V;
}

void Graph::addEdge(int nodeFrom, int nodeTo, int weigth)
{
	this->edges.push_back({ weigth, {nodeFrom, nodeTo} });
}

DisjointSets::DisjointSets(int n)
{
	// Allocate memory 
	this->n = n;
	parent = new int[n + 1];
	rank = new int[n + 1];

	// Initially, all vertices are in 
	// different sets and have rank 0. 
	for (int i = 0; i <= n; i++)
	{
		rank[i] = 0;

		//every element is parent of itself 
		parent[i] = i;
	}
}

// Find the parent of a node
// Path Compression 
int DisjointSets::find(int node)
{
	/* Make the parent of the nodes in the path
	from u--> parent[u] point to parent[u] */
	if (node != parent[node])
		parent[node] = find(parent[node]);
	return parent[node];
}

// Union by rank 
void DisjointSets::merge(int nodeA, int nodeB)
{
	nodeA = find(nodeA), nodeB = find(nodeB);

	/* Make tree with smaller height
	a subtree of the other tree */
	if (rank[nodeA] > rank[nodeB])
		parent[nodeB] = nodeA;
	else // If rank[nodeA] <= rank[nodeB] 
		parent[nodeA] = nodeB;

	if (rank[nodeA] == rank[nodeB])
		rank[nodeB]++;
}

int Graph::generateKruskalMST()
{
	clock_t start = clock();

	// Initialize result 
	int mstWeigth = 0;

	// Sort edges in increasing order on basis of cost
	QuickSort::sort(edges);
	//sort(edges.begin(), edges.end());

	// Create disjoint sets 
	DisjointSets disjointSets(V);

	// Iterate through all sorted edges 
	vector<Edge>::iterator it;
	for (it = edges.begin(); it != edges.end(); it++)
	{
		int nodeFrom = it->second.first;
		int nodeTo = it->second.second;

		int setFrom = disjointSets.find(nodeFrom);
		int setTo = disjointSets.find(nodeTo);

		// Check if the selected edge is creating 
		// a cycle or not (Cycle is created if u 
		// and v belong to same set) 
		if (setFrom != setTo)
		{
			// Current edge will be in the MST, so print it 
			cout << nodeFrom << " - " << nodeTo << endl;

			// Update MST weight 
			mstWeigth += it->first;

			// Merge two sets 
			disjointSets.merge(setFrom, setTo);
		}
	}

	TimeCounter::printTimeSpent("AGM por Kruskal", start, clock());

	return mstWeigth;
}

