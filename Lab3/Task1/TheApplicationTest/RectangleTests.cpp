#include "stdafx.h"
#include "../Lab3_1_Rectangle/Rectangle.h"
#include "../Lab3_1_Rectangle/RectangleUtils.h"
#include <boost/test/output_test_stream.hpp>

const std::string testDir = "TestRectFiles";

BOOST_AUTO_TEST_SUITE(RectUtilsTest)

BOOST_AUTO_TEST_CASE(CheckReadFromEmptyFile)
{
	std::ifstream testFin(testDir + "/empty.txt");
	vector<vector<string>> comandsFromEmptyFile = GetLinesFromInputFile(testFin);
	BOOST_CHECK(comandsFromEmptyFile.size() == 0);
}

BOOST_AUTO_TEST_CASE(CheckReadFromFile)
{
	std::ifstream testFin(testDir + "/test1.txt");
	vector<vector<string>> comandsFromFile = GetLinesFromInputFile(testFin);
	BOOST_CHECK(comandsFromFile.size() == 3);
}

BOOST_AUTO_TEST_CASE(CheckApplyCommandsToRect)
{
	std::ifstream testFin(testDir + "/test2.txt");
	vector<vector<string>> comandsFromFile = GetLinesFromInputFile(testFin);
	vector<CRectangle> rects;
	ApplyCommandsToRectangle(rects, comandsFromFile);
	BOOST_CHECK(rects[0].GetLeft() == 10);
	BOOST_CHECK(rects[0].GetBottom() == 50);
	BOOST_CHECK(rects[0].GetArea() == 1600);
}

BOOST_AUTO_TEST_CASE(CheckIntersection)
{
	vector<CRectangle> rects;
	std::ifstream testFin1(testDir + "/test1.txt");
	vector<vector<string>> comandsFromFile1 = GetLinesFromInputFile(testFin1);
	std::ifstream testFin2(testDir + "/test2.txt");
	vector<vector<string>> comandsFromFile2 = GetLinesFromInputFile(testFin2);
	ApplyCommandsToRectangle(rects, comandsFromFile1);
	ApplyCommandsToRectangle(rects, comandsFromFile2);

	BOOST_CHECK(rects[0].Intersects(rects[1]));
	BOOST_CHECK(rects[0].GetBottom() == 30);
	BOOST_CHECK(rects[0].GetRight() == 20);
	BOOST_CHECK(rects[0].GetArea() == 100);
}

BOOST_AUTO_TEST_SUITE_END()