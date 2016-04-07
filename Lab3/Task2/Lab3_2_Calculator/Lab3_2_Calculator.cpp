#include "stdafx.h"
#include <fstream>
#include "CalculatorUtils.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: Lab3_2_Calculator <input_file>" << endl;
		return 1;
	}
	CCalculator calculator;
	std::ifstream fin(argv[1]);
	vector<vector<string>> commandsFromFin = GetLinesFromInputFile(fin);
	OperateWithCommands(commandsFromFin, calculator);
    return 0;
}

