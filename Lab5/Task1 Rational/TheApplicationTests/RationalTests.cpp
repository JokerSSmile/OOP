#include "stdafx.h"
#include "../Lab5_3_Rational/CRational.h"

#include<iostream>

void VerifyRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(rationalTests)

BOOST_AUTO_TEST_CASE(to_double_works_correctly)
{
	BOOST_CHECK_CLOSE(CRational(3, 5).ToDouble(), 0.6, 0.1);
	BOOST_CHECK_CLOSE(CRational(5, 6).ToDouble(), 0.833333, 0.01);
	BOOST_CHECK_CLOSE(CRational(-3, 7).ToDouble(), -0.428571, 0.01);
}

BOOST_AUTO_TEST_CASE(unary_plus_works_correct)
{
	VerifyRational(+CRational(3, 4), 3, 4);
	VerifyRational(+CRational(0, 1), 0, 1);
	VerifyRational(+CRational(-1, 2), -1, 2);
}

BOOST_AUTO_TEST_CASE(unary_minus_works_correct)
{
	VerifyRational(-CRational(3, 4), -3, 4);
	VerifyRational(-CRational(0, 1), 0, 1);
	VerifyRational(-CRational(-1, 2), 1, 2);
}

BOOST_AUTO_TEST_CASE(binary_plus_works_correct_if_two_rationals)
{
	VerifyRational(CRational(3, 4) + CRational(2, 5), 23, 20);
}

BOOST_AUTO_TEST_CASE(binary_plus_works_correct_if_rational_and_int)
{
	VerifyRational(CRational(3, 4) + 1, 7, 4);
}

BOOST_AUTO_TEST_CASE(binary_plus_works_correct_if_int_and_rational)
{
	VerifyRational(2 + CRational(3, 4), 7, 4);
}

BOOST_AUTO_TEST_CASE(binary_minus_works_correct)
{

}

BOOST_AUTO_TEST_SUITE_END()