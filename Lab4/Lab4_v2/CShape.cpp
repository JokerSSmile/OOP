#include "stdafx.h"

CShape::CShape(const std::string& color)
{
	m_strokeColor = color;
}

std::string CShape::GetStrokeColor() const
{
	return m_strokeColor;
}
