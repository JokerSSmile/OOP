#include "stdafx.h"

CPoint::CPoint(const double& x, const double& y, const std::string& strokColor)
	:IShape(strokColor),
	m_x(x),
	m_y(y) {};

double CPoint::GetArea() const
{
	return 0;
}

double CPoint::GetPerimeter() const
{
	return 0;
}

std::string CPoint::ToString() const
{
	return "Point <" + std::to_string(m_x) + ", " + std::to_string(m_y) + " >";
}

double CPoint::GetX() const
{
	return m_x;
}

double CPoint::GetY() const
{
	return m_y;
}