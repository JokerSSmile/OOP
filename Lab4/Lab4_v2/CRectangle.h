#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CRectangle : ISolidShape
{
public:
	CRectangle(const double& x, const double& y, const double& width, const double& height, const std::string& strokeColor, const std::string& fillColor);
	double GetArea() override;
	double GetPerimeter() override;
	std::string GetType() override;
private:
	CPoint m_leftTop;
	double m_width;
	double m_height;
};
