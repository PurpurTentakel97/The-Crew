//
// Purpur Tentakel
// 12.07.2022
//

#pragma once

#include "Command.h"

#include <string>

[[nodiscard]] InputOrCommandType TryGetStringInputOrExecuteCommand(std::string& input);
[[nodiscard]] InputOrCommandType TryGetBoolInputOrExecuteCommand(bool& input, std::string message);
[[nodiscard]] InputOrCommandType TryGetIntInputOrExecuteCommand(int& input);
[[nodiscard]] int GetRandomInt(int max);

void Print(const std::string& message, bool newLine = true);
void Print(int number, bool newLine = true);
void Print(char character, bool newLine = true);

void PrintAnswer(const std::string& message);
void PrintAnswer(int number);
void PrintAnswer(char character);