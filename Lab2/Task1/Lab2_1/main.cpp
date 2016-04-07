#include "DivideByHalfOfMax.h"

int main()
{
	std::vector<double> resultVector;
	std::vector<double> givenVector = ReadInputToVector();

	resultVector = DivideToAHalfOfMaxElement(givenVector);
	SortVector(resultVector);
	OutputVector(resultVector);
	return 0;
}