#pragma once
#include <vector>

template <typename T, typename Less>
bool FindMaxEx(const std::vector<T>& array, T& maxValue, const Less& less)
{
	if (array.size() == 0)
	{
		return false;
	}

	
	auto maxTempValue = array.begin();
	for (auto it = array.begin(); it != array.end(); it++)
	{
		if (less(*maxTempValue, *it))
		{
			maxTempValue = it;
		}
	}

	maxValue = *maxTempValue;
	return true;
}