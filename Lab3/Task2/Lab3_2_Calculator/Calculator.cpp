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

double CCalculator::GetVariableValue(const string& name)
{
	if (IsVarableAlreadyExist(name))
	{
		return variables.find(name)->second;
	}
	return NAN;
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
	return variables.find(name) != variables.end();
}

std::pair<string, double> CCalculator::CreateVariable(const string& name, const double& value = NAN)
{
	std::pair<string, double> variable;
	if (IsCorrectVariableName(name))
	{
		variable.first = name;
		variable.second = value;
	}
	else
	{
		throw std::invalid_argument("\tIncorrect variable name");
	}
	variables.insert(variable);
	return variable;
}

void CCalculator::AddVariable(const vector<string>& parameters)
{
	if (parameters.size() != 4)
	{
		throw std::invalid_argument("\tIncorect variable declaration (incorrect number of arguments)");
	}
	if (!IsVarableAlreadyExist(parameters[1]))
	{
		CreateVariable(parameters[1]);
	}
	if (IsVarableAlreadyExist(parameters[3]))
	{
		variables.find(parameters[1])->second = variables.find(parameters[3])->second;
	}
	else
	{
		try
		{
			variables.find(parameters[1])->second = boost::lexical_cast<double>(parameters[3]);
		}
		catch (boost::bad_lexical_cast& const)
		{
			cout << "Error in value name" << endl;
			return;
		}
	}

}

void CCalculator::AddFunction(const vector<string>& parameters)
{
	cout << parameters[1] << endl;
	if (parameters.size() != 4 && parameters.size() != 6)
	{
		throw std::invalid_argument("\tIncorect function declaration (incorrect number of arguments)");
	}
	//cout << "1" << IsVarableAlreadyExist(parameters[1]) << endl;
	//cout << "2" << !IsVarableAlreadyExist(parameters[3]) << endl;
	//cout << "3" << (parameters.size() == 4 ? false : !IsVarableAlreadyExist(parameters[5])) << endl;
	//cout << "4" << (parameters[2] != "=") << endl;
	//TODO:repair it
	if (IsVarableAlreadyExist(parameters[1]) || !IsVarableAlreadyExist(parameters[3]) || (parameters.size() == 4 ? false : !IsVarableAlreadyExist(parameters[5])) || parameters[2] != "=")
	{
		throw std::invalid_argument("\tIncorect function declaration (incorrect variable name)");
	}
	if (parameters.size() == 6)
	{
		std::find(operators.begin(), operators.end(), parameters[4]) != operators.end() ? true : throw std::invalid_argument("\tIncorect function declaration (incorrect operator)");
	}
	if (!IsCorrectVariableName(parameters[1]))
	{
		throw std::invalid_argument("\tIncorrect variable name");
	}

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
