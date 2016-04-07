#include "stdafx.h"
#include "RectangleUtils.h"


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Error: Usage: Lab3_1_Rectangle.exe <input_file1> <input_file2>" << endl;
		return 1;
	}
	std::ifstream fin1(argv[1]);
	std::ifstream fin2(argv[2]);
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
	catch (const std::invalid_argument&)
	{
		cout << "Error: Invalid parameter value" << endl;
		return 1;
	}
	catch (const std::exception& error)
	{
		cout << error.what() << endl;
		return 1;
	}
    return 0;
}

