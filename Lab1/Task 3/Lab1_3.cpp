#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

const short MATRIX_SIZE = 3;

using namespace std;

void ReadStartMatrix(ifstream& file, float matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	string line;

	int row = 0;
	int column;
	float currentNumber;
	while (!file.eof())
	{
		while (getline(file, line))
		{
			istringstream myStream(line);
			column = 0;
			while (myStream >> currentNumber)
			{
				matrix[row][column] = currentNumber;
				column++;
			}
			row++;
		}
	}
}

float CalculateMatrixDeterminant(float matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	float firstDiagonalPlus = { matrix[0][0] * matrix[1][1] * matrix[2][2] };
	float firstDiagonalMinus = { matrix[0][2] * matrix[1][1] * matrix[2][0] };
	float secondDiagonalPlus = { matrix[0][1] * matrix[1][2] * matrix[2][0] };
	float secondDiagonalMinus = { matrix[0][1] * matrix[1][0] * matrix[2][2] };
	float thirdDiagonalPlus = { matrix[0][2] * matrix[1][0] * matrix[2][1] };
	float thirdDiagonalMinus = { matrix[0][0] * matrix[1][2] * matrix[2][1] };

	return firstDiagonalPlus + secondDiagonalPlus + thirdDiagonalPlus - firstDiagonalMinus - secondDiagonalMinus - thirdDiagonalMinus;
}

float CalculateMatrixAdditions(const int& col, const int& row, float matrix[3][3])
{
	vector<float> matrixElementsExcludingElementsOnColumnAndRow;

	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t k = 0; k < MATRIX_SIZE; k++)
		{
			if (i != row && k != col)
			{
				matrixElementsExcludingElementsOnColumnAndRow.push_back(matrix[i][k]);
			}
		}
	}

	return static_cast<float> (pow(-1, (col + 1) + (row + 1))*(matrixElementsExcludingElementsOnColumnAndRow[0] * matrixElementsExcludingElementsOnColumnAndRow[3] - matrixElementsExcludingElementsOnColumnAndRow[1] * matrixElementsExcludingElementsOnColumnAndRow[2]));
}

void CalculateInverseMatrix(float inverseMatrix[MATRIX_SIZE][MATRIX_SIZE], float unionMatrix[MATRIX_SIZE][MATRIX_SIZE], const float& determinant)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t k = 0; k < MATRIX_SIZE; k++)
		{
			inverseMatrix[i][k] = unionMatrix[k][i] * (1 / determinant);
		}
	}
}

void DrawResulMatrix(float matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	cout << "Inversed matrix" << endl;
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t k = 0; k < MATRIX_SIZE; k++)
		{
			cout << int(matrix[i][k] * 1000) / 1000.0 << "\t";
		}
		cout << endl;
	}
}

void RunApp(char* inputFileName)
{
	ifstream fin(inputFileName);
	if (fin.is_open() == false)
	{
		cout << "Error while opening file" << endl;
	}
	else
	{
		float givenMatrix[MATRIX_SIZE][MATRIX_SIZE];
		float unionMatrix[MATRIX_SIZE][MATRIX_SIZE];
		float inverseMatrix[MATRIX_SIZE][MATRIX_SIZE];

		float determinant = CalculateMatrixDeterminant(givenMatrix);
		if (determinant == 0)
		{
			cout << "Inverse martix does not exist. Determinant of the given matrix is 0" << endl;
			return;
		}

		ReadStartMatrix(fin, givenMatrix);

		for (size_t i = 0; i < MATRIX_SIZE; i++)
		{
			for (size_t k = 0; k < MATRIX_SIZE; k++)
			{
				unionMatrix[i][k] = CalculateMatrixAdditions(k, i, givenMatrix);
			}
		}

		CalculateInverseMatrix(inverseMatrix, unionMatrix, determinant);

		DrawResulMatrix(inverseMatrix);
	}
	fin.close();
}

int main(int argc, char* argv[])
{
	cout << "This program inserts given matrix\n" << endl;
	if (argc == 2)
	{
		RunApp(argv[1]);
	}
	else
	{
		cout << "Input must be:\nLab1_3.exe <matrix.txt>" << endl;
	}
	system("pause");
    return 0;
}

