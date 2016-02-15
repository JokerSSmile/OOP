#include <iostream>
#include <string>

using namespace std;

struct Vector2f
{
	float x;
	float y;
};

bool IsNumber(char str[])
{
	for (unsigned i = 0; i < strlen(str); i++)
	{
		if (isdigit(str[i]) == false && str[i] != '.')
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

Vector2f CalculateRoots(const float& discriminant, const float& A, const float& B)
{
	Vector2f roots;
	roots.x = (-B + sqrt(discriminant)) / (2 * A);
	roots.y = (-B - sqrt(discriminant)) / (2 * A);
	return roots;
}

void RunApp(char strA[], char strB[], char strC[])
{
	if (IsNumber(strA) && IsNumber(strB) && IsNumber(strC))
	{
		float A = static_cast<float>(atof(strA));
		float B = static_cast<float>(atof(strB));
		float C = static_cast<float>(atof(strC));

		if (A == 0)
		{
			cout << "There is no real root" << endl;
			return;
		}

		float discriminant = CalculateDiscriminant(A, B, C);
		if (discriminant < 0)
		{
			cout << "Discriminant is less than 0" << endl;
			return;
		}

		Vector2f roots = CalculateRoots(discriminant, A, B);

		cout << roots.x << " " << roots.y << endl;
	}
	else
	{
		cout << "Incorrect input" << endl;
		return;
	}
}

int main(int argc, char* argv[])
{
	if (argc == 4)
	{
		RunApp(argv[1], argv[2], argv[3]);
	}
	else
	{
			cout << "Need 3 argument" << endl;
	}
	system("pause");
	return 0;
}