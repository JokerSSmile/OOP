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
	return "Point <" + boost::lexical_cast<std::string>(m_x) + ", " + boost::lexical_cast<std::string>(m_y) + ">";
}

std::string CPoint::GetType() const
{
	return "point";
}

double CPoint::GetX() const
{
	return m_x;
}

double CPoint::GetY() const
{
	return m_y;
}