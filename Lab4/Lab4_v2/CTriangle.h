#pragma once
#include "ISolidShape.h"
#include "CPoint.h"
#include "CLineSegment.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(const double& x1, const double& y1, const double& x2, const double& y2, const double& x3, const double& y3, 
		const std::string& strokColor, const std::string& fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
private:
	CPoint m_p1;
	CPoint m_p2;
	CPoint m_p3;
	CLineSegment m_line1;
	CLineSegment m_line2;
	CLineSegment m_line3;
};
