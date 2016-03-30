#include "stdafx.h"
#include "HtmlDecode.h"

std::string ReadInput()
{
	std::cout << "Input string, ENTER to stop" << std::endl;
	std::string inputString;
	std::getline(std::cin, inputString);

	return inputString;
}

std::string Decode(const std::string& givenString)
{
	std::string resultString = givenString;

	boost::replace_all(resultString, "&quot;", "\"");
	boost::replace_all(resultString, "&apos;", "`");
	boost::replace_all(resultString, "&lt;", "<");
	boost::replace_all(resultString, "&gt;", ">");
	boost::replace_all(resultString, "&amp;", "&");

	return resultString;
}

void OutputResult(const std::string& resultString)
{
	std::cout << resultString << std::endl;
}
