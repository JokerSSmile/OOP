#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>

std::vector<double> ReadInputToVector();

std::vector<double> DivideToAHalfOfMaxElement(const std::vector<double>& vec);

void SortVector(std::vector<double>& vec);

void OutputVector(const std::vector<double>& vec);
