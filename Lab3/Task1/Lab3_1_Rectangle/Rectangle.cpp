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
	SetLeft(left);
	SetTop(top);
	if (width > 0)
	{
		SetWidth(width);
	}
	else
	{
		SetWidth(0);
	}
	if (height > 0)
	{
		SetHeight(height);
	}
	else
	{
		SetHeight(0);
	}
}

void CRectangle::Move(const int& dx, const int& dy)
{
	SetLeft(GetLeft() + dx);
	SetTop(GetTop() + dy);
}

void CRectangle::Scale(const int& sx, const int& sy)
{
	SetWidth(GetWidth() * sx);
	SetHeight(GetHeight() * sy);
}

bool CRectangle::Intersects(const CRectangle& other)
{
	if (this->m_left < other.GetRight() && this->GetRight() > other.GetLeft() && this->m_top < other.GetBottom() && this->GetBottom() > other.GetTop())
	{
		CRectangle intersectRect;
		intersectRect.SetLeft(std::max(this->GetLeft(), other.GetLeft()));
		intersectRect.SetTop(std::max(this->GetTop(), other.GetTop()));
		intersectRect.SetHeight(abs(std::min(this->GetBottom(), other.GetBottom()) - intersectRect.GetTop()));
		intersectRect.SetWidth(abs(std::min(this->GetRight(), other.GetRight()) - intersectRect.GetLeft()));
		*this = intersectRect;
		return true;
	}
	return false;
}

unsigned CRectangle::GetPerimeter() const
{
	return (GetWidth() + GetHeight()) * 2;
}

unsigned CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

int CRectangle::GetRight() const
{
	return GetLeft() + GetWidth();
}

int CRectangle::GetBottom() const
{
	return GetTop() + GetHeight();
}

int CRectangle::GetWidth() const
{
	return m_width;
}

int CRectangle::GetHeight() const
{
	return m_height;
}

void CRectangle::SetWidth(const int & width)
{
	m_width = width;
}

void CRectangle::SetHeight(const int & height)
{
	m_height = height;
}

void CRectangle::SetTop(const int & top)
{
	m_top = top;
}

void CRectangle::SetLeft(const int & left)
{
	m_left = left;
}

int CRectangle::GetLeft() const
{
	return m_left;
}

int CRectangle::GetTop() const
{
	return m_top;
}
