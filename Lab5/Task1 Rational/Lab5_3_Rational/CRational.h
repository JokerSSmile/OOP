#pragma once

class CRational final
{
public:
	//CRational(const int& value);
	CRational(const int& numerator = 0, const int& denominator = 1);

	int GetNumerator() const;
	int GetDenominator() const;

	double ToDouble() const;

	CRational const operator+() const;

	CRational const operator-() const;

	CRational& operator+=(const CRational& other);

	CRational& operator-=(const CRational& other);

	CRational& operator*=(const CRational& other);

	CRational& operator/=(const CRational& other);

	std::pair<int, CRational> ToCompoundFraction() const;

private:
	int m_numerator;
	int m_denominator;

	// Нормализует рациональное число
	void Normalize();
};

// Вычисляет наибольший общий знаменатель чисел a и b
unsigned GCD(unsigned a, unsigned b);

CRational const operator+(const CRational& left, const CRational& right);

CRational const operator-(const CRational& left, const CRational& right);

CRational const operator*(const CRational& left, const CRational& right);

CRational const operator/(const CRational& left, const CRational& right);

bool const operator==(const CRational& left, const CRational& right);

bool const operator!=(const CRational& left, const CRational& right);

bool const operator<(const CRational& left, const CRational& right);

bool const operator<=(const CRational& left, const CRational& right);

bool const operator>(const CRational& left, const CRational& right);

bool const operator>=(const CRational& left, const CRational& right);

std::istream& operator>>(std::istream& stream, CRational& rational);

std::ostream& operator<<(std::ostream& stream, const CRational& rational);
