#include "stdafx.h"
#include "../Lab2_4_Generator/PrimeNumbers.h"

BOOST_AUTO_TEST_SUITE(GeneratorTests)

BOOST_AUTO_TEST_CASE(worls_correct_if_bound_is_0)
{
	std::set<int> testSet = {};
	std::set<int> generatedTestSet = GeneratePrimeNumbersSet(0);
	BOOST_CHECK(testSet == generatedTestSet);
}

BOOST_AUTO_TEST_CASE(works_correct_with_bound_100)
{
	std::set<int> testSet = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
	std::set<int> generatedTestSet = GeneratePrimeNumbersSet(100);
	BOOST_CHECK(testSet == generatedTestSet);
}

BOOST_AUTO_TEST_SUITE(tests_if_bound_near_prime_nimbers)

BOOST_AUTO_TEST_CASE(works_correct_with_bound_less_than_prime_number_near_that_bound)
{
	std::set<int> testSet = { 2,3,5,7,11,13,17 };
	std::set<int> generatedTestSet = GeneratePrimeNumbersSet(18);
	BOOST_CHECK(testSet == generatedTestSet);
}

BOOST_AUTO_TEST_CASE(works_correct_with_bound_more_than_prime_number_near_that_bound)
{
	std::set<int> testSet = { 2,3,5,7,11,13,17,19,23,29,31,37 };
	std::set<int> generatedTestSet = GeneratePrimeNumbersSet(38);
	BOOST_CHECK(testSet == generatedTestSet);
}

BOOST_AUTO_TEST_CASE(works_correct_with_bound_equals_to_prime_number)
{
	std::set<int> testSet = { 2,3,5,7,11,13 };
	std::set<int> generatedTestSet = GeneratePrimeNumbersSet(13);
	BOOST_CHECK(testSet == generatedTestSet);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
