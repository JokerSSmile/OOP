// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#define BOOST_TEST_MODULE MyTestModule
#define BOOST_TEST_INCLUDED
#pragma warning (disable: 4702)
#pragma warning(disable:4996)
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
