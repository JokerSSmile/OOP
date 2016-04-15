#pragma once
#include "IShape.h"

//CPoint(const double& x, const double& y, const std::string& strokColor);
class CPoint : public IShape
{
public:
	CPoint(const double& x, const double& y, const std::string& strokColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetType() const override;
	double GetX() const;
	double GetY() const;
private:
	double m_x;
	double m_y;
};