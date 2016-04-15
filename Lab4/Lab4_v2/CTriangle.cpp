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
	std::vector<double> xValues = { m_p1.GetX(), m_p2.GetX(), m_p3.GetX() };
	std::vector<double> yValues = { m_p1.GetY(), m_p2.GetY(), m_p3.GetY() };

	return 0.5 * ((*std::max_element(xValues.begin(), xValues.end()) - *std::min_element(xValues.begin(), xValues.end())) *
		(*std::max_element(yValues.begin(), yValues.end()) - *std::min_element(yValues.begin(), yValues.end())));

}

double CTriangle::GetPerimeter() const
{
	return m_line1.GetPerimeter() + m_line2.GetPerimeter() + m_line3.GetPerimeter();
}

std::string CTriangle::ToString() const
{
	return "Triangle <" + boost::lexical_cast<std::string>(m_p1.GetX()) + ", " + boost::lexical_cast<std::string>(m_p1.GetY()) + "> " +
		" <" + boost::lexical_cast<std::string>(m_p2.GetX()) + ", " + boost::lexical_cast<std::string>(m_p2.GetY()) + "> " +
		" <" + boost::lexical_cast<std::string>(m_p3.GetX()) + ", " + boost::lexical_cast<std::string>(m_p3.GetY()) + ">" +
		" S=" + boost::lexical_cast<std::string>(GetArea()) + " P=" + boost::lexical_cast<std::string>(GetPerimeter());
}

std::string CTriangle::GetType() const
{
	return "triangle";
}
