#include "stdafx.h"

CRectangle::CRectangle(const double& x, const double& y, const double& width, const double& height, const std::string& strokeColor, const std::string& fillColor)
	:CSolidShape(strokeColor, fillColor),
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
	return "Rectangle <" + boost::lexical_cast<std::string>(m_leftTop.GetX()) + ", " +
		boost::lexical_cast<std::string>(m_leftTop.GetY()) +
		"> S=" + boost::lexical_cast<std::string>(GetArea()) + " P=" +
		boost::lexical_cast<std::string>(GetPerimeter());
}
