#include "stdafx.h"
#include "CalculatorUtils.h"

vector<vector<string>> GetLinesFromInputFile(std::ifstream& fin)
{
	vector<vector<string>> lines;
	string line;
	while (std::getline(fin, line))
	{
		vector<string> currentString;
		boost::split(currentString, line, boost::is_any_of(" "));
		lines.push_back(currentString);
	}
	return lines;
}

void OperateWithCommands(const vector<vector<string>>& commands, CCalculator& calculator)
{
	for (auto a : commands)
	{
		for (auto b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}
}