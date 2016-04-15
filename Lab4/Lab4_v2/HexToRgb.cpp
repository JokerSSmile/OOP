#include "stdafx.h"
#include <sstream>

sf::Color HexToRgb(const std::string& givenHexCode)
{
	std::string hexCode = givenHexCode;
	if (hexCode.size() != 7 || hexCode[0] != '#')
	{
		return sf::Color::Black;
	}
	hexCode.erase(0, 1);
	int number = std::stoi(hexCode, 0, 16);
	int r = number / 0x10000;;
	int g = (number / 0x100) % 0x100;
	int b = number % 0x100;;

	return sf::Color(r, g, b);
}