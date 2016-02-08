//cd C:\Users\oleg\Documents\Visual Studio 2015\Projects\OOP\Lab1\Debug
//Lab1.exe input.txt output.txt find replace

#include "stdafx.h"

using namespace std;

char ToLowercase(char in) {
	if (in <= 'Z' && in >= 'A')
	{
		return in - ('Z' - 'z');
	}
	return in;
}

void Replace(const char str[], char find[], char replace[], fstream& fout)
{
	unsigned k = 0;
	unsigned long i = 0;
	unsigned findLength = strlen(find);
	unsigned strLength = strlen(str);

	while (i < strLength)
	{
		if (ToLowercase(str[i]) == ToLowercase(find[k]))
		{
			k++;
			i++;
			if (k == findLength)
			{
				fout << replace;
				k = 0;
			}
		}
		else
		{
			if (k == 0)
			{
				fout << str[i];
				k = 0;
				i++;
			}
			else
			{
				i -= k - 1;
				fout << str[i - 1];
				k = 0;
			}
		}
	}
}

void WorkWithInput(ifstream& fin, fstream& fout, char find[], char replace[])
{
	if (fin.is_open() == false)
	{
		cout << "Error while opening file" << endl;
	}
	else
	{
		cout << "Working..." << endl;

		string line;
		int lineCount = 0;

		while (!fin.eof())
		{
			if (lineCount != 0)
			{
				fout << "\n";
			}
			getline(fin, line);
			Replace(line.c_str(), find, replace, fout);
			lineCount++;
		}
	}
}

void RunApp(char inputFile[], char outputFile[], char find[], char replace[])
{
	ifstream fin(inputFile, ios_base::in);
	fstream fout(outputFile, ios_base::out);
	WorkWithInput(fin, fout, find, replace);
	fin.close();
	fout.close();
	cout << "Done" << endl;
}

int main(int argc, char * argv[])
{
	srand(time(0));
 	if (argc == 5)
	{
		RunApp(argv[1], argv[2], argv[3], argv[4]);
	}
	else
	{
		cout << "Need 4 arguments" << endl;
	}
	cout << "runtime = " << clock() / 1000.0 << endl;
	system("pause");
	return 0;
}
