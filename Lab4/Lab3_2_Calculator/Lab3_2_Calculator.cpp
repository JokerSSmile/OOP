#include "stdafx.h"
#include <fstream>
#include "Calculator.h"
#include "CalculatorUtils.h"

int main()
{
	CCalculator calculator;
	std::ifstream fin("input.txt");
	vector<vector<string>> commandsFromFin = GetLinesFromInputFile(fin);
	////map<string, double> m;
	//try
	//{
	//	calculator.AddVariable(abc);
	//}
	//catch (const std::invalid_argument& error)
	//{
	//	cout << error.what() << endl;
	//}
	//for (map<string, double>::iterator it = calculator.variables.begin(); it != calculator.variables.end(); it++)
	//	std::cout << it->first << ' ' << it->second << '\n';




    return 0;
}

