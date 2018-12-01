/*
 * Nome: Humberto de Oliveira Sampaio
 * Matrícula: 201635012
 */

#include "Golomb.h"

// Print the first n term
// of Golomb Sequence
void Golomb::printGolombSequence(unsigned long n)
{
	clock_t start = clock();

	unsigned long *dp = new unsigned long[n + 1];

	// base cases
	dp[1] = 1;
	cout << dp[1] << " ";

	// Finding and printing first
	// n terms of Golomb Sequence.
	for (unsigned long i = 2; i <= n; i++)
	{
		dp[i] = 1 + dp[i - dp[dp[i - 1]]];
		cout << dp[i] << " ";
	}
	cout << endl;
	delete[] dp;

	TimeCounter::printTimeSpent("Sequencia de Golomb", start, clock());
}
