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

void Replace(const char str[], char find[], char replace[], fstream& fout)
{
	unsigned k = 0;
	unsigned long i = 0;
	unsigned findLength = strlen(find);
	unsigned strLength = strlen(str);

	if (findLength > strLength)
	{
		return;
	}

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

void FillOutputFile(ifstream& fin, fstream& fout, char find[], char replace[])
{
	string line;
	int lineCount = 0;

	while (getline(fin, line))
	{
		if (lineCount != 0)
		{
			fout << "\n";
		}
		Replace(line.c_str(), find, replace, fout);
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
		fstream fout(argv[2], ios_base::out);
		if (fin.is_open() == false || fout.is_open() == false)
		{
			cout << "Error while opening files" << endl;
			return 1;
		}
		FillOutputFile(fin, fout, argv[3], argv[4]);
		fin.close();
		fout.close();
		cout << "Done" << endl;
	}
	else
	{
		cout << "Input must be:\nLab1.exe <input.txt> <output.txt> <find> <replace>" << endl;
		return 1;
	}
	return 0;
}
