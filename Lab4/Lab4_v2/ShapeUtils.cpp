#include "stdafx.h"
#include "ShapeUtils.h"

std::vector<std::vector<std::string>> GetInputData()
{
	std::vector<std::vector<std::string>> lines;
	std::string line;
	while (std::getline(std::cin, line))
	{
		if (line.empty())
		{
			return lines;
		}
		std::vector<std::string> currentString;
		boost::split(currentString, line, std::bind2nd(std::equal_to<char>(), ' '));
		lines.push_back(currentString);
	}
	return lines;
}

void CreateRectangle(const std::vector<std::string>& command, std::vector<std::unique_ptr<IShape>>& figures)
{
	if (command.size() != 7)
	{
		throw std::exception("\tError: Invalid parameters count to create rectangle");
	}
	try
	{
		figures.push_back(std::make_unique<CRectangle>(stof(command[1]), stof(command[2]), stof(command[3]), stof(command[4]), command[5], command[6]));
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create rectangle");
	}
}

void CreateCircle(const std::vector<std::string>& command, std::vector<std::unique_ptr<IShape>>& figures)
{
	if (command.size() != 6)
	{
		throw std::exception("\tError: Invalid parameters count to create circle");
	}
	try
	{
		figures.push_back(std::make_unique<CCircle>(stof(command[1]), stof(command[2]), stof(command[3]), command[4], command[5]));
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create circle");
	}
}

void CreateLine(const std::vector<std::string>& command, std::vector<std::unique_ptr<IShape>>& figures)
{
	if (command.size() != 6)
	{
		throw std::exception("\tError: Invalid parameters count to create line");
	}
	try
	{
		figures.push_back(std::make_unique<CLineSegment>(stof(command[1]), stof(command[2]), stof(command[3]), stof(command[4]), command[5]));
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create line");
	}
}

void CreateTriangle(const std::vector<std::string>& command, std::vector<std::unique_ptr<IShape>>& figures)
{
	if (command.size() != 9)
	{
		throw std::exception("\tError: Invalid parameters count to create triangle");
	}
	try
	{
		figures.push_back(std::make_unique<CTriangle>(stof(command[1]), stof(command[2]), stof(command[3]), stof(command[4]), stof(command[5]),
			stof(command[6]), command[7], command[8]));
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create triangle");
	}
}

void CreatePoint(const std::vector<std::string>& command, std::vector<std::unique_ptr<IShape>>& figures)
{
	if (command.size() != 4)
	{
		throw std::exception("\tError: Invalid parameters count to create point");
	}
	try
	{
		figures.push_back(std::make_unique<CPoint>(stof(command[1]), stof(command[2]), command[3]));
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create point");
	}
}

void ParseCommands(const std::vector<std::vector<std::string>>& commands, std::vector<std::unique_ptr<IShape>>& figures)
{
	for (const auto& command : commands)
	{
		try
		{
			cout << "> Parsing:" << endl;
			std::copy(command.begin(), command.end(), std::ostream_iterator<std::string>(std::cout, " "));
			cout << endl;
			if (command[0] == "rectangle")
			{
				CreateRectangle(command, figures);
			}
			else if (command[0] == "circle")
			{
				CreateCircle(command, figures);
			}
			else if (command[0] == "line")
			{
				CreateLine(command, figures);
			}
			else if (command[0] == "triangle")
			{
				CreateTriangle(command, figures);
			}
			else if (command[0] == "point")
			{
				CreatePoint(command, figures);
			}
			else
			{
				throw std::exception("\tError: Invalid command");
			}
		}
		catch (const std::exception& error)
		{
			cout << error.what() << endl;
		}
	}
}

void OutputInfoAboutShape(const std::unique_ptr<IShape>& figure)
{
	cout << figure->GetType() << " " << figure->GetArea() << " " << figure->GetPerimeter() << endl;
}