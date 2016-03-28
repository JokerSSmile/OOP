#pragma once
#include "Rectangle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<vector<string>> GetLinesFromInputFile(std::ifstream& fin);

void ApplyCommandsToRectangle(vector<CRectangle>& rectangles, const vector<vector<string>>& commands);

void OutputInfo(const vector<CRectangle>& rectangles);

void OutputIntersectionInfo(vector<CRectangle>& rectangles);