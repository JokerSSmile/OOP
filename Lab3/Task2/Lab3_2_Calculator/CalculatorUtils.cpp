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
	for (auto command : commands)
	{
		cout << "> Processing: ";
		std::copy(command.begin(), command.end(), std::ostream_iterator<string>(std::cout, " "));
		cout << endl;
		if (command[0] == "var")
		{
			try
			{
				calculator.CreateVariable(command[1]);
				cout << "Created variable with name " << command[1] << endl;
			}
			catch (const std::invalid_argument& error)
			{
				cout << error.what() << endl;
			}
		}
		else if (command[0] == "let")
		{
			try
			{
				calculator.AddVariable(command);
				cout << "Now variable " << command[1] << " equals to " << command[3] << endl;
			}
			catch (const std::invalid_argument& error)
			{
				cout << error.what() << endl;
			}
		}
		else if (command[0] == "fn")
		{
			try
			{
				calculator.AddFunction(command);
				cout << "Now function " << command[1] << " equals to ";
				std::copy(command.begin() + 3, command.end(), std::ostream_iterator<string>(std::cout, " "));
				cout << endl;
			}
			catch (const std::invalid_argument& error)
			{
				cout << error.what() << endl;
			}
		}
		else if (command[0] == "print")
		{
			try
			{
				if (calculator.IsVarableAlreadyExist(command[1]))
				{
					try
					{
						cout << command[1] << " = " << std::setprecision(2) << std::fixed << calculator.CalculateVariableValue(command[1]) << endl;
					}
					catch (const std::invalid_argument&)
					{
						cout << command[1] << " = " << std::setprecision(2) << std::fixed << calculator.CalculateFunctionsBody(command[1]) << endl;
					}
				}
				else
				{
					cout << "Unknown variable name \"" << command[1] << "\"" << endl;
				}
			}
			catch (const std::invalid_argument& error)
			{
				cout << error.what() << endl;
			}
		}
		else if (command[0] == "printvars")
		{
			calculator.OutputVariablesAndValues();
		}
		else if (command[0] == "printfns")
		{
			calculator.OutputFunctionsAndValues();
		}
		else
		{
			cout << "Unknown command \"" << command[0] << "\"" << endl;
		}
		cout << endl;
	}
}