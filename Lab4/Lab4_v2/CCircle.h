#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CCircle : ISolidShape
{
public:
	CCircle(const double& x, const double& y, const double& radius, const std::string& strokColor, const std::string& fillColor);
	double GetArea() override;
	double GetPerimeter() override;
	std::string GetType() override;
private:
	CPoint m_center;
	double m_radius;
};
