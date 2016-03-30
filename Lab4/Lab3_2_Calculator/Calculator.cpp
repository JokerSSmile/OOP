#include "stdafx.h"
#include "Calculator.h"
#include <boost\lexical_cast.hpp>

bool IsEngStr(const string& str)
{
	for (const auto& ch : str)
	{
		if ((ch < 'A' || ch > 'z') || (ch > 'Z'  && ch < 'a'))
		{
			return false;
		}
	}
	return true;
}

bool CCalculator::IsCorrectVariableName(const string& name)
{
	if (name.size() == 0)
	{
		return false;
	}
	if (isdigit(name[0]))
	{
		return false;
	}
	return IsEngStr(name);
}

bool CCalculator::IsVarableAlreadyExist(const string& name)
{
	return variables.find(name) == variables.end();
}

void CCalculator::AddVariable(const vector<string>& parameters)
{
	if (!IsCorrectVariableName(parameters[0]))
	{
		throw std::invalid_argument("SKIP\n\tIncorrect variable name");
	}
	if (!IsVarableAlreadyExist(parameters[0]))
	{
		throw std::invalid_argument("SKIP\n\tVariable name already exists");
	}
	std::pair<string, double> variable;
	variable.first = parameters[0];
	variable.second = NAN;
	if (parameters.size() == 1)
	{
		variables.insert(variable);
		return;
	}
	try
	{
		variable.second = boost::lexical_cast<double>(parameters[1]);
	}
	catch (boost::bad_lexical_cast& const)
	{
		throw std::invalid_argument("SKIP\n\tWrong value argument");
	}
	variables.insert(variable);
}

void CCalculator::AddFunction(const vector<string>& parameters)
{
	if (parameters.size() != 4 || parameters.size() != 6)
	{
		throw std::invalid_argument("SKIP\n\tIncorect function declaration (incorrect number of arguments)");
	}
	if ((!IsVarableAlreadyExist(parameters[1]) && IsVarableAlreadyExist(parameters[3]) && (parameters.size() == 4 ? IsVarableAlreadyExist(parameters[5]) : true)) || parameters[2] != "=")
	{
		throw std::invalid_argument("SKIP\n\tIncorect function declaration (incorrect variable name)");
	}
	std::find(operators.begin(), operators.end(), parameters[4]) == operators.end() ? true : throw std::invalid_argument("SKIP\n\tIncorect function declaration (incorrect operator)");

	vector<string> copyParams = parameters;
	vector<string> functionBody;
	if (copyParams.size() == 4)
	{
		functionBody.push_back(parameters[3]);
		functions.insert(std::pair<string, vector<string>>(parameters[1], functionBody));
	}
	else
	{
		for (size_t i = 3; i < 6; i++)
		{
			functionBody.push_back(parameters[i]);
		}
		functions.insert(std::pair<string, vector<string>>(parameters[1], functionBody));
	}
}
