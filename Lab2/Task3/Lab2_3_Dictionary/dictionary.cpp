#include "dictionary.h"

multimap<string, string> LoadDictionaryFromFile(const string& filename)
{
	multimap<string, string> dictionaryMap;
	string fileLine;
	std::vector<string> strings;

	std::ifstream fin(filename);
	
	while (std::getline(fin, fileLine))
	{
		cout << "1" << endl;
		//boost::split(strings, fileLine, boost::is_any_of(":"));
	}

	return dictionaryMap;
}