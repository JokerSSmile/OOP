#include "stdafx.h"

BOOST_AUTO_TEST_SUITE(color_tests)

BOOST_AUTO_TEST_CASE(color_hex_to_rgb_is_correct)
{
	sf::Color color1 = HexToRgb("#c0cfbc");
	BOOST_CHECK(int(color1.r) == 192);
	BOOST_CHECK(int(color1.g) == 207);
	BOOST_CHECK(int(color1.b) == 188);

	sf::Color color2 = HexToRgb("#14f7ef");
	BOOST_CHECK(int(color2.r) == 20);
	BOOST_CHECK(int(color2.g) == 247);
	BOOST_CHECK(int(color2.b) == 239);

	sf::Color color3 = HexToRgb("14f7ef");
	BOOST_CHECK(int(color3.r) == 0);
	BOOST_CHECK(int(color3.g) == 0);
	BOOST_CHECK(int(color3.b) == 0);
}

BOOST_AUTO_TEST_SUITE_END()

struct PointFixture
{
	CPoint point;
	PointFixture()
		:point(10, 20, "#ff00ff")
	{ }
	std::vector<std::shared_ptr<IShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableFigures;
};

BOOST_FIXTURE_TEST_SUITE(point_tests, PointFixture)

BOOST_AUTO_TEST_CASE(correct_getters_result)
{
	BOOST_CHECK(point.GetX() == 10);
	BOOST_CHECK(point.GetY() == 20);
	BOOST_CHECK(point.GetArea() == 0);
	BOOST_CHECK(point.GetPerimeter() == 0);
}

BOOST_AUTO_TEST_CASE(correct_adding_from_input)
{
	std::vector<std::vector<std::string>> input = { {{"point"}, {"10"}, {"20"}, {"#ff00ff"}} };

	BOOST_CHECK_NO_THROW(ParseCommands(input, figures, drawableFigures));
	BOOST_CHECK(figures.size() == 1);
}

