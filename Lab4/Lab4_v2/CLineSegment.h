#pragma once
#include "IShape.h"
#include "CPoint.h"

class CLineSegment : IShape
{
public:
	CLineSegment(const double& x1, const double& y1, const double& x2, const double& y2, const std::string& strokColor);
	double GetArea() override;
	double GetPerimeter() override;
	std::string GetType() override;
	void CalculateLength();
private:
	CPoint m_start;
	CPoint m_end;
	double m_length;
};