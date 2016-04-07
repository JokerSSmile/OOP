#pragma once
#include "IShape.h"

class CPoint : IShape
{
public:
	CPoint(const double& x, const double& y, const std::string& strokColor);
	double GetArea() override;
	double GetPerimeter() override;
	std::string GetType() override;
	double GetX() const;
	double GetY() const;
private:
	double m_x;
	double m_y;
};