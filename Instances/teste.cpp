
#include <iostream>

using namespace std;

int main()
{
	path = "E:\Code\Trabalho_APA\Instances";
	ifstream file(path);

	unsigned long int V, cont = 0;
	int nodeA, nodeB;
	if (file.is_open())
	{
		file >> V;
		while (file >> nodeA >> nodeB)
			graph.addNode(++cont, nodeA, nodeB);

		graph.addAllEdges();
	}

	file.close();
	return V;
}