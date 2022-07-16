//
// Purpur Tentakel
// 12.07.2022
//

#pragma once
#include <string>

[[nodiscard]] bool TryGetStringInput(std::string& input);
[[nodiscard]] bool TryGetIntInput(int& input);

void Print(const std::string& message, bool newLine = true);
void Print(int number, bool newLine = true);
void Print(char character, bool newLine = true);