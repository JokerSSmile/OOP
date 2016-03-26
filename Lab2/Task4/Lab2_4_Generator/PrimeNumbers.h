#pragma once
#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::size_t;

std::set<int> GeneratePrimeNumbersSet(const int& upperBound);

void OutputNumbers(const std::set<int>& givenSet);
