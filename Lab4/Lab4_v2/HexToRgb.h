#pragma once
#include "stdafx.h"

//Convert string with HEX code to sf::Color
//returns Black if error in HEX code
sf::Color HexToRgb(const std::string& givenHexCode);
