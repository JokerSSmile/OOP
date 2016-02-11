#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const unsigned MAX_FILE_SIZE = 2147483647;

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

void FillOutputMatrix(ifstream& fin, fstream& fout, char find[], char replace[])
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

bool IsFileSizeCorrect(char inputFile[])
{
	ifstream file(inputFile, ios::in);
	file.seekg(0, std::ios::end);

	if (file.tellg() > MAX_FILE_SIZE)
	{
		std::cout << "File size must be less than 2GB";
		return false;
	}
	return true;
}

void RunApp(char inputFile[], char outputFile[], char find[], char replace[])
{
	ifstream fin(inputFile, ios_base::in);
	fstream fout(outputFile, ios_base::out);
	if (fin.is_open() == false || fout.is_open() == false)
	{
		cout << "Error while opening files" << endl;
		return;
	}
	if (IsFileSizeCorrect(inputFile) == false)
	{
		cout << "Too big file size" << endl;
		return;
	}
	FillOutputMatrix(fin, fout, find, replace);
	fin.close();
	fout.close();
	cout << "Done" << endl;
}

int main(int argc, char * argv[])
{
	cout << "This program replace given find string to given replace string in input file and saves the result to output file\n" << endl;
	srand(time(0));
 	if (argc == 5)
	{
		RunApp(argv[1], argv[2], argv[3], argv[4]);
	}
	else
	{
		cout << "Input must be:\nLab1.exe <input.txt> <output.txt> <find> <replace>" << endl;
	}
	cout << "runtime = " << clock() / 1000.0 << endl;
	system("pause");
	return 0;
}
