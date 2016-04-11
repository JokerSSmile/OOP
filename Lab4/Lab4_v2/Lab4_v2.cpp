#include "stdafx.h"
#include "ShapeUtils.h"

auto sortRuleLambda = [](const IShape& s1, const IShape& s2) -> bool
{
	return s1.GetPerimeter() < s2.GetPerimeter();
};

int main()
{
	std::vector<std::vector<std::string>> inputData = GetInputData();
	std::vector<std::unique_ptr<IShape>> figures;

	ParseCommands(inputData, figures);
	cout << "------" << endl;

	std::sort(figures.begin(), figures.end(), [](std::unique_ptr<IShape>& shape1, std::unique_ptr<IShape>& shape2) {return shape1->GetPerimeter() < shape2->GetPerimeter();});

	for (auto& f : figures)
	{
		cout << f->GetPerimeter() << endl;
	}

	cout << endl;

	std::sort(figures.begin(), figures.end(), [](std::unique_ptr<IShape>& shape1, std::unique_ptr<IShape>& shape2) {return shape1->GetArea() < shape2->GetArea();});

	for (auto& f : figures)
	{
		cout << f->GetArea() << endl;
	}

    return 0;
}
