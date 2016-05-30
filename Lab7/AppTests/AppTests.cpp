#include "stdafx.h"
#include "../FindMaxEx/FindMatrixEx.h"
#include <iostream>

BOOST_AUTO_TEST_SUITE(find_max_tests)

BOOST_AUTO_TEST_CASE(correct_int_max)
{
	std::vector<int> arr = { 1, 5, 3, 7, 32, 5, 0 };
	int maxNum;
	bool result = FindMaxEx(arr, maxNum, [](int left, int right)
		{return left < right;});
	BOOST_CHECK(maxNum == 32);
}

BOOST_AUTO_TEST_CASE(correct_float_max)
{
	std::vector<double> arr = { 1.3, 5.4, 3.3, 7.6, 3, 5, 0 };
	double maxNum;
	bool result = FindMaxEx(arr, maxNum, [](double left, double right)
		{return left < right;});
	BOOST_CHECK(maxNum == 7.6);
}

BOOST_AUTO_TEST_CASE(correct_string_max)
{
	std::vector<std::string> arr = { "hello", "its", "me", "whats", "your", "name" };
	std::string maxStr;
	bool result = FindMaxEx(arr, maxStr, [](std::string left, std::string right)
		{return left < right;});
	BOOST_CHECK(maxStr == "your");
}

BOOST_AUTO_TEST_SUITE_END()