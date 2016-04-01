#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;

class CCalculator
{
public:
	double CalculateVariableValue(const string& name) const;
	double CalculateFunctionsBody(const string& name) const;
	bool IsCorrectVariableName(const string& name) const;
	bool IsVarableAlreadyExist(const string& name) const;
	void CreateVariable(const string& name, const double& value = NAN);
	void AddVariable(const vector<string>& parameters);
	void AddFunction(const vector<string>& parameters);
	void OutputVariablesAndValues();
	void OutputFunctionsAndValues();
	int GetVariablesSize();
	int GetFunctiosSize();
private:
	vector<string> operators = {"+", "-", "*", "/"};
	map<string, double> variables;
	map<string, vector<string>> functions;
};