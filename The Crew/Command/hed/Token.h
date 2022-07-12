//
// Purpur Tentakel
// 12.07.2022
//

#pragma once
#include <string>

enum class Token {
	COMMAND, // !commands
	QUIT, // !quit
	INVALID,
};

const Token LexToken(const std::string& command);
