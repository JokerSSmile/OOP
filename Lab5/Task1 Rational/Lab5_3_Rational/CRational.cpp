#include "stdafx.h"
#include "CRational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

double CRational::ToDouble() const
{
	return m_numerator / m_denominator;
}

CRational& CRational::operator+=(const CRational& other)
{
	this->m_numerator = this->GetNumerator() * other.GetDenominator() + other.GetNumerator() * this->GetDenominator();
	this->m_denominator = this->GetDenominator() * other.GetDenominator();
	return *this;
}