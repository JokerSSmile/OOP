#pragma once
#include <memory>
#include "IShape.h"
#include "CShape.h"

std::vector<std::vector<std::string>> GetInputData();

void CreateRectangle(const std::vector<std::string>& command, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures);

void CreateCircle(const std::vector<std::string>& command, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures);

void CreateLine(const std::vector<std::string>& command, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures);

void CreateTriangle(const std::vector<std::string>& command, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures);

void CreatePoint(const std::vector<std::string>& command, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures);

void ParseCommands(const std::vector<std::vector<std::string>>& commands, std::vector<std::shared_ptr<CShape>>& figures, std::vector<std::shared_ptr<sf::Shape>>& drawableFigures);

void OutputInfoAboutShapes(const std::vector<std::shared_ptr<CShape>>& figures);