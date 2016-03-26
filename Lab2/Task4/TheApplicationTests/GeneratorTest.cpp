#include "stdafx.h"
#include "../Lab2_4_Generator/PrimeNumbers.h"

BOOST_AUTO_TEST_SUITE(GeneratorTests)

BOOST_AUTO_TEST_CASE(emptyCase)
{
	std::set<int> testSet = {};
	std::set<int> generatedTestSet = GeneratePrimeNumbersSet(0);
	BOOST_CHECK(testSet == generatedTestSet);
}

BOOST_AUTO_TEST_CASE(normalTestCase)
{
	std::set<int> testSet = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	std::set<int> generatedTestSet = GeneratePrimeNumbersSet(25);
	BOOST_CHECK(testSet == generatedTestSet);
}

BOOST_AUTO_TEST_CASE(normalTestCaseTo100)
{
	std::set<int> testSet = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
	std::set<int> generatedTestSet = GeneratePrimeNumbersSet(100);
	BOOST_CHECK(testSet == generatedTestSet);
}

BOOST_AUTO_TEST_SUITE_END()
