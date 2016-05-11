#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

const short MATRIX_SIZE = 3;

using namespace std;

bool ReadStartMatrix(ifstream& file, double matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	string line;

	size_t row = 0;
	size_t column;
	string currentNumber;
	while (getline(file, line))
	{
		istringstream myStream(line);
		column = 0;
		while (myStream >> currentNumber)
		{
			try
			{
				matrix[row][column] = stod(currentNumber);
				column++;
			}
			catch (const std::exception&)
			{
				return false;
			}
		}
		row++;
	}
	return true;
}

double CalculateMatrixDeterminant(double matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	double firstDiagonalPlus = { matrix[0][0] * matrix[1][1] * matrix[2][2] };
	double firstDiagonalMinus = { matrix[0][2] * matrix[1][1] * matrix[2][0] };
	double secondDiagonalPlus = { matrix[0][1] * matrix[1][2] * matrix[2][0] };
	double secondDiagonalMinus = { matrix[0][1] * matrix[1][0] * matrix[2][2] };
	double thirdDiagonalPlus = { matrix[0][2] * matrix[1][0] * matrix[2][1] };
	double thirdDiagonalMinus = { matrix[0][0] * matrix[1][2] * matrix[2][1] };

	return firstDiagonalPlus + secondDiagonalPlus + thirdDiagonalPlus - firstDiagonalMinus - secondDiagonalMinus - thirdDiagonalMinus;
}

double CalculateMatrixAdditions(const int& col, const int& row, double matrix[3][3])
{
	vector<double> matrixElementsExcludingElementsOnColumnAndRow;

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

	return (pow(-1, (col + 1) + (row + 1))*(matrixElementsExcludingElementsOnColumnAndRow[0] * matrixElementsExcludingElementsOnColumnAndRow[3] - matrixElementsExcludingElementsOnColumnAndRow[1] * matrixElementsExcludingElementsOnColumnAndRow[2]));
}

void CalculateInverseMatrix(double inverseMatrix[MATRIX_SIZE][MATRIX_SIZE], double unionMatrix[MATRIX_SIZE][MATRIX_SIZE], const double& determinant)
{
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t k = 0; k < MATRIX_SIZE; k++)
		{
			inverseMatrix[i][k] = unionMatrix[k][i] * (1 / determinant);
		}
	}
}

void OutputResulMatrix(double matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	ostringstream outStream;
	ofstream fout("output.txt");
	cout << "Inversed matrix" << endl;
	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t k = 0; k < MATRIX_SIZE; k++)
		{
			outStream << std::setprecision(3) << std::fixed << matrix[i][k] << "\t";
		}
		outStream << endl;

	}
}

bool CalculateRoots(double givenMatrix[MATRIX_SIZE][MATRIX_SIZE], double inverseMatrix[MATRIX_SIZE][MATRIX_SIZE])
{
	double unionMatrix[MATRIX_SIZE][MATRIX_SIZE];

	double determinant = CalculateMatrixDeterminant(givenMatrix);
	if (determinant == 0)
	{
		cout << "Inverse martix does not exist. Determinant of the given matrix is 0" << endl;
		return false;
	}

	for (size_t i = 0; i < MATRIX_SIZE; i++)
	{
		for (size_t k = 0; k < MATRIX_SIZE; k++)
		{
			unionMatrix[i][k] = CalculateMatrixAdditions(k, i, givenMatrix);
		}
	}

	CalculateInverseMatrix(inverseMatrix, unionMatrix, determinant);

	return true;
}

bool CalculateAndOutputResult(string& inputFileName)
{
	ifstream fin(inputFileName);
	if (fin.is_open() == false)
	{
		cout << "Error while opening file" << endl;
		return false;
	}

	double givenMatrix[MATRIX_SIZE][MATRIX_SIZE];
	double inverseMatrix[MATRIX_SIZE][MATRIX_SIZE];

	if (!ReadStartMatrix(fin, givenMatrix))
	{
		cout << "Incorrect input" << endl;
		return false;
	}

	CalculateRoots(givenMatrix, inverseMatrix);
	
	OutputResulMatrix(inverseMatrix);

	return true;
}

int main(int argc, char* argv[])
{
	cout << "This program inserts given matrix\n" << endl;
	if (argc == 2)
	{
		if (!CalculateAndOutputResult(string(argv[1])))
		{
			return 1;
		}
	}
	else
	{
		cout << "Input must be:\nLab1_3.exe <matrix.txt>" << endl;
		return 1;
	}
    return 0;
}

