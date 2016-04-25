#pragma once

class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	int GetNumerator() const;
	int GetDenominator() const;

	double ToDouble() const;

	CRational const operator+() const;

	CRational const operator-() const;
	
	CRational const operator+(const CRational& other) const;

	CRational const operator-(const CRational& other) const;

	CRational& operator+=(const CRational& other);

	CRational& operator-=(const CRational& other);

	CRational& const operator*(const CRational& other) const;

	CRational& const operator/(const CRational& other) const;

	CRational& operator*=(const CRational& other);

	CRational& operator/=(const CRational& other);

	bool operator==(const CRational& other) const;

	bool operator!=(const CRational& other) const;

private:
	int m_numerator;
	int m_denominator;

	// Нормализует рациональное число
	void Normalize();
};

// Вычисляет наибольший общий знаменатель чисел a и b
unsigned GCD(unsigned a, unsigned b);