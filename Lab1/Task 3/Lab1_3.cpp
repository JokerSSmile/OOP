// Lab1_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

const short MATRIX_SIZE = 3;

using namespace std;

void GetInputData(ifstream& file, float matrix[3][3])
{
	string line;
	int row = 0;
	int col;
	float num;
	while (!file.eof())
	{
		while (getline(file, line))
		{
			istringstream myStream(line);
			col = 0;
			while (myStream >> num)
			{
				cout << num << endl;
				matrix[row][col] = num;
				col++;
			}
			row++;
		}
	}
	cout << "Matrix readed from file" << endl;
	for (unsigned i = 0; i < MATRIX_SIZE; i++)
	{
		for (unsigned k = 0; k < MATRIX_SIZE; k++)
		{
			cout << matrix[i][k] << "\t";
		}
		cout << endl;
	}
}

float CalculateMatrixDeterminant(float matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	float linePlus = { matrix[0][0] * matrix[1][1] * matrix[2][2] };
	float lineMinus = { matrix[0][2] * matrix[1][1] * matrix[2][0] };
	float firstTrianglePlus = { matrix[0][1] * matrix[1][2] * matrix[2][0] };
	float firstTriangleMinus = { matrix[0][1] * matrix[1][0] * matrix[2][2] };
	float secondTrianglePlus = { matrix[0][2] * matrix[1][0] * matrix[2][1] };
	float secondTriangleMinus = { matrix[0][0] * matrix[1][2] * matrix[2][1] };

	return linePlus + firstTrianglePlus + secondTrianglePlus - lineMinus - firstTriangleMinus - secondTriangleMinus;
}

void CalculateMatrixAdditions(int col, int row, float matrix[3][3])
{
	vector<float> tempMatrix;
	int currentCol = 0;
	int currentRow = 0;

	for (unsigned i = 0; i < MATRIX_SIZE; i++)
	{
		for (unsigned k = 0; k < MATRIX_SIZE; k++)
		{
			if (i != row || k != col)
			{
				tempMatrix.push_back(matrix[i][k]);
			}
		}
	}
	for (auto a : tempMatrix)
	{
		cout << a << endl;
	}
	cout << "\n" << endl;
}

void RunApp(char inputFileName[])
{
	ifstream fin(inputFileName);
	if (fin.is_open() == false)
	{
		cout << "Error while opening file" << endl;
	}
	else
	{
		float givenMatrix[MATRIX_SIZE][MATRIX_SIZE];
		GetInputData(fin, givenMatrix);
		CalculateMatrixDeterminant(givenMatrix);
		for (unsigned i = 0; i < MATRIX_SIZE; i++)
		{
			for (unsigned k = 0; k < MATRIX_SIZE; k++)
			{
				CalculateMatrixAdditions(k, i, givenMatrix);
			}
		}
	}
	fin.close();
}

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		RunApp(argv[1]);
	}
	else
	{
		cout << "Input 1 argument" << endl;
	}
	system("pause");
    return 0;
}

