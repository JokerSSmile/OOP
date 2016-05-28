#pragma once
#include "CUrlParsingError.h"
#include <string>

const static std::string PERMITTED_DOMAIN_NAME_SYMBOLS = "abcdefghijklmnopqrstuvwxyz1234567890-";
const static std::string PERMITTED_DOMAIN_TYPE_SYMBOLS = "abcdefghijklmnopqrstuvwxyz";

enum Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:

	CHttpUrl(const std::string& url);

	CHttpUrl(
		const std::string& domain,
		const std::string& document,
		Protocol = HTTP,
		unsigned short port = 80);

	std::string GetURL() const;
	std::string GetDomain() const;	
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

private:

	void ParseUrl(const std::string& url);
	std::string ParseUrlForDomain(const std::string& url);
	void VerifyDomain(const std::string& domain);
	std::string ParseUrlForProtocol(const std::string& url);
	void VerifyProtocol(const std::string& protocol);
	unsigned short ParseUrlForPort(const std::string& url);
	void VerifyPort(const unsigned short& port);
	std::string ParseUrlForDocument(const std::string& url);
	void VerifyDocument(const std::string& document);

	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};
