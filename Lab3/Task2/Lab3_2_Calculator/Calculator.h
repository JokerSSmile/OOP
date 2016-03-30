#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;

class CCalculator
{
public:
	double GetVariableValue(const string& name);
	bool IsCorrectVariableName(const string& name);
	bool IsVarableAlreadyExist(const string& name);
	std::pair<string, double> CCalculator::CreateVariable(const string& name, const double& value);
	void AddVariable(const vector<string>& parameters);
	void AddFunction(const vector<string>& parameters);

//private:
	vector<string> operators = {"+", "-", "*", "/"};
	map<string, double> variables;
	map<string, vector<string>> functions;
};