#include "stdafx.h"
#include <fstream>
#include "Calculator.h"
#include "CalculatorUtils.h"

int main()
{
	CCalculator calculator;
	std::ifstream fin("input.txt");
	vector<vector<string>> commandsFromFin = GetLinesFromInputFile(fin);

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
		calculator.AddFunction(commandsFromFin[3]);
		calculator.AddFunction(commandsFromFin[4]);
	}
	catch(const std::invalid_argument& err)
	{
		cout << err.what() << endl;
	}
	/*
	cout << calculator.variables.size() << " " << calculator.functions.size() << endl;
	cout << "vars" << endl;
	for (auto mapa : calculator.variables)
	{
		cout << mapa.first << " = " << mapa.second << endl;
	}
	cout << "fns" << endl;
	
	for (auto mapa : calculator.functions)
	{
		cout << mapa.first << " ";
		for (auto a : mapa.second)
		{
			cout << a << " ";
		}
		cout << endl;
	}
	cout << "--------------" << endl;

	try
	{
		cout << calculator.CalculateFunctionsBody("C") << endl;
	}
	catch (const std::invalid_argument& err)
	{
		cout << err.what() << endl;
	}
	*/
	calculator.OutputVariablesAndValues();
	cout << "----------" << endl;
	calculator.OutputFunctionsAndValues();
    return 0;
}