BOOST_AUTO_TEST_CASE(can_not_create_if_incorrect_command)
{
	std::vector<std::string> input1 = { { { "point" },{ "10" },{ "20" } } };
	std::vector<std::string> input2 = { { { "point" },{ "10" },{ "20" },{ "#ff00ff" }, {"123"} } };

	BOOST_CHECK_THROW(CreatePoint(input1, figures, drawableFigures), std::exception);
	BOOST_CHECK_THROW(CreatePoint(input2, figures, drawableFigures), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()



struct CircleFixture
{
	CCircle circle;
	CircleFixture()
		:circle(10, 20, 5, "#ff00ff", "#00ff00")
	{ }
	std::vector<std::shared_ptr<IShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableFigures;
};

BOOST_FIXTURE_TEST_SUITE(circle_tests, CircleFixture)

BOOST_AUTO_TEST_CASE(correct_getters_result)
{
	BOOST_CHECK(circle.GetStrokeColor() == "#ff00ff");
	BOOST_CHECK(circle.GetFillColor() == "#00ff00");
	BOOST_CHECK_CLOSE(circle.GetArea(), 78.5, 0.1);
	BOOST_CHECK_CLOSE(circle.GetPerimeter(), 31.4, 0.1);
}

BOOST_AUTO_TEST_CASE(correct_adding_from_input)
{
	std::vector<std::vector<std::string>> input = { { { "circle" },{ "10" },{ "20" },{"5"},{ "#ff00ff" },{ "#ff00ff" } } };
	BOOST_CHECK_NO_THROW(ParseCommands(input, figures, drawableFigures));
	BOOST_CHECK(figures.size() == 1);
}

BOOST_AUTO_TEST_CASE(can_not_create_if_incorrect_command)
{
	std::vector<std::string> input1 = { { { "circle" },{ "10" },{ "20" } } };
	std::vector<std::string> input2 = { { { "circle" },{ "10" },{ "20" },{ "#ff00ff" },{ "123" } } };
	std::vector<std::string> input3 = { { { "circle" },{ "10" },{ "20" },{ "-5" },{ "#ff00ff" },{ "#ff00ff" } } };

	BOOST_CHECK_THROW(CreateCircle(input1, figures, drawableFigures), std::exception);
	BOOST_CHECK_THROW(CreateCircle(input2, figures, drawableFigures), std::exception);
	BOOST_CHECK_THROW(CreateCircle(input3, figures, drawableFigures), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()



struct LineTests
{
	CLineSegment line;
	LineTests()
		:line(10, 20, 5, 32, "#ff00ff")
	{ }
	std::vector<std::shared_ptr<IShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableFigures;
};

BOOST_FIXTURE_TEST_SUITE(line_tests, LineTests)

BOOST_AUTO_TEST_CASE(correct_getters_result)
{
	BOOST_CHECK(line.GetStrokeColor() == "#ff00ff");
	BOOST_CHECK(line.GetArea() == 0);
	BOOST_CHECK_CLOSE(line.GetPerimeter(), 13, 0.1);
}

BOOST_AUTO_TEST_CASE(correct_adding_from_input)
{
	std::vector<std::vector<std::string>> input = { { { "line" },{ "10" },{ "20" },{ "5" },{"32"},{ "#ff00ff" } } };
	BOOST_CHECK_NO_THROW(ParseCommands(input, figures, drawableFigures));
	BOOST_CHECK(figures.size() == 1);
}

BOOST_AUTO_TEST_CASE(can_not_create_if_incorrect_command)
{
	std::vector<std::string> input1 = { { { "line" },{ "20" },{ "2" } } };
	std::vector<std::string> input2 = { { { "line" },{ "45" },{ "8" },{ "#ff00ff" },{ "123" },{"34"} } };

	BOOST_CHECK_THROW(CreateLine(input1, figures, drawableFigures), std::exception);
	BOOST_CHECK_THROW(CreateLine(input2, figures, drawableFigures), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()



struct RectTests
{
	CRectangle rect;
	RectTests()
		:rect(10, 20, 40, 30, "#ff00ff", "#56cf32")
	{ }
	std::vector<std::shared_ptr<IShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableFigures;
};

BOOST_FIXTURE_TEST_SUITE(rect_tests, RectTests)

BOOST_AUTO_TEST_CASE(correct_getters_result)
{
	BOOST_CHECK(rect.GetStrokeColor() == "#ff00ff");
	BOOST_CHECK(rect.GetFillColor() == "#56cf32");
	BOOST_CHECK(rect.GetArea() == 1200);
	BOOST_CHECK(rect.GetPerimeter() == 140);
}

BOOST_AUTO_TEST_CASE(correct_adding_from_input)
{
	std::vector<std::vector<std::string>> input = { { { "rectangle" },{ "10" },{ "20" },{ "5" },{ "32" },{ "#ff00ff" },{"#cf043f"} } };
	BOOST_CHECK_NO_THROW(ParseCommands(input, figures, drawableFigures));
	BOOST_CHECK(figures.size() == 1);
}

BOOST_AUTO_TEST_CASE(can_not_create_if_incorrect_command)
{
	std::vector<std::string> input1 = { { { "rectangle" },{ "20" },{ "2" },{"r4ra"} } };
	std::vector<std::string> input2 = { { { "rectangle" },{ "45" },{ "8" },{ "-4" },{"-5"},{ "#ff00ff" },{ "#ff00ff" } } };
	std::vector<std::string> input3 = { { { "rectangle" },{ "45" },{ "8" },{ "#ff00ff" },{ "123" },{ "34" } } };

	BOOST_CHECK_THROW(CreateRectangle(input1, figures, drawableFigures), std::exception);
	BOOST_CHECK_THROW(CreateRectangle(input2, figures, drawableFigures), std::exception);
	BOOST_CHECK_THROW(CreateRectangle(input3, figures, drawableFigures), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()



struct TriangleTests
{
	CTriangle triangle;
	TriangleTests()
		:triangle(10, 20, 40, 30, 25, 35, "#ff00f0", "#56cf34")
	{ }
	std::vector<std::shared_ptr<IShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableFigures;
};

BOOST_FIXTURE_TEST_SUITE(triangle_tests, TriangleTests)

BOOST_AUTO_TEST_CASE(correct_getters_result)
{
	BOOST_CHECK(triangle.GetStrokeColor() == "#ff00f0");
	BOOST_CHECK(triangle.GetFillColor() == "#56cf34");
	BOOST_CHECK_CLOSE(triangle.GetArea(), 150, 0.1);
	BOOST_CHECK_CLOSE(triangle.GetPerimeter(), 68.6, 0.1);
}

BOOST_AUTO_TEST_CASE(correct_adding_from_input)
{
	std::vector<std::vector<std::string>> input = { { { "triangle" },{ "10" },{ "20" },{ "5" },{ "32" }, {"43"}, {"23"},{ "#ff00ff" },{ "#cf043f" } } };
	BOOST_CHECK_NO_THROW(ParseCommands(input, figures, drawableFigures));
	BOOST_CHECK(figures.size() == 1);
}

BOOST_AUTO_TEST_CASE(can_not_create_if_incorrect_command)
{
	std::vector<std::string> input1 = { { { "triangle" },{ "20" },{ "2" },{ "r4ra" } } };
	std::vector<std::string> input2 = { { { "triangle" },{ "45" },{ "8" },{ "-4" },{ "-5" },{ "#ff00ff" },{ "#ff00ff" } } };
	std::vector<std::string> input3 = { { { "triangle" },{ "45" },{ "8" },{ "#ff00ff" },{ "123" },{ "34" } } };

	BOOST_CHECK_THROW(CreateTriangle(input1, figures, drawableFigures), std::exception);
	BOOST_CHECK_THROW(CreateTriangle(input2, figures, drawableFigures), std::exception);
	BOOST_CHECK_THROW(CreateTriangle(input3, figures, drawableFigures), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()