#pragma once
#include <iostream>
#include <cmath>

class IShape
{
public:
	IShape() {};
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual ~IShape() = default;
};