#include "dictionary.h"
#include <windows.h>


int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	if (argc != 2)
	{
		//cout << "Input must be Lab2_3_Dictionary.exe <inputFile.txt>" << endl;
		//return 1;
	}

	cout << "Input English word and if it is already exists in dictionary you will get translation,/n" <<
		"else you can save translation by yourself./n"<< endl;
	cout << "At the end you can save changed dictionary" << endl;

	string fileName = "input.txt";//argv[1];

	std::multimap<string, string> newDictionary;
	try
	{
		newDictionary = LoadDictionaryFromFile(fileName);
		int startDictionarySize = newDictionary.size();
		WorkWithUser(newDictionary);
		if (startDictionarySize != newDictionary.size())
		{
			AskUserToSaveNewDictionary(fileName, newDictionary);
		}
	}
	catch (const std::exception &error)
	{
		cout << error.what() << endl;
		return 1;
	}

    return 0;
}

