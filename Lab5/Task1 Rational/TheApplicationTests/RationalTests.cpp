#include "stdafx.h"
#include "../Lab5_3_Rational/CRational.h"

#include<iostream>

using namespace std;

void VerifyRational(const CRational & r, const int& expectedNumerator, const int& expectedDenominator)
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
	CRational first(1, 2);
	CRational second(1, 6);
	auto answer = first + second;
	VerifyRational(answer, 2, 3);
}

BOOST_AUTO_TEST_CASE(binary_plus_works_correct_if_rational_and_int)
{
	int num = 2;
	CRational rational = CRational(2, 5);
	auto answer = rational + num;
	VerifyRational(answer, 12, 5);
}

BOOST_AUTO_TEST_CASE(binary_plus_works_correct_if_int_and_rational)
{
	CRational rational = CRational(2, 5);
	auto answer = 1 + rational;
	VerifyRational(answer, 7, 5);
}

BOOST_AUTO_TEST_CASE(binary_minus_works_correct_if_two_rationals)
{
	CRational first(1, 2);
	CRational second(1, 6);
	auto answer = first - second;
	VerifyRational(answer, 1, 3);
}

BOOST_AUTO_TEST_CASE(binary_minus_works_correct_if_rational_and_int)
{
	CRational rational = CRational(10, 3);
	auto answer = rational - 2;
	VerifyRational(answer, 4, 3);
}

BOOST_AUTO_TEST_CASE(binary_minus_works_correct_if_int_and_rational)
{
	CRational rational = CRational(2, 5);
	auto answer = 1 - rational;
	VerifyRational(answer, 3, 5);
}

BOOST_AUTO_TEST_CASE(minus_eq_works_correct_if_two_rationals)
{
	CRational first(1, 2);
	CRational second(1, 6);
	first -= second;
	VerifyRational(first, 1, 3);
}

BOOST_AUTO_TEST_CASE(minus_eq_works_correct_if_rational_and_int)
{
	CRational rational = CRational(10, 3);
	rational -= 2;
	VerifyRational(rational, 4, 3);
}

BOOST_AUTO_TEST_CASE(plus_eq_works_correct_if_two_rationals)
{
	CRational first(1, 2);
	CRational second(1, 6);
	first += second;
	VerifyRational(first, 2, 3);
}

BOOST_AUTO_TEST_CASE(plus_eq_works_correct_if_rational_and_int)
{
	CRational rational = CRational(1, 3);
	rational += 2;
	VerifyRational(rational, 7, 3);
}

BOOST_AUTO_TEST_CASE(multiplication_works_correct_if_two_rationals)
{
	CRational first(1, 2);
	CRational second(1, 6);
	auto answer = first * second;
	VerifyRational(answer, 1, 12);
}

BOOST_AUTO_TEST_CASE(multiplication_works_correct_if_rational_and_int)
{
	CRational rational = CRational(10, 3);
	auto answer = rational * 2;
	VerifyRational(answer, 20, 3);
}

BOOST_AUTO_TEST_CASE(multiplication_works_correct_if_int_and_rational)
{
	CRational rational = CRational(2, 5);
	auto answer = 3 * rational;
	VerifyRational(answer, 6, 5);
}

BOOST_AUTO_TEST_CASE(division_works_correct_if_two_rationals)
{
	CRational first(1, 2);
	CRational second(1, 6);
	auto answer = first / second;
	VerifyRational(answer, 3, 1);
}

BOOST_AUTO_TEST_CASE(division_works_correct_if_rational_and_int)
{
	CRational rational = CRational(10, 3);
	auto answer = rational / 2;
	VerifyRational(answer, 5, 3);
}

BOOST_AUTO_TEST_CASE(division_works_correct_if_int_and_rational)
{
	CRational rational = CRational(2, 5);
	auto answer = 3 / rational;
	VerifyRational(answer, 15, 2);
}

BOOST_AUTO_TEST_CASE(mult_eq_works_correct_if_two_rationals)
{
	CRational first(1, 2);
	CRational second(1, 6);
	first *= second;
	VerifyRational(first, 1, 12);
}

