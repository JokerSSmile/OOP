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

void Replace(string& str, string& find, string& replace, fstream& fout)
{
	unsigned k = 0;
	unsigned long i = 0;
	unsigned findLength = find.size();

	while (i < str.size())
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

void WorkWithInput(ifstream& fin, fstream& fout, string& find, string& replace)
{
	if (!fin.is_open())
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
			Replace(line, find, replace, fout);
			lineCount++;
		}
	}
}

void RunApp(string& inputFile, string& outputFile, string& find, string& replace)
{
	if (find.size() == 0)
	{
		ifstream fin(inputFile, ios_base::in);
		fstream fout(outputFile, ios_base::out);
		WorkWithInput(fin, fout, find, replace);
		fin.close();
		fout.close();
		cout << "Done" << endl;
	}
	else
	{
		cout << "Size of string to find must be more then 0" << endl;
	}
}

int main(int argc, char * argv[])
{
 	if (argc == 5)
	{
		RunApp(string(argv[1]), string(argv[2]), string(argv[3]), string(argv[4]));
	}
	else
	{
		cout << "Need 4 arguments" << endl;
	}
	system("pause");
	return 0;
}
