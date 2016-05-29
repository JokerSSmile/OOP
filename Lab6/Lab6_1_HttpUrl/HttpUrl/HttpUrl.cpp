// HttpUrl.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CHttpUrl.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		CHttpUrl url("google.ru", "doc", HTTPS, 443);
		cout << url.GetProtocol() << endl;
		cout << url.GetDomain() << endl;
		cout << url.GetPort() << endl;
		cout << url.GetDocument() << endl;
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
	
	

    return 0;
}

