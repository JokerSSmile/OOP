// TestLab2_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Lab2_1/DivideByHalfOfMax.h"
#include <vector>
	
BOOST_AUTO_TEST_CASE(testCase1)
{
	std::vector<double> startVector = {1, 2, 3, 5};
	std::vector<double> resultVector = {0.400, 0.800, 1.200, 2.000};
	startVector = DivideToAHalfOfMaxElement(startVector);
	//BOOST_CHECK_EQUAL(startVector, resultVector);
}