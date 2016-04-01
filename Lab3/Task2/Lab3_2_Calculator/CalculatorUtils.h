#pragma once
#pragma warning (disable:4996)
#include "Calculator.h"
#include <boost/algorithm/string.hpp>

vector<vector<string>> GetLinesFromInputFile(std::ifstream& fin);

#pragma warning (default:4996)

void OperateWithCommands(const vector<vector<string>>& commands, CCalculator& calculator);