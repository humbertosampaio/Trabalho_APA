/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#ifndef TRABALHOAPAHUMBERTO_FILEREADER_H
#define TRABALHOAPAHUMBERTO_FILEREADER_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class FileReader {
public:
    vector<int> readInstance(vector<int> &vet, string path);
};


#endif //TRABALHOAPAHUMBERTO_FILEREADER_H
