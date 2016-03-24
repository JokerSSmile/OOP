#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

char ToLowercase(char in) {
	if (in <= 'Z' && in >= 'A')
	{
		return in - ('Z' - 'z');
	}
	return in;
}

void Replace(const string& str, const string& find, const string& replace, ofstream& fout)
{
	size_t positionInFindString = 0;
	size_t positionInGivenString = 0;
	size_t findLength = find.size();
	size_t strLength = str.size();

	if (findLength > strLength)
	{
		return;
	}

	while (positionInGivenString < strLength)
	{
		if (ToLowercase(str[positionInGivenString]) == ToLowercase(find[positionInFindString]))
		{
			positionInFindString++;
			positionInGivenString++;
			if (positionInFindString == findLength)
			{
				fout << replace;
				positionInFindString = 0;
			}
		}
		else
		{
			if (positionInFindString == 0)
			{
				fout << str[positionInGivenString];
				positionInFindString = 0;
				positionInGivenString++;
			}
			else
			{
				positionInGivenString -= positionInFindString - 1;
				fout << str[positionInGivenString - 1];
				positionInFindString = 0;
			}
		}
	}
}

void ReplaceStringsInFile(ifstream& fin, ofstream& fout, const string& find, const string& replace)
{
	string line;
	int lineCount = 0;

	while (getline(fin, line))
	{
		if (lineCount != 0)
		{
			fout << "\n";
		}
		Replace(line, find, replace, fout);
		if (lineCount < 2)
		{
			lineCount++;
		}
	}
}

int main(int argc, char * argv[])
{
 	if (argc == 5)
	{
		ifstream fin(argv[1], ios_base::in);
		ofstream fout(argv[2], ios_base::out);
		if (!fin.is_open() || !fout.is_open())
		{
			cout << "Error while opening files" << endl;
			return 1;
		}
		ReplaceStringsInFile(fin, fout, argv[3], argv[4]);
		cout << "Done" << endl;
	}
	else
	{
		cout << "Input must be:\nLab1.exe <input.txt> <output.txt> <find> <replace>" << endl;
		return 1;
	}
	return 0;
}
