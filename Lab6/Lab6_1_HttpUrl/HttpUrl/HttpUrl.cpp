// HttpUrl.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "CHttpUrl.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		CHttpUrl("kek.", "/adsfasdf", Protocol(HTTPS), 25);
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
	
	

    return 0;
}

