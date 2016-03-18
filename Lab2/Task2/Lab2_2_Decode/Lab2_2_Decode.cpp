#include "HtmlDecode.h"

int main()
{
	std::string givenString;
	givenString = ReadInput();
	std::string resultString = Decode(givenString);
	OutputResult(resultString);

    return 0;
}
