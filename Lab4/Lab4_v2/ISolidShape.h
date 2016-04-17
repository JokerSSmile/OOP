#pragma once
#include "IShape.h"

class ISolidShape : public IShape
{
public:
	ISolidShape(const std::string& strokeColor, const std::string& fillColor)
		:IShape(strokeColor),
		m_fillColor(fillColor) {};
	std::string GetFillColor()
	{
		return m_fillColor;
	}
protected:
	std::string m_fillColor;
};
