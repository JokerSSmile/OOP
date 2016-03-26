#include "stdafx.h"
#include <iostream>
#include <memory>
#include "PrimeNumbers.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Input must be:\nLab2_4_Generator.exe <bound>" << endl;
		return 1;
	}
	std::set<int> primeNumbers =  GeneratePrimeNumbersSet(std::stoi(argv[1]));

	OutputNumbers(primeNumbers);

	return 0;
}