#include "stdafx.h"
#include "ShapeUtils.h"

void DrawShapes(const std::vector<std::shared_ptr<sf::Shape>>& drawableShapes)
{
	if (drawableShapes.size() == 0)
	{
		return;
	}
	sf::RenderWindow window(sf::VideoMode(1500, 900), "Shapes");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		for (const auto& shape : drawableShapes)
		{
			window.draw(*shape);
		}
		window.display();
	}
}

int main()
{
	std::vector<std::vector<std::string>> inputData = GetInputData();
	std::vector<std::shared_ptr<CShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableShapes;

	ParseCommands(inputData, figures, drawableShapes);
	std::cout << "______" << std::endl;

	OutputInfoAboutShapes(figures);

	DrawShapes(drawableShapes);

    return 0;
}
