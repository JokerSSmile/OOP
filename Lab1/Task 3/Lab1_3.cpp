#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

const short MATRIX_SIZE = 3;

using namespace std;

void GetInputData(ifstream& file, float matrix[MATRIX_SIZE][MATRIX_SIZE])
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
				matrix[row][col] = num;
				col++;
			}
			row++;
		}
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

float CalculateMatrixAdditions(const int& col, const int& row, float matrix[3][3])
{
	vector<float> tempMatrix;

	for (unsigned i = 0; i < MATRIX_SIZE; i++)
	{
		for (unsigned k = 0; k < MATRIX_SIZE; k++)
		{
			if (i != row && k != col)
			{
				tempMatrix.push_back(matrix[i][k]);
			}
		}
	}

	return static_cast<float> (pow(-1, (col + 1) + (row + 1))*(tempMatrix[0] * tempMatrix[3] - tempMatrix[1] * tempMatrix[2]));
}

void CalculateInverseMatrix(float inverseMatrix[MATRIX_SIZE][MATRIX_SIZE], float unionMatrix[MATRIX_SIZE][MATRIX_SIZE], const float& determinant)
{
	for (unsigned i = 0; i < MATRIX_SIZE; i++)
	{
		for (unsigned k = 0; k < MATRIX_SIZE; k++)
		{
			inverseMatrix[i][k] = unionMatrix[k][i] * (1 / determinant);
		}
	}
}

void DrawResulMatrix(float matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	cout << "Inversed matrix" << endl;
	for (unsigned i = 0; i < MATRIX_SIZE; i++)
	{
		for (unsigned k = 0; k < MATRIX_SIZE; k++)
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

		GetInputData(fin, givenMatrix);

		for (unsigned i = 0; i < MATRIX_SIZE; i++)
		{
			for (unsigned k = 0; k < MATRIX_SIZE; k++)
			{
				unionMatrix[i][k] = CalculateMatrixAdditions(k, i, givenMatrix);
			}
		}

		CalculateInverseMatrix(inverseMatrix, unionMatrix, CalculateMatrixDeterminant(givenMatrix));

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

