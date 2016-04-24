#include "stdafx.h"
#include <boost/algorithm/string.hpp>
#include <boost/math/constants/constants.hpp>
#include "ShapeUtils.h"
#include "CShape.h"

const double C_PI = boost::math::constants::pi<double>();

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

void CreateRectangle(const std::vector<std::string>& command, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures)
{
	if (command.size() != 7)
	{
		throw std::exception("\tError: Invalid parameters count to create rectangle");
	}
	try
	{
		double x = stod(command[1]);
		double y = stod(command[2]);
		double width = stod(command[3]);
		double height = stod(command[4]);
		if (width < 0 || height < 0)
		{
			throw std::exception("");
		}
		figures.push_back(std::make_shared<CRectangle>(x, y, width, height, command[5], command[6]));
		std::shared_ptr<sf::Shape> rect = std::make_shared<sf::RectangleShape>(sf::Vector2f(float(width), float(height)));
		rect->setPosition(float(x), float(y));
		rect->setOutlineThickness(3);
		rect->setOutlineColor(HexToRgb(command[5]));
		rect->setFillColor(HexToRgb(command[6]));
		drawableFigures.push_back(rect);
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create rectangle");
	}
}

void CreateCircle(const std::vector<std::string>& command, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures)
{
	if (command.size() != 6)
	{
		throw std::exception("\tError: Invalid parameters count to create circle");
	}
	try
	{
		double x = stod(command[1]);
		double y = stod(command[2]);
		double radius = stod(command[3]);
		if (radius < 0)
		{
			throw std::exception("");
		}
		figures.push_back(std::make_shared<CCircle>(x, y, radius, command[4], command[5]));
		std::shared_ptr<sf::Shape> circle = std::make_shared<sf::CircleShape>(int(radius));
		circle->setOrigin(sf::Vector2f(float(radius), float(radius)));
		circle->setPosition(float(x), float(y));
		circle->setOutlineThickness(3);
		circle->setOutlineColor(HexToRgb(command[4]));
		circle->setFillColor(HexToRgb(command[5]));
		drawableFigures.push_back(circle);
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create circle");
	}
}

void CreateLine(const std::vector<std::string>& command, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures)
{
	if (command.size() != 6)
	{
		throw std::exception("\tError: Invalid parameters count to create line");
	}
	try
	{
		double x1 = stod(command[1]);
		double y1 = stod(command[2]);
		double x2 = stod(command[3]);
		double y2 = stod(command[4]);
		figures.push_back(std::make_shared<CLineSegment>(x1, y1, x2, y2, command[5]));
		std::shared_ptr<sf::Shape> line = std::make_shared<sf::RectangleShape>(sf::Vector2f(float(figures.back()->GetPerimeter()), 3.f));
		x2 < x1 ? line->setPosition(float(x2), float(y2)) : line->setPosition(float(x1), float(y1));
		line->setRotation(float(std::atan((y2 - y1) / (x2 - x1)) * 180 / C_PI));
		line->setFillColor(HexToRgb(command[5]));
		drawableFigures.push_back(line);
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create line");
	}
}

void CreateTriangle(const std::vector<std::string>& command, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures)
{
	if (command.size() != 9)
	{
		throw std::exception("\tError: Invalid parameters count to create triangle");
	}
	try
	{
		double x1 = stod(command[1]);
		double y1 = stod(command[2]);
		double x2 = stod(command[3]);
		double y2 = stod(command[4]);
		double x3 = stod(command[5]);
		double y3 = stod(command[6]);
		figures.push_back(std::make_shared<CTriangle>(x1, y1, x2, y2, x3,
			y3, command[7], command[8]));
		std::shared_ptr<sf::ConvexShape> triangle = std::make_shared<sf::ConvexShape>(3);
		triangle->setPoint(0, (sf::Vector2f(float(x1), float(y1))));
		triangle->setPoint(1, (sf::Vector2f(float(x2), float(y2))));
		triangle->setPoint(2, (sf::Vector2f(float(x3), float(y3))));
		triangle->setOutlineThickness(3);
		triangle->setOutlineColor(HexToRgb(command[7]));
		triangle->setFillColor(HexToRgb(command[8]));
		drawableFigures.push_back(triangle);
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create triangle");
	}
}

void CreatePoint(const std::vector<std::string>& command, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures)
{
	if (command.size() != 4)
	{
		throw std::exception("\tError: Invalid parameters count to create point");
	}
	try
	{
		double x = stod(command[1]);
		double y = stod(command[2]);
		figures.push_back(std::make_shared<CPoint>(x, y, command[3]));
		std::shared_ptr<sf::Shape> point = std::make_shared<sf::CircleShape>(2);
		point->setPosition(float(x), float(y));
		point->setFillColor(HexToRgb(command[3]));
		drawableFigures.push_back(point);
	}
	catch (const std::exception&)
	{
		throw std::exception("\tError: Invalid parameters to create point");
	}
}

void ParseCommands(const std::vector<std::vector<std::string>>& commands, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures)
{
	for (const auto& command : commands)
	{
		try
		{
			std::cout << "> Parsing:" << std::endl;
			std::copy(command.begin(), command.end(), std::ostream_iterator<std::string>(std::cout, " "));
			std::cout << std::endl;
			if (command[0] == "rectangle")
			{
				CreateRectangle(command, figures, drawableFigures);
			}
			else if (command[0] == "circle")
			{
				CreateCircle(command, figures, drawableFigures);
			}
			else if (command[0] == "line")
			{
				CreateLine(command, figures, drawableFigures);
			}
			else if (command[0] == "triangle")
			{
				CreateTriangle(command, figures, drawableFigures);
			}
			else if (command[0] == "point")
			{
				CreatePoint(command, figures, drawableFigures);
			}
			else
			{
				throw std::exception("\tError: Invalid command");
			}
		}
		catch (const std::exception& error)
		{
			std::cout << error.what() << std::endl;
		}
	}
}

void OutputInfoAboutShapes(const std::vector<std::shared_ptr<CShape>>& figures)
{
	if (figures.size() == 0)
	{
		std::cout << "Nothing to output" << std::endl;
		return;
	}
	std::vector<std::shared_ptr<CShape>> figuresCopy = figures;

	std::sort(figuresCopy.begin(), figuresCopy.end(), [](std::shared_ptr<CShape>& shape1, std::shared_ptr<CShape>& shape2) {return shape1->GetPerimeter() < shape2->GetPerimeter();});
	std::cout << ">Sorted by perimeter" << std::endl;
	for (const auto& figure : figuresCopy)
	{
		std::cout << figure->ToString() << std::endl;
	}

	std::cout << std::endl;

	std::sort(figuresCopy.begin(), figuresCopy.end(), [](std::shared_ptr<CShape>& shape1, std::shared_ptr<CShape>& shape2) {return shape1->GetArea() < shape2->GetArea();});
	std::cout << ">Sorted by area" << std::endl;
	for (const auto& figure : figuresCopy)
	{
		std::cout << figure->ToString() << std::endl;
	}
}