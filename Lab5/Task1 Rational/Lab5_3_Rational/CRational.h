#pragma once

class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	int GetNumerator() const;
	int GetDenominator() const;

	double ToDouble() const;

	CRational& operator +=(const CRational& other);
	
private:
	int m_numerator;
	int m_denominator;

	// Нормализует рациональное число
	void Normalize();
};

// Вычисляет наибольший общий знаменатель чисел a и b
unsigned GCD(unsigned a, unsigned b);