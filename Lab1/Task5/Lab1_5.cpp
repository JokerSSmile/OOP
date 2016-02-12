#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Vector2i
{
	int x;
	int y;
};

void FillStartMatrix(const string& line, char labyrinthMatrix[100][100], const int& lineCounter, Vector2i& startPos, Vector2i& endPos)
{
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] == 'A' || line[i] == 'a')
		{
			startPos = { static_cast<int>(i), lineCounter };
		}
		else if (line[i] == 'B' || line[i] == 'b')
		{
			endPos = { static_cast<int>(i), lineCounter };
		}

		labyrinthMatrix[lineCounter][i] = line[i];
	}
}

void UpdateMaximumLineLength(short& maxLineLength, const string& line)
{
	if (line.size() > maxLineLength)
	{
		maxLineLength = line.size();
	}
}

void FillMatrixDependsOnMaxLength(const short& lineCounter, const short& maxLineLength, char labyrinthMatrix[100][100])
{
	for (size_t i = 0; i < lineCounter; i++)
	{
		for (size_t k = 0; k < maxLineLength; k++)
		{
			if (static_cast<int>(labyrinthMatrix[i][k]) == -52)
			{
				labyrinthMatrix[i][k] = ' ';
			}
		}
	}
}

void GetInputData(ifstream& inputFile, char labyrinthMatrix[100][100])
{
	string line;
	short lineCounter = 0;
	short maxLineLength = 0;
	Vector2i startPos;
	Vector2i endPos;

	while (!inputFile.eof())
	{
		getline(inputFile, line);
		if (line.size() > 0)
		{
			UpdateMaximumLineLength(maxLineLength, line);
			FillStartMatrix(line, labyrinthMatrix, lineCounter, startPos, endPos);
			lineCounter++;
		}
		
	}
	
	FillMatrixDependsOnMaxLength(lineCounter, maxLineLength, labyrinthMatrix);
}

void RunApp(char* inputFileName)
{
	char labyrinthMatrix[100][100];
	ifstream inputFile(inputFileName);
	
	if (!inputFile.is_open())
	{
		cout << "Error while opening file" << endl;
		return;
	}
	
	GetInputData(inputFile, labyrinthMatrix);

	///////////////////////////////////
	//output
	//

	for (size_t i = 0; i < lineCounter; i++)
	{
		for (size_t k = 0; k < maxLineLength; k++)
		{
			cout << labyrinthMatrix[i][k];
		}
		cout << endl;
	}

	cout << startPos.x << " " << startPos.y << endl;
	cout << endPos.x << " " << endPos.y << endl;

	cout << labyrinthMatrix[startPos.y][startPos.x] << endl;
	cout << labyrinthMatrix[endPos.y][endPos.x] << endl;

	//
	///////////////////////////////////
}

int main(int argc, char* argv[])
{
	//if (argc == 2)
	//{
		//RunApp(argv[1]);
		RunApp("input.txt");
	//}
		system("pause");
    return 0;
}
