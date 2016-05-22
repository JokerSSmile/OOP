#pragma once

class CRectangle
{
public:
	CRectangle();
	CRectangle(const int& left, const int& top, const int& width, const int& height);
	void Move(const int& dx, const int& dy);
	void Scale(const int& sx, const int& sy);
	bool Intersects(const CRectangle& other);
	unsigned GetPerimeter() const;
	unsigned GetArea() const;
	int GetRight() const;
	int GetBottom() const;
	int GetLeft() const;
	int GetTop() const;
	int GetWidth() const;
	int GetHeight() const;
	void SetWidth(const int& width);
	void SetHeight(const int& height);
	void SetTop(const int& top);
	void SetLeft(const int& left);
private:
	int m_left;
	int m_top;
	unsigned m_width;
	unsigned m_height;
};