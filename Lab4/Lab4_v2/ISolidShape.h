#pragma once
#include "IShape.h"
#include "CShape.h"

class ISolidShape : public IShape
{
public:
	virtual std::string GetFillColor() const = 0;
};
