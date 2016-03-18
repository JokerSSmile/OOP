#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using std::string;
using std::map;
using std::multimap;
using std::cout;
using std::endl;

multimap<string, string> LoadDictionaryFromFile(string& fileName);