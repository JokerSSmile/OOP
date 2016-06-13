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
		CHttpUrl url = CHttpUrl("https://yandex.ru/get:80");
		cout << url.GetProtocol() << endl;
		cout << url.GetDomain() << endl;
		cout << url.GetPort() << endl;
		cout << url.GetDocument() << endl;
		cout << url.GetURL() << endl;
	}
	catch (const std::exception& err)
	{
		cout << err.what() << endl;
	}
	
    return 0;
}

