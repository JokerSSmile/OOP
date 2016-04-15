#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

//CCircle(const double& x, const double& y, const double& radius, const std::string& strokColor, const std::string& fillColor);
class CCircle : public ISolidShape
{
public:
	CCircle(const double& x, const double& y, const double& radius, const std::string& strokColor, const std::string& fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetType() const override;
private:
	CPoint m_center;
	double m_radius;
};
