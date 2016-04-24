#pragma once
#include "IShape.h"

class CShape : public IShape
{
public:
	CShape(const std::string& color);
	std::string GetStrokeColor() const;
protected:
	std::string m_strokeColor;
};
