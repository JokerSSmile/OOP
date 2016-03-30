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
	bool IsCorrectVariableName(const string& name);
	bool IsVarableAlreadyExist(const string& name);
	void AddVariable(const vector<string>& parameters);
	void AddFunction(const vector<string>& parameters);

//private:
	vector<string> operators = {"+", "-", "*", "/"};
	map<string, double> variables;
	map<string, vector<string>> functions;
};