#include "stdafx.h"
#include "CCircle.h"
#include <boost/math/constants/constants.hpp>

const double C_PI = boost::math::constants::pi<double>();

CCircle::CCircle(const double& x, const double& y, const double& radius, const std::string& strokColor, const std::string& fillColor)
	:ISolidShape(strokColor, fillColor),
	m_center(x, y, strokColor)
{

}

double CCircle::GetArea()
{
	return C_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter()
{
	return 2 * C_PI * m_radius;
}

std::string CCircle::GetType()
{
	return "Circle";
}