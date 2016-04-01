#include "stdafx.h"
#include <fstream>
#include "CalculatorUtils.h"

int main()
{
	CCalculator calculator;
	std::ifstream fin("input.txt");
	vector<vector<string>> commandsFromFin = GetLinesFromInputFile(fin);
	OperateWithCommands(commandsFromFin, calculator);
	/*
	for (auto a : commandsFromFin)
	{
		for (auto b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}

	try
	{
		calculator.AddVariable(commandsFromFin[0]);
		calculator.AddVariable(commandsFromFin[1]);
		calculator.AddVariable(commandsFromFin[2]);
		calculator.AddVariable(commandsFromFin[3]);
		calculator.AddVariable(commandsFromFin[4]);
		calculator.AddFunction(commandsFromFin[5]);
		calculator.AddFunction(commandsFromFin[6]);
		calculator.AddFunction(commandsFromFin[7]);
		calculator.AddFunction(commandsFromFin[8]);
	}
	catch(const std::invalid_argument& err)
	{
		cout << err.what() << endl;
	}
	calculator.OutputVariablesAndValues();
	cout << "----------" << endl;
	calculator.OutputFunctionsAndValues();
	*/
    return 0;
}

