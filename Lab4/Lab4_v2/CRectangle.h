#pragma once
#include "ISolidShape.h"
#include "CPoint.h"
#include "CSolidShape.h"

//CRectangle(const double& x, const double& y, const double& width, const double& height, const std::string& strokeColor, const std::string& fillColor);
class CRectangle : public CSolidShape
{
public:
	CRectangle(const double& x, const double& y, const double& width, const double& height, const std::string& strokeColor, const std::string& fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
private:
	CPoint m_leftTop;
	double m_width;
	double m_height;
};
