#include "stdafx.h"
#include "PrimeNumbers.h"

std::set<int> GeneratePrimeNumbersSet(const int& upperBound)
{
	std::set<int> primeNumbers;
	std::vector<bool> isPrimeNumber(upperBound + 1);
	std::fill(isPrimeNumber.begin(), isPrimeNumber.end(), true);

	size_t currentNumber = 2;

	for (size_t currentNumber = 2; currentNumber * currentNumber <= upperBound; currentNumber++)
	{
		for (size_t i = currentNumber * currentNumber; i <= upperBound; i += currentNumber)
		{
			if (isPrimeNumber[i] == true)
			{
				isPrimeNumber[i] = false;
			}
		}
	}

	for (size_t k = 2; k <= upperBound; k++)
	{
		if (isPrimeNumber[k] == true)
		{
			primeNumbers.insert(k);
		}
	}

	return primeNumbers;
}

void OutputNumbers(const std::set<int>& givenSet)
{
	for (auto number : givenSet)
	{
		cout << number << endl;
	}
}