#include "stdafx.h"

CLineSegment::CLineSegment(const double& x1, const double& y1, const double& x2,
	const double& y2, const std::string& strokColor)
	:IShape(strokColor),
	m_start(x1, y1, strokColor),
	m_end(x2, y2, strokColor) {};

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return std::sqrt(std::pow((m_start.GetX() - m_end.GetX()), 2) + std::pow((m_start.GetY() - m_end.GetY()), 2));
}

std::string CLineSegment::ToString() const
{
	return "Line Segment <" + boost::lexical_cast<std::string>(m_start.GetX()) + ", " +
		boost::lexical_cast<std::string>(m_start.GetY()) + ">, <" + boost::lexical_cast<std::string>(m_end.GetX()) +
		 ", " + boost::lexical_cast<std::string>(m_end.GetY()) + "> S=" + boost::lexical_cast<std::string>(GetArea()) +
		" P=" + boost::lexical_cast<std::string>(GetPerimeter());
}

std::string CLineSegment::GetType() const
{
	return "line";
}