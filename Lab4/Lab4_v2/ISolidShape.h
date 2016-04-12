#pragma once
#include "IShape.h"

class ISolidShape : public IShape
{
public:
	ISolidShape(const std::string& fillColor, const std::string& strokeColor)
		:IShape(strokeColor),
		m_fillColor(fillColor) {};
protected:
	std::string m_fillColor;
};
