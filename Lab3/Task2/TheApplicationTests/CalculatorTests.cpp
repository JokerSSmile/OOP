#include "stdafx.h"
#include "../Lab3_2_Calculator/Calculator.h"
#include "../Lab3_2_Calculator/CalculatorUtils.h"
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_SUITE(calcTests)

BOOST_AUTO_TEST_CASE(CreateCorrectVariable)
{
	CCalculator calculator;
	BOOST_CHECK(!calculator.IsVarableAlreadyExist("someVar"));
	calculator.CreateVariable("someVar");
	BOOST_CHECK(calculator.IsVarableAlreadyExist("someVar"));
}

BOOST_AUTO_TEST_CASE(CreateNotCorrectVariable)
{
	CCalculator calculator;
	try
	{
		calculator.CreateVariable("1someVar");
	}
	catch (std::invalid_argument& err)
	{
		BOOST_CHECK(err.what() != "");
	}
	BOOST_CHECK(calculator.GetVariablesSize() == 0);
}

BOOST_AUTO_TEST_CASE(CreateFnsAndVars)
{
	CCalculator calculator;
	calculator.CreateVariable("e", 3);
	calculator.CreateVariable("d", 3.6);
	calculator.AddFunction({ "fn", "A", "=", "e" });
	calculator.AddFunction({ "fn", "D", "=", "A", "*", "d" });
	BOOST_CHECK(calculator.IsVarableAlreadyExist("A"));
	BOOST_CHECK(calculator.IsVarableAlreadyExist("e"));
	BOOST_CHECK(calculator.IsVarableAlreadyExist("D"));
	BOOST_CHECK(calculator.IsVarableAlreadyExist("d"));
	BOOST_CHECK(calculator.CalculateFunctionsBody("D") == 10.8);
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(GlobalTest)

CCalculator calculator;
std::ifstream fin("testInput.txt");
vector<vector<string>> inputVec = GetLinesFromInputFile(fin);

BOOST_AUTO_TEST_CASE(ReadFromFile)
{
	BOOST_CHECK(inputVec.size() == 17);
}

BOOST_AUTO_TEST_CASE(GlobalTest)
{
	//using to hide output from the function
	std::streambuf* orig_buf = cout.rdbuf();
	cout.rdbuf(0);
	OperateWithCommands(inputVec, calculator);
	cout.rdbuf(orig_buf);

	BOOST_CHECK(calculator.GetFunctiosSize() == 4);
	BOOST_CHECK(calculator.GetVariablesSize() == 5);
	BOOST_CHECK_EQUAL(int(calculator.CalculateFunctionsBody("E")), -53);
	boost::test_tools::output_test_stream output;
	output << calculator.CalculateVariableValue("c");
	BOOST_CHECK(output.is_equal("-1"));
}

BOOST_AUTO_TEST_SUITE_END()