#include "stdafx.h"
#include "../Lab2_2_Decode/HtmlDecode.h"

BOOST_AUTO_TEST_SUITE(DecodeHtml)

BOOST_AUTO_TEST_CASE(TestCase1)
{
	BOOST_CHECK(Decode("Cat &lt;says&gt; &quot;Meow&quot;.M&amp;M&apos;s") == "Cat <says> \"Meow\".M&M’s");
}

BOOST_AUTO_TEST_SUITE_END()