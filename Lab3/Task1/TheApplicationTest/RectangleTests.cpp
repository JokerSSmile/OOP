#include "stdafx.h"
#include "../Lab3_1_Rectangle/Rectangle.h"
#include "../Lab3_1_Rectangle/RectangleUtils.h"

BOOST_AUTO_TEST_SUITE(rectangles_test)

BOOST_AUTO_TEST_CASE(reading_from_empty_file_makes_nothing)
{
	std::ifstream testFin("TestRectFiles/empty.txt");
	vector<vector<string>> comandsFromEmptyFile = GetLinesFromInputFile(testFin);
	BOOST_CHECK(comandsFromEmptyFile.size() == 0);
}

BOOST_AUTO_TEST_CASE(correct_read_from_file)
{
	std::ifstream testFin("TestRectFiles/test1.txt");
	vector<vector<string>> comandsFromFile = GetLinesFromInputFile(testFin);
	BOOST_CHECK(comandsFromFile.size() == 4);
}

BOOST_AUTO_TEST_CASE(correct_aply_commands_to_rectangle)
{
	std::ifstream testFin("TestRectFiles/test2.txt");
	vector<vector<string>> comandsFromFile = GetLinesFromInputFile(testFin);
	vector<CRectangle> rects;
	ApplyCommandsToRectangle(rects, comandsFromFile);
	BOOST_CHECK(rects[0].GetLeft() == 10);
	BOOST_CHECK(rects[0].GetBottom() == 50);
	BOOST_CHECK(rects[0].GetArea() == 1600);
}

BOOST_AUTO_TEST_CASE(correct_intersection_rectangle)
{
	vector<CRectangle> rects;
	std::ifstream testFin1("TestRectFiles/test1.txt");
	vector<vector<string>> comandsFromFile1 = GetLinesFromInputFile(testFin1);
	std::ifstream testFin2("TestRectFiles/test2.txt");
	vector<vector<string>> comandsFromFile2 = GetLinesFromInputFile(testFin2);
	ApplyCommandsToRectangle(rects, comandsFromFile1);
	ApplyCommandsToRectangle(rects, comandsFromFile2);

	BOOST_CHECK(rects[0].Intersects(rects[1]));
	BOOST_CHECK(rects[0].GetBottom() == 30);
	BOOST_CHECK(rects[0].GetRight() == 20);
	BOOST_CHECK(rects[0].GetArea() == 100);
}

BOOST_AUTO_TEST_CASE(correct_work_if_rectangle_not_defined_in_input_file)
{
	vector<CRectangle> rects;
	std::ifstream testFin("TestRectFiles/noRectangleDefined.txt");
	vector<vector<string>> comands = GetLinesFromInputFile(testFin);
	ApplyCommandsToRectangle(rects, comands);
	BOOST_CHECK(rects[0].GetTop() == 0);
	BOOST_CHECK(rects[0].GetLeft() == 0);
	BOOST_CHECK(rects[0].GetWidth() == 0);
	BOOST_CHECK(rects[0].GetHeight() == 0);
}

BOOST_AUTO_TEST_CASE(throw_error_if_2_rects_defined_in_1_file)
{
	vector<CRectangle> rects;
	std::ifstream testFin("TestRectFiles/declare2rectsIn1file.txt");
	vector<vector<string>> comands = GetLinesFromInputFile(testFin);
	BOOST_CHECK_THROW(ApplyCommandsToRectangle(rects, comands), std::exception);
}

BOOST_AUTO_TEST_CASE(throw_error_if_incorrect_parameters)
{
	vector<CRectangle> rects;
	std::ifstream testFin("TestRectFiles/incorrectParameters.txt");
	vector<vector<string>> comands = GetLinesFromInputFile(testFin);
	BOOST_CHECK_THROW(ApplyCommandsToRectangle(rects, comands), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
