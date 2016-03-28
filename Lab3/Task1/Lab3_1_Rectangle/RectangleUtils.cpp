#include "stdafx.h"
#include "RectangleUtils.h"
#include <boost/algorithm/string.hpp>

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

void ApplyCommandsToRectangle(vector<CRectangle>& rectangles, const vector<vector<string>>& commands)
{
	bool isDeclared = false;
	CRectangle rectangle;
	for (auto command : commands)
	{
		if (command[0] == "Rectangle")
		{
			if (command.size() != 5)
			{
				throw std::invalid_argument("Error: To create rectangle you must give 5 parameters:\n  Rectangle <left> <top> <width> <height>.");
				return;
			}
			if (isDeclared == true)
			{
				throw std::invalid_argument("Error: Declared 2 rectangles in 1 file");
				return;
			}
			isDeclared = true;
			rectangle = CRectangle(stoi(command[1]), stoi(command[2]), stoi(command[3]), stoi(command[4]));
		}
		else if (command[0] == "Move")
		{
			if (command.size() != 3)
			{
				throw std::invalid_argument("Error: To move rectangle you must give 3 parameters:\n  Move <dx> <dy>.");
				return;
			}
			rectangle.Move(stoi(command[1]), stoi(command[2]));
		}
		else if (command[0] == "Scale")
		{
			if (command.size() != 3)
			{
				throw std::invalid_argument("Error: To scale rectangle you must give 3 parameters:\n  Scale <sx> <sy>.");
				return;
			}
			rectangle.Scale(stoi(command[1]), stoi(command[2]));
		}
	}
	rectangles.push_back(rectangle);
}

void OutputInfo(const vector<CRectangle>& rectangles)
{
	short currentRectNumber = 1;
	for (auto rectangle : rectangles)
	{
		
		cout << "Rectangle " << currentRectNumber << endl;
		cout << "\tLeft Top: " << rectangle.GetLeft() << ", " << rectangle.GetTop() << endl;
		cout << "\tSize:" << rectangle.GetWidth() << " * " << rectangle.GetHeight() << endl;
		cout << "\tRight Bottom: " << rectangle.GetRight() << ", " << rectangle.GetBottom() << endl;
		cout << "\tArea: " << rectangle.GetArea() << endl;
		cout << "\tPerimeter: " << rectangle.GetPerimeter() << endl;
		currentRectNumber++;
		
	}
}

void OutputIntersectionInfo(vector<CRectangle>& rectangles)
{
	if (rectangles[0].Intersects(rectangles[1]))
	{
		
		cout << "Intersection rectangle" << endl;
		cout << "\tLeft Top: " << rectangles[0].GetLeft() << ", " << rectangles[0].GetTop() << endl;
		cout << "\tSize:" << rectangles[0].GetWidth() << " * " << rectangles[0].GetHeight() << endl;
		cout << "\tRight Bottom: " << rectangles[0].GetRight() << ", " << rectangles[0].GetBottom() << endl;
		cout << "\tArea: " << rectangles[0].GetArea() << endl;
		cout << "\tPerimeter: " << rectangles[0].GetPerimeter() << endl;
		
	}
	else
	{
		cout << "Rectangles do not intersect" << endl;
	}
}