#include "stdafx.h"
#include "../Lab2_1/DivideByHalfOfMax.h"

BOOST_AUTO_TEST_SUITE(VectorTests)

BOOST_AUTO_TEST_CASE(biggestIsLast)
{
	std::vector<double> startVector = { 1, 2, 3, 5 };
	std::vector<double> resultVector = { 0.400, 0.800, 1.200, 2.000 };
	startVector = DivideToAHalfOfMaxElement(startVector);
	BOOST_CHECK(startVector == resultVector);
}

BOOST_AUTO_TEST_CASE(biggestIsFirst)
{
	std::vector<double> startVector = { 5, 2, 3, 1 };
	std::vector<double> resultVector = { 2.000, 0.800, 1.200, 0.400 };
	startVector = DivideToAHalfOfMaxElement(startVector);
	BOOST_CHECK(startVector == resultVector);
}

BOOST_AUTO_TEST_CASE(zeroInVector)
{
	std::vector<double> startVector = { 0, 2, 3, 5 };
	std::vector<double> resultVector = { 0.000, 0.800, 1.200, 2.000 };
	startVector = DivideToAHalfOfMaxElement(startVector);
	BOOST_CHECK(startVector == resultVector);
}

BOOST_AUTO_TEST_SUITE_END()