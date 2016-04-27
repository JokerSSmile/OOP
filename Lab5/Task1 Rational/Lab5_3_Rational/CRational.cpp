#include "stdafx.h"
#include "CRational.h"
#include <iostream>
#include <utility>
#include <stdexcept>

CRational::CRational(const int& numerator, const int& denominator)
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
	return (double)m_numerator / m_denominator;
}

CRational const CRational::operator+() const
{
	return *this;
}

CRational const CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const operator+(const CRational& left, const CRational& right)
{
	return CRational(left.GetNumerator() * right.GetDenominator() + left.GetDenominator() * right.GetNumerator(),
		left.GetDenominator() * right.GetDenominator());
}

CRational const operator-(const CRational& left, const CRational& right)
{
	return CRational(left.GetNumerator() * right.GetDenominator() - right.GetNumerator() * left.GetDenominator(),
		left.GetDenominator() * right.GetDenominator());
}

CRational& CRational::operator+=(const CRational& other)
{
	m_numerator = GetNumerator() * other.GetDenominator() + other.GetNumerator() * GetDenominator();
	m_denominator = GetDenominator() * other.GetDenominator();
	Normalize();
	return *this;
}

CRational& CRational::operator-=(const CRational& other)
{
	m_numerator = GetNumerator() * other.GetDenominator() - other.GetNumerator() * GetDenominator();
	m_denominator = GetDenominator() * other.GetDenominator();
	Normalize();
	return *this;
}

CRational const operator*(const CRational& left, const CRational& right)
{
	return CRational(left.GetNumerator() * right.GetNumerator(), left.GetDenominator() * right.GetDenominator());
}

CRational const operator/(const CRational& left, const CRational& right)
{
	return CRational(left.GetNumerator() * right.GetDenominator(), left.GetDenominator() * right.GetNumerator());
}

CRational& CRational::operator*=(const CRational& other)
{
	m_numerator = GetNumerator() * other.GetNumerator();
	m_denominator = GetDenominator() * other.GetDenominator();
	Normalize();
	return *this;
}

CRational& CRational::operator/=(const CRational& other)
{
	m_numerator = GetNumerator() * other.GetDenominator();
	m_denominator = GetDenominator() * other.GetNumerator();
	Normalize();
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const CRational& rational)
{
	stream << rational.GetNumerator() << "/" << rational.GetDenominator();
	return stream;
}

std::istream& operator>>(std::istream& stream, CRational& rational)
{
	int numerator;
	int denominator;
	if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}

bool operator==(const CRational& left, const CRational& right)
{
	return (left.GetNumerator() == right.GetNumerator()) && (left.GetDenominator() == right.GetDenominator());
}

bool operator!=(const CRational& left, const CRational& right)
{
	return (left.GetNumerator() != right.GetNumerator()) || (left.GetDenominator() != right.GetDenominator());
}

bool operator<(const CRational& left, const CRational& right)
{
	return ((left.GetNumerator() * right.GetDenominator()) < (left.GetDenominator() * right.GetNumerator()));
}

bool operator<=(const CRational& left, const CRational& right)
{
	return ((left.GetNumerator() * right.GetDenominator()) <= (left.GetDenominator() * right.GetNumerator()));
}

bool operator>(const CRational& left, const CRational& right)
{
	return ((left.GetNumerator() * right.GetDenominator()) > (left.GetDenominator() * right.GetNumerator()));
}

bool operator>=(const CRational& left, const CRational& right)
{
	return ((left.GetNumerator() * right.GetDenominator()) >= (left.GetDenominator() * right.GetNumerator()));
}
