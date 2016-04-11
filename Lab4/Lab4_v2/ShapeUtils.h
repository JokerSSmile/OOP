#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>

std::vector<std::vector<std::string>> GetInputData();

void CreateRectangle(const std::vector<std::string>& command, std::vector<std::unique_ptr<IShape>>& figures);

void CreateCircle(const std::vector<std::string>& command, std::vector<std::unique_ptr<IShape>>& figures);

void CreateLine(const std::vector<std::string>& command, std::vector<std::unique_ptr<IShape>>& figures);

void CreateTriangle(const std::vector<std::string>& command, std::vector<std::unique_ptr<IShape>>& figures);

void CreatePoint(const std::vector<std::string>& command, std::vector<std::unique_ptr<IShape>>& figures);

void ParseCommands(const std::vector<std::vector<std::string>>& commands, std::vector<std::unique_ptr<IShape>>& figures);
