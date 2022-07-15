//
// Purpur Tentakel
// 12.07.2022
//

#pragma once
#include <string>

bool TryGetStringInput(std::string& input);
bool TryGetIntInput(int& input);

void Print(const std::string& message, bool newLine = true);
void Print(int number, bool newLine = true);
void Print(char character, bool newLine = true);