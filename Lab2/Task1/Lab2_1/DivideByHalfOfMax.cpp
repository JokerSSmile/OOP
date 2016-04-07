#include "stdafx.h"
#include "DivideByHalfOfMax.h"

std::vector<double> ReadInputToVector()
{
	std::cout << "Enter numbers. Type any letter to stop:\n";
	std::vector<double> vec((std::istream_iterator<double>(std::cin)), std::istream_iterator<double>());

	return vec;
}

std::vector<double> DivideToAHalfOfMaxElement(std::vector<double>& vec)
{
	if (vec.size() == 0)
	{
		return vec;
	}

	std::vector<double> resultVec = vec;
	double maxElement = *std::max_element(resultVec.begin(), resultVec.end());

	if (maxElement == 0)
	{
		return vec;
	}

	for (auto& element : resultVec)
	{
		element = element / (maxElement / 2);
	}
	return resultVec;
}

void SortVector(std::vector<double>& vec)
{
	std::sort(vec.begin(), vec.end());
}

void OutputVector(const std::vector<double>& vec)
{
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<double>(std::cout << std::fixed << std::setprecision(3), " "));
	std::cout << std::endl;
}