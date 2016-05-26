#include "stdafx.h"
#include "CHttpUrl.h"

CHttpUrl::CHttpUrl(const std::string & url)
{
}

CHttpUrl::CHttpUrl(std::string const & domain, std::string const & document, Protocol, unsigned short port)
{
}

std::string CHttpUrl::GetURL() const
{
	return std::string();
}

std::string CHttpUrl::GetDomain() const
{
	return std::string();
}

std::string CHttpUrl::GetDocument() const
{
	return std::string();
}

Protocol CHttpUrl::GetProtocol() const
{
	return Protocol();
}

unsigned short CHttpUrl::GetPort() const
{
	return 0;
}
