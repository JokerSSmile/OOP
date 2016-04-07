#pragma once
#include <iostream>
#include <cmath>

class IShape
{
public:
	IShape(const std::string& color);
	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
	virtual std::string GetType() = 0;
	virtual ~IShape();
protected:
	std::string m_strokeColor;
};