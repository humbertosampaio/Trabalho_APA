/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "Golomb.h"

void Golomb::golombSequence(vector<unsigned long int>& vec, unsigned long maxIndex)
{
	clock_t start = clock();

	if (vec.size() < maxIndex + 1)
		vec.resize(maxIndex + 1);

	vec[1] = 1;
	//cout << vec[1] << " ";

	for (unsigned long i = 2; i <= maxIndex; i++)
	{
		vec[i] = 1 + vec[i - vec[vec[i - 1]]];
		//cout << vec[i] << " ";
	}

	FileHandler::printTimeSpent(maxIndex, start, clock());
}
