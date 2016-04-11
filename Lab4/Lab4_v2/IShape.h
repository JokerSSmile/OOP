#pragma once
#include <iostream>
#include <cmath>

class IShape
{
public:
	IShape(const std::string& color)
		:m_strokeColor(color) {};
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string GetType() const = 0;
	virtual ~IShape() = default;
protected:
	std::string m_strokeColor;
};