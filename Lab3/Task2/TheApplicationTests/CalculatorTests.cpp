#include "stdafx.h"
#include "../Lab3_2_Calculator/Calculator.h"
#include "../Lab3_2_Calculator/CalculatorUtils.h"
#include <boost/test/output_test_stream.hpp>

struct Calc
{
	CCalculator calculator;
};

BOOST_FIXTURE_TEST_SUITE(create_variables_test, Calc)

	BOOST_AUTO_TEST_CASE(can_create_correct_variable)
	{
		BOOST_CHECK_NO_THROW(calculator.CreateVariable("_1someVar"));
	}

	BOOST_AUTO_TEST_CASE(error_if_first_is_digit)
	{
		BOOST_CHECK_THROW(calculator.CreateVariable("1someVar"), std::exception);
	}

	BOOST_AUTO_TEST_CASE(error_if_not_eng_symbol)
	{
		BOOST_CHECK_THROW(calculator.CreateVariable("sóêóêmeVar"), std::exception);
	}

	BOOST_AUTO_TEST_CASE(can_create_variable)
	{
		BOOST_CHECK_NO_THROW(calculator.CreateVariable({ "x" }));
	}

	struct Calc_with_var_a : Calc
	{
		Calc_with_var_a()
		{
			calculator.AddVariable({ "let", "a", "=", "4" });
		}
	};

	BOOST_FIXTURE_TEST_SUITE(create_variables_test, Calc_with_var_a)

		BOOST_AUTO_TEST_CASE(can_add_variable_with_body)
		{
			BOOST_CHECK(calculator.CalculateVariableValue("a") == 4);
		}

		BOOST_AUTO_TEST_CASE(reset_variables_value)
		{
			calculator.AddVariable({ "let", "a", "=", "5.54" });
			BOOST_CHECK(calculator.CalculateVariableValue("a") == 5.54);
		}

		BOOST_AUTO_TEST_CASE(let_variable_be_equal_to_another_variable)
		{
			calculator.AddVariable({ "let", "b", "=", "a" });
			BOOST_CHECK(calculator.CalculateVariableValue("b") == 4);
		}

	BOOST_AUTO_TEST_SUITE_END()

	struct Calc_with_fn_A : Calc_with_var_a
	{
		Calc_with_fn_A()
		{
			calculator.AddVariable({ "let", "b", "=", "3" });
			calculator.AddFunction({"fn", "A", "=", "a", "+", "b"});
		}
	};

	BOOST_FIXTURE_TEST_SUITE(create_function_test, Calc_with_fn_A)

		BOOST_AUTO_TEST_CASE(can_create_function)
		{
			BOOST_CHECK(calculator.CalculateFunctionsBody("A") == 7);
		}
		
		BOOST_AUTO_TEST_CASE(one_function_can_contain_another_function_in_body)
		{
			calculator.AddFunction({ "fn", "B", "=", "A", "+", "b" });
			BOOST_CHECK(calculator.CalculateFunctionsBody("B") == 10);
		}

		BOOST_AUTO_TEST_CASE(correct_function_value_if_one_of_variables_in_body_changed_value)
		{
			calculator.AddFunction({ "fn", "B", "=", "A", "+", "b" });
			calculator.AddFunction({ "fn", "C", "=", "B", "+", "b" });
			BOOST_CHECK(calculator.CalculateFunctionsBody("C") == 13);
			calculator.AddVariable({"let", "a", "=", "10"});
			BOOST_CHECK(calculator.CalculateFunctionsBody("C") == 19);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(exception_if_incorrect_number_of_parameters)
	{
		BOOST_CHECK_THROW(calculator.CreateVariable({"a", "3"}), std::exception);
		BOOST_CHECK_THROW(calculator.CreateVariable({ "" }), std::exception);
		BOOST_CHECK_THROW(calculator.AddVariable({ "let", "a"}), std::exception);
		BOOST_CHECK_THROW(calculator.AddVariable({ "let", "a", "=", "4", "+", "3" }), std::exception);
		BOOST_CHECK_THROW(calculator.AddFunction({ "fn", "A", "=", "2" }), std::exception);
		BOOST_CHECK_THROW(calculator.AddFunction({ "fn", "A", "=", "2", "-", "a", "+", "a" }), std::exception);
	}

	BOOST_AUTO_TEST_CASE(can_not_create_function_if_name_is_already_declared)
	{
		BOOST_CHECK_THROW(calculator.AddFunction({ "fn", "A", "=", "4", "+", "b" }), std::exception);
	}

	BOOST_AUTO_TEST_CASE(can_change_value_if_variable_name_was_declared)
	{
		BOOST_CHECK_NO_THROW(calculator.AddVariable({ "let", "a", "=", "65" }));
	}

BOOST_AUTO_TEST_SUITE_END()
