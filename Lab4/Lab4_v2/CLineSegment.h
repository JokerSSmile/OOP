#pragma once
#include "IShape.h"
#include "CPoint.h"

//CLineSegment(const double& x1, const double& y1, const double& x2, const double& y2, const std::string& strokColor);
class CLineSegment : public CShape
{
public:
	CLineSegment(const double& x1, const double& y1, const double& x2, const double& y2, const std::string& strokColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
private:
	CPoint m_start;
	CPoint m_end;
};