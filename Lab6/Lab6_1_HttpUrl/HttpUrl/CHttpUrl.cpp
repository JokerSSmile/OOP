#include "stdafx.h"
#include "CHttpUrl.h"
#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;

CHttpUrl::CHttpUrl(const std::string & url)
{
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port)
{
	m_protocol = protocol == HTTP ? HTTP : HTTPS;
	VerifyPort(port);
	VerifyDomain(domain);
	VerifyDocument(document);
}

std::string CHttpUrl::GetURL() const
{
	return GetDomain() + GetDocument();
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return Protocol(m_protocol);
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

void CHttpUrl::ParseUrl(const std::string & url)
{
	std::string protocol = ParseUrlForProtocol(url);
	VerifyProtocol(protocol);
	std::string domain = ParseUrlForDomain(url);
	VerifyDomain(domain);
	unsigned short port = ParseUrlForPort(url);
	VerifyPort(port);
	std::string document = ParseUrlForDocument(url);
	VerifyDocument(document);
	
}

std::string CHttpUrl::ParseUrlForDomain(const std::string & url)
{
	size_t domainStartPos = url.find("://") + 3;
	std::string domain;

	for (size_t urlPos = domainStartPos; urlPos < url.size(); urlPos++)
	{
		
		if (url[urlPos] == ':' || url[urlPos] == '/')
		{
			break;
		}
		else
		{
			domain += url[urlPos];
		}
	}

	return domain;
}

void CHttpUrl::VerifyDomain(const std::string & domain)
{
	if (domain.size() == 0)
	{
		throw CUrlParsingError("Error: missing domain in url");
	}
	
	size_t delimeterPos = domain.find('.');
	if (delimeterPos == std::string::npos)
	{
		throw CUrlParsingError("Error: missing domain type declaration");
	}
	
	std::string domainName = domain.substr(0, delimeterPos);
	std::string domainType = domain.substr(delimeterPos + 1, domain.size());
	
	if (domainName.find_first_not_of(PERMITTED_DOMAIN_NAME_SYMBOLS) != std::string::npos || domainName.size() > 63 || domainName.size() == 0)
	{
		throw CUrlParsingError("Error: invalid symbol in domain name");
	}

	if (domainType.find_first_not_of(PERMITTED_DOMAIN_TYPE_SYMBOLS) != std::string::npos || domainType.size() < 2)
	{
		throw CUrlParsingError("Error: invalid symbol in domain type");
	}

	m_domain = domain;
}

std::string CHttpUrl::ParseUrlForProtocol(const std::string & url)
{
	size_t delimeterPos = url.find("://");

	if (delimeterPos == std::string::npos)
	{
		throw CUrlParsingError("Error: missing protocol in URL");
	}

	return url.substr(0, delimeterPos);
}

void CHttpUrl::VerifyProtocol(const std::string & protocol)
{
	if (protocol == "http")
	{
		m_protocol = HTTP;
		return;
	}
	else if (protocol == "https")
	{
		m_protocol = HTTPS;
		return;
	}

	throw CUrlParsingError("Error: invalid protocol type");
}

unsigned short CHttpUrl::ParseUrlForPort(const std::string & url)
{
	unsigned short port;
	size_t minPosOfDelimeter = 8;
	std::string containsPort = url.substr(minPosOfDelimeter, url.size());

	size_t portDelimeterPos = containsPort.find(':');

	if (portDelimeterPos == std::string::npos)
	{
		switch (m_protocol)
		{
		case HTTP:
			port = 80;
			break;
		case HTTPS:
			port = 443;
			break;
		}
	}
	else
	{
		containsPort += '/';
		size_t documentStartPos = containsPort.find('/');

		std::string portStr = containsPort.substr(portDelimeterPos + 1, documentStartPos - portDelimeterPos);
		try
		{
			port = std::stoi(portStr);
		}
		catch (const std::invalid_argument&)
		{
			throw CUrlParsingError("Error: invalid port");
		}
	}

	return port;
}

void CHttpUrl::VerifyPort(const unsigned short & port)
{
	m_port = port;
}

std::string CHttpUrl::ParseUrlForDocument(const std::string & url)
{
	std::string urlWithDocument = url.substr(8, url.size());
	size_t documentStartPos = urlWithDocument.find('/');

	return urlWithDocument.substr(documentStartPos,  urlWithDocument.size() - 8);
}

void CHttpUrl::VerifyDocument(const std::string & document)
{
	std::string doc = document;

	if (doc[0] != '/')
	{
		doc.insert(doc.begin(), '/');
	}

	if (doc.find_first_not_of(' ') == std::string::npos)
	{
		throw CUrlParsingError("Error: invalid symbol in document");
	}
	m_document = doc;
}
