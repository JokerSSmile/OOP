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

bool CalculateRoots(const double& A, const double& B, const double& C, double& root1, double& root2)
{
	double discriminant = B * B - 4 * A * C;
	if (discriminant < 0)
	{
		cout << "Discriminant is less than 0" << endl;
		return false;
	}
	root1 = (-B + sqrt(discriminant)) / (2 * A);
	root2 = (-B - sqrt(discriminant)) / (2 * A);
	return true;
}

void OutputRoots(const double& root1, const double& root2)
{
	ofstream fout("output.txt");
	cout << std::setprecision(4) << root1 << endl;
	fout << std::setprecision(4) << root1 << endl;
	cout << std::setprecision(4) << root2 << endl;
	fout << std::setprecision(4) << root2 << endl;
}

int main(int argc, char* argv[])
{
	if (argc == 4)
	{
		string strA = static_cast<string>(argv[1]);
		string strB = static_cast<string>(argv[2]);
		string strC = static_cast<string>(argv[3]);
		if (IsNumber(strA) && IsNumber(strB) && IsNumber(strC))
		{
			double A = stof(strA);
			double B = stof(strB);
			double C = stof(strC);
			double root1;
			double root2;
			if (A == 0)
			{
				cout << "There is no real root" << endl;
				return 1;
			}
			if (!CalculateRoots(A, B, C, root1, root2))
			{
				return 1;
			}
			OutputRoots(root1, root2);
		}
		else
		{
			cout << "Incorrect input" << endl;
			return 1;
		}
	}
	else
	{
			cout << "Need 3 argument\nInput must be: Lab1_2.exe <A> <B> <C>\n" << endl;
			return 1;
	}
	return 0;
}
