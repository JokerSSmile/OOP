#include "dictionary.h"

int main(int argc, char* argv[])
{
	multimap<string, string> dictionary;
	dictionary = LoadDictionaryFromFile(string("input.txt"));
    return 0;
}

