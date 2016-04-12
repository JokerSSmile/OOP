#include "stdafx.h"
#include <boost/math/constants/constants.hpp>

const double C_PI = boost::math::constants::pi<double>();

CCircle::CCircle(const double& x, const double& y, const double& radius, const std::string& strokColor, const std::string& fillColor)
	:ISolidShape(strokColor, fillColor),
	m_center(x, y, strokColor),
	m_radius(radius) {};

double CCircle::GetArea() const
{
	return C_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * C_PI * m_radius;
}

std::string CCircle::ToString() const
{
	return "Circle <" + std::to_string(m_center.GetX()) + ", " + 
		std::to_string(m_center.GetY()) + "> R = " + std::to_string(m_radius) +
		" S = " + std::to_string(GetArea()) + " P = " + std::to_string(GetPerimeter());
}
