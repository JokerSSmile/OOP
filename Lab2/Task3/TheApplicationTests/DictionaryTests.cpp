#include "stdafx.h"
#include "../Lab2_3_Dictionary/dictionary.h"
#include <windows.h>

struct EmptyDictionary
{
	std::multimap<string, string> dict = {};
};

BOOST_FIXTURE_TEST_SUITE(empty_dictionary_test, EmptyDictionary)

BOOST_AUTO_TEST_CASE(is_empty_at_start)
{
	BOOST_CHECK(dict.size() == 0);
}

BOOST_AUTO_TEST_CASE(can_add_word_to_empty_dictionary)
{
	BOOST_CHECK(!IsWordInDictionary(dict, "dog"));
	AddWordToDictionary(dict, "dog", "pes");
	BOOST_CHECK(IsWordInDictionary(dict, "dog"));
}

BOOST_AUTO_TEST_SUITE_END()

struct Dictionary
{
	std::multimap<string, string> dict = { {"dog", "pes"} };
};

BOOST_FIXTURE_TEST_SUITE(dictionary_test, Dictionary)

BOOST_AUTO_TEST_CASE(can_get_translation_to_existed_word)
{
	BOOST_CHECK_EQUAL(GetTranslation(dict, "dog"), "pes ");
}

BOOST_AUTO_TEST_CASE(returns_as_many_translations_as_already_exists)
{
	AddWordToDictionary(dict, "dog", "pesik");
	BOOST_CHECK_EQUAL(GetTranslation(dict, "dog"), "pes pesik ");
}

BOOST_AUTO_TEST_SUITE_END()