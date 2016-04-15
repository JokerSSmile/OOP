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
	return "Circle <" + boost::lexical_cast<std::string>(m_center.GetX()) + ", " +
		boost::lexical_cast<std::string>(m_center.GetY()) + "> R=" +boost::lexical_cast<std::string>(m_radius) +
		" S=" + boost::lexical_cast<std::string>(GetArea()) + " P=" + boost::lexical_cast<std::string>(GetPerimeter());
}

std::string CCircle::GetType() const
{
	return "circle";
}
