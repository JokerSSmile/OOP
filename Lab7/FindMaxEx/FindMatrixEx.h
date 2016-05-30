#pragma once
#include <vector>

template <typename T, typename Less>
bool FindMaxEx(const std::vector<T>& array, T& maxValue, const Less& less)
{
	if (array.size() == 0)
	{
		return false;
	}

	
	auto maxTempValue = array[0];
	for (size_t pos = 1; pos < array.size(); pos++)
	{
		if (less(maxTempValue, array[pos]))
		{
			maxTempValue = array[pos];
		}
	}

	maxValue = maxTempValue;
	return true;
}