//
// Purpur Tentakel
// 12.07.2022
//

#pragma once

#include <string>

enum class InputOrCommandType {
	INVALID_INPUT,
	VALID_INPUT,
	INVALID_COMMAND,
	EXECUTED_COMMAND,
	BACK_COMMAND
};

[[nodiscard]] bool IsValidInput(InputOrCommandType value);
[[nodiscard]] bool IsBackCommand(InputOrCommandType value);
[[nodiscard]] bool HasCommandPrefix(const std::string& command);
[[nodiscard]] InputOrCommandType ExecuteCommand(const std::string& command);
