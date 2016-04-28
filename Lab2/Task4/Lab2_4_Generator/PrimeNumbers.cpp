#include "stdafx.h"
#include "PrimeNumbers.h"

std::set<int> GeneratePrimeNumbersSet(const int& upperBound)
{
	std::set<int> primeNumbers;
	std::vector<bool> isPrimeNumber(upperBound + 1);
	std::fill(isPrimeNumber.begin(), isPrimeNumber.end(), true);

	size_t startNumber = 2;

	for (size_t currentNumber = startNumber; currentNumber * currentNumber <= upperBound; currentNumber++)
	{
		if (currentNumber % 2 == 0 && currentNumber != 2)
		{
			continue;
		}
		for (size_t i = currentNumber * currentNumber; i <= upperBound; i += currentNumber)
		{
			isPrimeNumber[i] = false;
		}
	}

	for (size_t k = 2; k <= upperBound; k++)
	{
		if (isPrimeNumber[k] == true)
		{
			primeNumbers.insert(primeNumbers.end(), k);
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