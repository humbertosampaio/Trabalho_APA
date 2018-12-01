/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "FileReader.h"

unsigned long int FileReader::readSortInstance(vector<int> &vet, string path)
{
	ifstream file(path);

	int n;
	if (file.is_open())
	{
		file >> n;
		file >> n;
		while (file >> n)
			vet.push_back(n);
	}
	else
		printErrorMessage();

	file.close();
	return vet.size();
}

unsigned long int FileReader::readSortInstanceSize(string path)
{
	ifstream file(path);

	unsigned long int n = 0;
	if (file.is_open())
	{
		file >> n;
		file >> n;
	}
	else
		printErrorMessage();

	file.close();
	return n;
}

unsigned long int FileReader::readMSTInstance(Graph& graph, string path)
{
	ifstream file(path);

	unsigned long int V;
	int nodeA, nodeB;
	if (file.is_open())
	{
		file >> V;
		while (file >> nodeA >> nodeB)
			graph.addEdge(nodeA, nodeB, 0);
	}
	else
		printErrorMessage();

	file.close();
	return V;
}

unsigned long int FileReader::readMSTInstanceSize(string path)
{
	ifstream file(path);

	unsigned long int n = 0;
	if (file.is_open())
		file >> n;
	else
		printErrorMessage();

	file.close();
	return n;
}

void FileReader::printErrorMessage()
{
	cout << "Erro ao abrir o arquivo. Talvez voce tenha inserido o caminho errado. Por favor, tente novamente." << endl;
}
