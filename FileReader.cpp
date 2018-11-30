/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "FileReader.h"

vector<int> FileReader::readInstance(vector<int> &vet, string path)
{
    ifstream reader;
    reader.open(path);

    int n;
    if (reader.is_open())
    {
        reader >> n;
        reader >> n;
        while (reader >> n)
        {
            vet.push_back(n);
        }
    }
}
