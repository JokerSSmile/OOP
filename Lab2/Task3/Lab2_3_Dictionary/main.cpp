#include "dictionary.h"
#include <windows.h>


int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	if (argc != 2)
	{
		cout << "Input must be Lab2_3_Dictionary.exe <inputFile.txt>" << endl;
		return 1;
	}

	string fileName = argv[1];

	std::multimap<string, string> newDictionary;
	try
	{
		newDictionary = LoadDictionaryFromFile(fileName);
		int startDictionarySize = newDictionary.size();
		WorkWithUser(newDictionary);
		if (startDictionarySize != newDictionary.size())
		{
			TryToSaveNewDictionary(fileName, newDictionary);
		}
	}
	catch (const std::invalid_argument &error)
	{
		cout << error.what() << endl;
		return 1;
	}

    return 0;
}

