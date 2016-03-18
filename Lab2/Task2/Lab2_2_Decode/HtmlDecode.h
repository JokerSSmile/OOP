#pragma once

#include <iostream>
#include <string>
#include <boost\algorithm\string\replace.hpp>

std::string ReadInput();

std::string Decode(const std::string& givenString);

void OutputResult(const std::string& resultString);
