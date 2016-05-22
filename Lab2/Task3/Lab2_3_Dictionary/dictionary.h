#pragma warning(disable:4996)
#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using std::string;
using std::cout;
using std::endl;
using std::cin;

std::multimap<string, string> LoadDictionaryFromFile(const string& finName);
bool IsWordInDictionary(const std::multimap<string, string> newDictionary, const string& word);
void OutputTranslationsForKey(const std::multimap<string, string> newDictionary, const string& key);
string GetTranslation(const std::multimap<string, string>& newDictionary, const string& key);
void AddWordToDictionary(std::multimap<string, string>& dictionary, const string& word, const string& translation);
void AskUserToSaveNewWord(const string& word, std::multimap<string, string>& newDictionary);
void SaveChangedDictionary(const string& fileName, std::multimap<string, string>& newDictionary);
void AskUserToSaveNewDictionary(const string& fileName, std::multimap<string, string>& newDictionary);
void WorkWithUser(std::multimap<string, string>& newDictionary);