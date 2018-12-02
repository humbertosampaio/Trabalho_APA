/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "FileHandler.h"

unsigned long int FileHandler::readSortInstance(vector<unsigned long int> &vec, string path)
{
	ifstream file(path);

	int n;
	if (file.is_open())
	{
		file >> n;
		file >> n;
		while (file >> n)
			vec.push_back(n);
		file.close();
	}

	return vec.size();
}

unsigned long int FileHandler::readSortInstanceSize(string path)
{
	ifstream file(path);

	unsigned long int n = 0;
	if (file.is_open())
	{
		file >> n;
		file >> n;
		file.close();
	}

	return n;
}

unsigned long int FileHandler::readMSTInstance(Graph& graph, string path)
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

unsigned long int FileHandler::readMSTInstanceSize(string path)
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

vector<unsigned long int> FileHandler::readGolombInstance(string path)
{
	vector<unsigned long int> vec;

	ifstream file(path);

	unsigned long int n;
	if (file.is_open())
	{
		while (file >> n)
			vec.push_back(n);
		file.close();
	}

	return vec;
}

void FileHandler::writeToOutputFile(const string &outputFileName, const string &text)
{
	ofstream writer(outputFileName, ios::app);
	if (writer.is_open())
	{
		writer << text << endl;
		writer.close();
	}
	else
		cout << "Falha ao abrir o arquivo \"" << outputFileName << "\" para escrita." << endl;
}

void FileHandler::writeToOutputFile(const string& outputFileName, stringstream& stream)
{
	ofstream writer(outputFileName, ios::app);
	if (writer.is_open())
	{
		writer << stream.str();
		stream.str(std::string());
		writer.close();
	}
	else
		cout << "Falha ao abrir o arquivo \"" << outputFileName << "\" para escrita." << endl;
}

void FileHandler::printErrorMessage(string fileName)
{
	cout << "Arquivo " << fileName << " nao encontrado." << endl;
}

void FileHandler::clearOutputFileContents(string path)
{
	ofstream writer;
	writer.open(path, std::ofstream::out | std::ofstream::trunc);
	writer.close();
}