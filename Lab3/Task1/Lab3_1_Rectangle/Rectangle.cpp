#include "stdafx.h"
#include "Rectangle.h"
#include <algorithm>
#include <iostream>

using namespace std;

CRectangle::CRectangle()
{
	m_width = 0;
	m_height = 0;
	m_top = 0;
	m_left = 0;
}

CRectangle::CRectangle(const int& left, const int& top, const int& width, const int& height)
{
	this->m_left = left;
	this->m_top = top;
	if (width > 0)
	{
		this->m_width = width;
	}
	else
	{
		this->m_width = 0;
	}
	if (height > 0)
	{
		this->m_height = height;
	}
	else
	{
		this->m_height = 0;
	}
}

void CRectangle::Move(const int& dx, const int& dy)
{
	m_left += dx;
	m_top += dy;
}

void CRectangle::Scale(const int& sx, const int& sy)
{
	m_width *= sx;
	m_height *= sy;
}

bool CRectangle::Intersects(const CRectangle& other)
{
	if (this->m_left < other.GetRight() && this->GetRight() > other.GetLeft() && this->m_top < other.GetBottom() && this->GetBottom() > other.GetTop())
	{
		CRectangle intersectRect;
		intersectRect.m_left = std::max(this->m_left, other.m_left);
		intersectRect.m_top = std::max(this->m_top, other.m_top);
		intersectRect.m_height = abs(std::min(this->GetBottom(), other.GetBottom()) - intersectRect.m_top);
		intersectRect.m_width = abs(std::min(this->GetRight(), other.GetRight()) - intersectRect.m_left);
		*this = intersectRect;
		return true;
	}
	return false;
}

unsigned CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

unsigned CRectangle::GetArea() const
{
	return m_width * m_height;
}

int CRectangle::GetRight() const
{
	return m_left + m_width;
}

int CRectangle::GetBottom() const
{
	return m_top + m_height;
}

int CRectangle::GetWidth() const
{
	return m_width;
}

int CRectangle::GetHeight() const
{
	return m_height;
}

int CRectangle::GetLeft() const
{
	return m_left;
}

int CRectangle::GetTop() const
{
	return m_top;
}