BOOST_AUTO_TEST_CASE(mult_eq_works_correct_if_rational_and_int)
{
	CRational rational = CRational(1, 3);
	rational *= 2;
	VerifyRational(rational, 2, 3);
}

BOOST_AUTO_TEST_CASE(div_eq_works_correct_if_two_rationals)
{
	CRational first(1, 2);
	CRational second(1, 6);
	first /= second;
	VerifyRational(first, 3, 1);
}

BOOST_AUTO_TEST_CASE(div_eq_works_correct_if_rational_and_int)
{
	CRational rational = CRational(1, 3);
	rational /= 2;
	VerifyRational(rational, 1, 6);
}

BOOST_AUTO_TEST_CASE(eq_works_correct_if_rational_and_rational)
{
	CRational rational1 = CRational(1, 3);
	CRational rational2 = CRational(2, 6);
	BOOST_CHECK(rational1 == rational2);
}

BOOST_AUTO_TEST_CASE(eq_works_correct_if_rational_and_int)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(rational1 == 2);
}

BOOST_AUTO_TEST_CASE(eq_works_correct_if_int_and_rational)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(2 == rational1);
}

BOOST_AUTO_TEST_CASE(not_eq_works_correct_if_rational_and_rational)
{
	CRational rational1 = CRational(1, 3);
	CRational rational2 = CRational(2, 7);
	BOOST_CHECK(rational1 != rational2);
}

BOOST_AUTO_TEST_CASE(not_eq_works_correct_if_rational_and_int)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(rational1 != 1);
}

BOOST_AUTO_TEST_CASE(not_eq_works_correct_if_int_and_rational)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(3 != rational1);
}

BOOST_AUTO_TEST_CASE(more_works_correct_if_rational_and_rational)
{
	CRational rational1 = CRational(1, 3);
	CRational rational2 = CRational(2, 7);
	BOOST_CHECK(rational1 > rational2);
}

BOOST_AUTO_TEST_CASE(more_works_correct_if_rational_and_int)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(rational1 > 1);
}

BOOST_AUTO_TEST_CASE(more_works_correct_if_int_and_rational)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(5 > rational1);
}

BOOST_AUTO_TEST_CASE(less_works_correct_if_rational_and_rational)
{
	CRational rational1 = CRational(1, 3);
	CRational rational2 = CRational(2, 7);
	BOOST_CHECK(rational2 < rational1);
}

BOOST_AUTO_TEST_CASE(less_works_correct_if_rational_and_int)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(rational1 < 5);
}

BOOST_AUTO_TEST_CASE(less_works_correct_if_int_and_rational)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(1 < rational1);
}

BOOST_AUTO_TEST_CASE(more_eq_works_correct_if_rational_and_rational)
{
	CRational first = CRational(1, 3);
	CRational second = CRational(1, 3);
	BOOST_CHECK(first >= second);
}

BOOST_AUTO_TEST_CASE(more_eq_works_correct_if_rational_and_int)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(rational1 >= 1);
}

BOOST_AUTO_TEST_CASE(more_eq_works_correct_if_int_and_rational)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(2 >= rational1);
}

BOOST_AUTO_TEST_CASE(less_eq_works_correct_if_rational_and_rational)
{
	CRational first = CRational(1, 3);
	CRational second = CRational(1, 3);
	BOOST_CHECK(first <= second);
}

BOOST_AUTO_TEST_CASE(less_eq_works_correct_if_rational_and_int)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(rational1 <= 10);
}

BOOST_AUTO_TEST_CASE(less_eq_works_correct_if_int_and_rational)
{
	CRational rational1 = CRational(6, 3);
	BOOST_CHECK(2 <= rational1);
}

BOOST_AUTO_TEST_CASE(input_operator_works_correct)
{
	CRational rational;
	std::istringstream strm("6/3");
	strm >> rational;
	VerifyRational(rational, 2, 1);
}

BOOST_AUTO_TEST_CASE(output_operator_works_correct)
{
	CRational rational(4, 3);
	std::ostringstream strm;
	strm << rational;
	BOOST_CHECK_EQUAL(strm.str(), "4/3");
}

BOOST_AUTO_TEST_SUITE_END()