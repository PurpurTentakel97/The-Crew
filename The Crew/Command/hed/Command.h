//
// Purpur Tentakel
// 12.07.2022
//

#pragma once

#include <string>

[[nodiscard]] bool HasCommandPrefix(const std::string& command);
void ExecuteCommand(const std::string& command);
