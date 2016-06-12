#pragma once
#include "CUrlParsingError.h"

const static std::string PERMITTED_DOMAIN_NAME_SYMBOLS = "abcdefghijklmnopqrstuvwxyz1234567890-";
const static std::string PERMITTED_DOMAIN_TYPE_SYMBOLS = "abcdefghijklmnopqrstuvwxyz";
const static std::string PERMITTED_DOCUMENT_SYMBOLS = "abcdefghijklmnopqrstuvwxyz1234567890/-&$?._=";

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
	std::string VerifyAndApplyDomain(const std::string& domain);
	std::string ParseUrlForProtocol(const std::string& url);
	Protocol VerifyAndApplyProtocol(const std::string& protocol);
	unsigned short ParseUrlForPort(const std::string& url);
	unsigned short ApplyPort(unsigned short port);
	std::string ParseUrlForDocument(const std::string& url);
	std::string VerifyAndApplyDocument(const std::string& document);

	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};
