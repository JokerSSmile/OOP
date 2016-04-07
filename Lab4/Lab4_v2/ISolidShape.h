#pragma once
#include "IShape.h"

class ISolidShape : IShape
{
public:
	ISolidShape(const std::string& fillColor, const std::string& strokeColor);
protected:
	std::string m_fillColor;
};
