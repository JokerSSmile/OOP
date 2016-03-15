#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

bool IsNumber(const string& str)
{
	
	for (unsigned i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]) == false && str[i] != '.' && str[i] != '-')
		{
			return false;
		}
	}
	return true;
}

float CalculateDiscriminant(const float& A, const float& B, const float& C)
{
	return B * B - 4 * A * C;
}

void CalculateAndOutputRoots(const float& A, const float& B, const float& discriminant)
{
	ofstream fout("output.txt");

	float firstRoot = (-B + sqrt(discriminant)) / (2 * A);
	cout << std::setprecision(4) << firstRoot << endl;
	fout << std::setprecision(4) << firstRoot << endl;

	if (discriminant > 0)
	{
		float secondRoot = (-B - sqrt(discriminant)) / (2 * A);
		cout << std::setprecision(4) << secondRoot << endl;
		fout << std::setprecision(4) << secondRoot << endl;
	}

}

bool RunApp(string& strA, string& strB, string& strC)
{
	if (IsNumber(strA) && IsNumber(strB) && IsNumber(strC))
	{
		float A = stof(strA);
		float B = stof(strB);
		float C = stof(strC);

		if (A == 0)
		{
			cout << "There is no real root" << endl;
			return false;
		}

		float discriminant = CalculateDiscriminant(A, B, C);
		if (discriminant < 0)
		{
			cout << "Discriminant is less than 0" << endl;
			return false;
		}

		CalculateAndOutputRoots(A, B, discriminant);
		
	}
	else
	{
		cout << "Incorrect input" << endl;
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc == 4)
	{
		if (!RunApp(string(argv[1]), string(argv[2]), string(argv[3])))
		{
			return 1;
		}
	}
	else
	{
			cout << "Need 3 argument\nInput must be: Lab1_2.exe <A> <B> <C>\nor\nLab1_2.exe <input_file>" << endl;
			return 1;
	}
	return 0;
}
