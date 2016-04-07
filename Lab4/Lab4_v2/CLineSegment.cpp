#include "stdafx.h"
#include "CLineSegment.h"

CLineSegment::CLineSegment(const double& x1, const double& y1, const double& x2,
	const double& y2, const std::string& strokColor)
	:IShape(strokColor),
	m_start(x1, y1, strokColor),
	m_end(x2, y2, strokColor)
{
	CalculateLength();
}

void CLineSegment::CalculateLength()
{
	m_length = std::sqrt(std::pow((m_start.GetX() - m_end.GetX()), 2) + std::pow((m_start.GetY() - m_end.GetY()), 2));
}

double CLineSegment::GetArea()
{
	return 0;
}

double CLineSegment::GetPerimeter()
{
	return m_length;
}

std::string CLineSegment::GetType()
{
	return "Line Segment";
}