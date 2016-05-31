#pragma once
#include <memory>

template <typename T>
class CMyList
{
public:
	CMyList() = default;

	CMyList(const CMyList& myList)
	{

	};

	void PushFront() {};
	void PushBack() {};
	T Begin() {};
	T End() {};
	T RBegin() {};
	T REnd() {};
	size_t GetSize() {};
	void Insert() {};
	void Remove() {};
	operator= () {};

private:

	std::shared_ptr<T> m_begin;
	std::shared_ptr<T> m_end;

};