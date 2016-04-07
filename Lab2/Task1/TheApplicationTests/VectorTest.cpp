#include "stdafx.h"
#include "../Lab2_1/DivideByHalfOfMax.h"

BOOST_AUTO_TEST_SUITE(processVector_function_test)

	BOOST_AUTO_TEST_CASE(vector_doesnt_modifies_if_it_was_empty)
	{
		std::vector<double> startVector = {};
		startVector = DivideToAHalfOfMaxElement(startVector);
		BOOST_CHECK(startVector.size() == 0);
	}

	BOOST_AUTO_TEST_CASE(vector_doesnt_modifies_if_max_element_is_zero)
	{
		std::vector<double> startVector = {0, -2, -1};
		std::vector<double> resultVector = { 0, -2, -1 };
		startVector = DivideToAHalfOfMaxElement(startVector);
		BOOST_CHECK(startVector == resultVector);
	}

	BOOST_AUTO_TEST_SUITE(divide_elements_by_half_of_max)

		BOOST_AUTO_TEST_CASE(if_biggest_is_last)
		{
			std::vector<double> startVector = { 1, 2, 3, 5 };
			std::vector<double> resultVector = { 0.400, 0.800, 1.200, 2.000 };
			startVector = DivideToAHalfOfMaxElement(startVector);
			BOOST_CHECK(startVector == resultVector);
		}

		BOOST_AUTO_TEST_CASE(if_biggest_is_first)
		{
			std::vector<double> startVector = { 5, 2, 3, 1 };
			std::vector<double> resultVector = { 2.000, 0.800, 1.200, 0.400 };
			startVector = DivideToAHalfOfMaxElement(startVector);
			BOOST_CHECK(startVector == resultVector);
		}

		BOOST_AUTO_TEST_CASE(if_biggest_in_middle)
		{
			std::vector<double> startVector = { 0, 2, 3, 5 };
			std::vector<double> resultVector = { 0.000, 0.800, 1.200, 2.000 };
			startVector = DivideToAHalfOfMaxElement(startVector);
			BOOST_CHECK(startVector == resultVector);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()