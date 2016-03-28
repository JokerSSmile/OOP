#include "stdafx.h"
#include "RectangleUtils.h"


int main()
{
	std::ifstream fin1("input1.txt");
	std::ifstream fin2("input2.txt");
	if (!fin1.is_open() || !fin2.is_open())
	{
		cout << "Error: Can not open input files" << endl;
		return 1;
	}
	vector<CRectangle> rectangles;
	vector<vector<string>> commandsFirstRect = GetLinesFromInputFile(fin1);
	vector<vector<string>> commandsSecondRect = GetLinesFromInputFile(fin2);
	try
	{
		ApplyCommandsToRectangle(rectangles, commandsFirstRect);
		ApplyCommandsToRectangle(rectangles, commandsSecondRect);
		OutputInfo(rectangles);
		OutputIntersectionInfo(rectangles);
	}
	catch (const std::invalid_argument& error)
	{
		cout << error.what() << endl;
		return 1;
	}
    return 0;
}

