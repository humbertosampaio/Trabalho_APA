/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHO_APA_FILEHANDLER_H
#define TRABALHO_APA_FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

class FileHandler
{
	public:
	// Retorna o tamanho do vetor lido
	static unsigned long int readSortInstance(vector<unsigned long int> &vec, string path);
	static unsigned long int readSortInstanceSize(string path);

	// Retorna a quantidade de nos no grafo
	static unsigned long int readMSTInstanceSize(string path);

	static vector<unsigned long int> readGolombInstance(string path);

	static void writeToOutputFile(const string &outputFileName, const string &text);
	static void writeToOutputFile(const string& outputFileName, stringstream& text);
	static void printTimeSpent(unsigned long int size, clock_t start, clock_t end);

	static void printErrorMessage(string fileName);
	static void clearOutputFileContents(string path);
};


#endif
