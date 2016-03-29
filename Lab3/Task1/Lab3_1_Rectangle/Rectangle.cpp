#include "stdafx.h"
#include "Rectangle.h"
#include <algorithm>
#include <iostream>

using namespace std;

CRectangle::CRectangle()
{
	width = 0;
	height = 0;
	top = 0;
	left = 0;
}

CRectangle::CRectangle(const int& left, const int& top, const int& width, const int& height)
{
	this->left = left;
	this->top = top;
	if (width > 0)
	{
		this->width = width;
	}
	else
	{
		this->width = 0;
	}
	if (height > 0)
	{
		this->height = height;
	}
	else
	{
		this->height = 0;
	}
}

void CRectangle::Move(const int& dx, const int& dy)
{
	left += dx;
	top += dy;
}

void CRectangle::Scale(const int& sx, const int& sy)
{
	width *= sx;
	height *= sy;
}

bool CRectangle::Intersects(const CRectangle& other)
{
	if (this->left < other.GetRight() && this->GetRight() > other.GetLeft() && this->top < other.GetBottom() && this->GetBottom() > other.GetTop())
	{
		CRectangle intersectRect;
		intersectRect.left = std::max(this->left, other.left);
		intersectRect.top = std::max(this->top, other.top);
		intersectRect.height = abs(std::min(this->GetBottom(), other.GetBottom()) - intersectRect.top);
		intersectRect.width = abs(std::min(this->GetRight(), other.GetRight()) - intersectRect.left);
		*this = intersectRect;
		return true;
	}
	return false;
}

unsigned CRectangle::GetPerimeter() const
{
	return (width + height) * 2;
}

unsigned CRectangle::GetArea() const
{
	return width * height;
}

int CRectangle::GetRight() const
{
	return left + width;
}

int CRectangle::GetBottom() const
{
	return top + height;
}

int CRectangle::GetWidth() const
{
	return width;
}

int CRectangle::GetHeight() const
{
	return height;
}

int CRectangle::GetLeft() const
{
	return left;
}

int CRectangle::GetTop() const
{
	return top;
}
