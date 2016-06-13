#include "stdafx.h"
#include "CHttpUrl.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <boost/lexical_cast.hpp>

using std::cout;
using std::endl;

CHttpUrl::CHttpUrl(const std::string & url)
{
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(const std::string& domain, const std::string& document, Protocol protocol, unsigned short port)
	:m_protocol(protocol),
	m_port(ApplyPort(port)),
	m_domain(VerifyAndApplyDomain(domain)),
	m_document(VerifyAndApplyDocument(document))
{

}

std::string CHttpUrl::GetURL() const
{
	std::string url;
	GetProtocol() == HTTP ? url += "http://" : url += "https://";
	url += m_domain;
	if (GetPort() != 80 && GetProtocol() == HTTP ||
		GetPort() != 443 && GetProtocol() == HTTPS)
	{
		url += ":" + std::to_string(GetPort());
	}
	url += GetDocument();
	return url;
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
	m_protocol = VerifyAndApplyProtocol(protocol);
	std::string domain = ParseUrlForDomain(url);
	m_domain = VerifyAndApplyDomain(domain);
	m_port = ParseUrlForPort(url);
	std::string document = ParseUrlForDocument(url);
	m_document = VerifyAndApplyDocument(document);
	
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

std::string CHttpUrl::VerifyAndApplyDomain(const std::string & domain)
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

	return domain;
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

Protocol CHttpUrl::VerifyAndApplyProtocol(const std::string & protocol)
{
	if (protocol == "http")
	{
		return HTTP;
	}
	else if (protocol == "https")
	{
		return HTTPS;
	}

	throw CUrlParsingError("Error: invalid protocol type");
}

unsigned short CHttpUrl::ParseUrlForPort(const std::string & url)
{
	unsigned short port;
	size_t minPosOfDelimeter = 8;
	std::string containsPort = url.substr(minPosOfDelimeter, url.size());

	size_t portDelimeterPos = containsPort.find_first_of(":/");

	if (portDelimeterPos == std::string::npos || containsPort[portDelimeterPos] == '/')
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

		std::string portStr = containsPort.substr(portDelimeterPos + 1, documentStartPos - portDelimeterPos - 1);
		try
		{
			port = boost::lexical_cast<int>(portStr);
		}
		catch (const boost::bad_lexical_cast&)
		{
			throw CUrlParsingError("Error: invalid port");
		}
	}

	return port;
}

unsigned short CHttpUrl::ApplyPort(unsigned short port)
{
	m_port = port;

	return port;
}

std::string CHttpUrl::ParseUrlForDocument(const std::string & url)
{
	std::string urlWithDocument = url.substr(8, url.size());

	if (urlWithDocument.back() != '/')
	{
		urlWithDocument += "/";
	}

	size_t documentStartPos = urlWithDocument.find('/');

	return urlWithDocument.substr(documentStartPos,  urlWithDocument.size() - 8);
}

std::string CHttpUrl::VerifyAndApplyDocument(const std::string & document)
{
	std::string doc = document;

	if (doc[0] != '/')
	{
		doc.insert(doc.begin(), '/');
	}

	if (doc.find_first_not_of(PERMITTED_DOCUMENT_SYMBOLS) != std::string::npos)
	{
		throw CUrlParsingError("Error: invalid symbol in document");
	}

	return doc;
}
