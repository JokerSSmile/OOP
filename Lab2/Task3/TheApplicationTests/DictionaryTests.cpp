#include "stdafx.h"
#include "../Lab2_3_Dictionary/dictionary.h"
#include <windows.h>

BOOST_AUTO_TEST_SUITE(DictionaryTests)

std::multimap<string, string> dict = LoadDictionaryFromFile("testDictionaryEmpty.txt");

BOOST_AUTO_TEST_CASE(emptyInputFile)
{
	BOOST_CHECK(dict.empty());
}

BOOST_AUTO_TEST_CASE(addWord)
{
	BOOST_CHECK(!IsWordInDictionary(dict, "test"));
	AddWordToDictionary(dict, "test", "тест");
	BOOST_CHECK(IsWordInDictionary(dict, "test"));
}

BOOST_AUTO_TEST_CASE(outputWord)
{
	setlocale(LC_ALL, "RUS");
	string translation = GetTranslation(dict, "test");
	cout << translation << " " << "тест";
	//BOOST_CHECK(_T(translation) == _T("тест"));
}

BOOST_AUTO_TEST_SUITE_END()