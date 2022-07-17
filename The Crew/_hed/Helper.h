//
// Purpur Tentakel
// 12.07.2022
//

#pragma once

#include <string>

[[nodiscard]] bool TryGetStringInputOrExecuteCommand(std::string& input);
[[nodiscard]] bool TryGetIntInputOrExecuteCommand(int& input);
[[nodiscard]] int GetRandomInt(int max);

void Print(const std::string& message, bool newLine = true);
void Print(int number, bool newLine = true);
void Print(char character, bool newLine = true);

void PrintAwenser(const std::string& message);
void PrintAwenser(int number);
void PrintAwenser(char character);