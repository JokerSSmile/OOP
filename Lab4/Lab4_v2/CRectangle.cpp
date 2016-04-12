#include "stdafx.h"

CRectangle::CRectangle(const double& x, const double& y, const double& width, const double& height, const std::string& strokeColor, const std::string& fillColor)
	:ISolidShape(strokeColor, fillColor),
	m_leftTop(x, y, strokeColor),
	m_width(width),
	m_height(height) {};

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

std::string CRectangle::ToString() const
{
	return "Rectangle <" + std::to_string(m_leftTop.GetX()) + ", " + std::to_string(m_leftTop.GetY()) +
		" > S = " + std::to_string(GetArea()) + " P = " + std::to_string(GetPerimeter());
}
