#include "stdafx.h"
#include "CPoint.h"

CPoint::CPoint(const double& x, const double& y, const std::string& strokColor)
	:IShape(strokColor),
	m_x(x),
	m_y(y)
{

}

double CPoint::GetArea()
{
	return 0;
}

double CPoint::GetPerimeter()
{
	return 0;
}

std::string CPoint::GetType()
{
	return "Point";
}

double CPoint::GetX() const
{
	return m_x;
}

double CPoint::GetY() const
{
	return m_y;
}