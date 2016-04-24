#pragma once
#include "ISolidShape.h"
#include "CShape.h"

class CSolidShape : public CShape, ISolidShape
{
public:
	CSolidShape(const std::string& strokeColor, const std::string& fillColor);
	std::string GetFillColor() const;
protected:
	std::string m_fillColor;
};
