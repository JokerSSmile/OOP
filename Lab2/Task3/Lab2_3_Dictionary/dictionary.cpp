#include "stdafx.h"
#include "dictionary.h"

std::multimap<string, string> LoadDictionaryFromFile(const string& finName)
{
	std::ifstream fin(finName);
	if (!fin.is_open())
	{
		throw std::exception("Input file can not be opened");
	}
	std::multimap<string, string> dictionary;
	string fileLine;

	while (std::getline(fin, fileLine))
	{
		std::vector<string> translationPair;
		boost::split(translationPair, fileLine, boost::is_any_of(":"));
		dictionary.insert(std::pair<string, string>(translationPair[1], translationPair[0]));
	}

	return dictionary;
}

bool IsWordInDictionary(const std::multimap<string, string> newDictionary, const string& word)
{
	return (newDictionary.find(word) != newDictionary.end());
}

void OutputTranslationsForKey(const std::multimap<string, string> newDictionary, const string& key)
{
	auto range = newDictionary.equal_range(key);
	for (auto it = range.first; it != range.second; it++)
	{
		cout << it->second << " ";
	}
	cout << endl;
}

string GetTranslation(const std::multimap<string, string>& newDictionary, const string& key)
{
	string translation;
	auto range = newDictionary.equal_range(key);
	for (auto it = range.first; it != range.second; it++)
	{
		translation = translation + it->second + " ";
	}
	return translation;
}

void AddWordToDictionary(std::multimap<string, string>& dictionary, const string& word, const string& translation)
{
	dictionary.insert(std::pair<string, string>(word, translation));
}

void AskUserToSaveNewWord(const string& word, std::multimap<string, string>& newDictionary)
{
	string translationString;
	cout << "Unknown word \"" << word << "\". Input translation or empty string to abort" << endl;
	std::getline(cin, translationString);
	if (translationString != "")
	{
		AddWordToDictionary(newDictionary, word, translationString);
		cout << "Word \"" << word << "\" was saved as \"" << translationString << "\"" << endl;
	}
	else
	{
		cout << "Word \"" << word << "\" was ignored" << endl;
	}
}

void SaveChangedDictionary(const string& fileName, std::multimap<string, string>& newDictionary)
{
	std::ofstream fout(fileName);
	if (!fout.is_open())
	{
		throw std::exception("Output file can not be opened");
	}
	for (auto& pair : newDictionary)
	{
		fout << pair.second << ":" << pair.first << endl;
	}
}

void AskUserToSaveNewDictionary(const string& fileName, std::multimap<string, string>& newDictionary)
{
	cout << "Found changes in dictionary!\nSave updated dictionary? y/n" << endl;
	string confirmationString;
	std::getline(cin, confirmationString);
	while (boost::algorithm::to_lower_copy(confirmationString) != "n" && boost::algorithm::to_lower_copy(confirmationString) != "y")
	{
		std::getline(cin, confirmationString);
	}
	if (boost::algorithm::to_lower_copy(confirmationString) == "y")
	{
		SaveChangedDictionary(fileName, newDictionary);
		cout << "Changes are saved" << endl;
	}
	else
	{
		cout << "Exit without saving changes" << endl;
	}
}

void WorkWithUser(std::multimap<string, string>& newDictionary)
{
	string inputString;
	cout << ">";
	std::getline(cin, inputString);
	while (inputString != "...")
	{
		if (newDictionary.find(inputString) != newDictionary.end())
		{
			OutputTranslationsForKey(newDictionary, inputString);
		}
		else if (inputString != "")
		{

			AskUserToSaveNewWord(inputString, newDictionary);
		}
		cout << ">";
		std::getline(cin, inputString);
	}
}