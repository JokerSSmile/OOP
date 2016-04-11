#include "stdafx.h"

CTriangle::CTriangle(const double& x1, const double& y1, const double& x2, const double& y2, const double& x3,
	const double& y3, const std::string& strokColor, const std::string& fillColor)
	:ISolidShape(strokColor, fillColor),
	m_p1(x1, y1, strokColor),
	m_p2(x2, y2, strokColor),
	m_p3(x3, y3, strokColor),
	m_line1(x1, y1, x2, y2, strokColor),
	m_line2(x1, y1, x3, y3, strokColor),
	m_line3(x2, y2, x3, y3, strokColor) {};

double CTriangle::GetArea() const
{
	return 0.5 * ((m_p1.GetX() - m_p3.GetX()) * (m_p2.GetY() - m_p3.GetY()) - (m_p2.GetX() - m_p3.GetX()) * (m_p1.GetY() - m_p3.GetY()));
}

double CTriangle::GetPerimeter() const
{
	return m_line1.GetPerimeter() + m_line2.GetPerimeter() + m_line3.GetPerimeter();
}

std::string CTriangle::GetType() const
{
	return "Triangle";
}