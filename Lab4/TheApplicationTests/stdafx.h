// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <vector>
#include <string>
#include <iostream>
//#include <cmath>

#include <SFML/Graphics.hpp>
//#include <boost/lexical_cast.hpp>
//#include <boost/algorithm/string/replace.hpp>

#include "../Lab4_v2/CCircle.h"
#include "../Lab4_v2/CLineSegment.h"
#include "../Lab4_v2/CPoint.h"
#include "../Lab4_v2/CRectangle.h"
#include "../Lab4_v2/CTriangle.h"
#include "../Lab4_v2/IShape.h"
#include "../Lab4_v2/ISolidShape.h"
#include "../Lab4_v2/ShapeUtils.h"
#include "../Lab4_v2/HexToRgb.h"

#define BOOST_TEST_MODULE TheApplicationTestsModule
#define BOOST_TEST_INCLUDED
#pragma warning (disable: 4702)
#include <boost/test/unit_test.hpp>


// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
