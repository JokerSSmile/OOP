#include "stdafx.h"

CSolidShape::CSolidShape(const std::string& strokeColor, const std::string& fillColor)
	:CShape(strokeColor),
	m_fillColor(fillColor) {};

std::string CSolidShape::GetFillColor() const 
{
	return m_fillColor;
}