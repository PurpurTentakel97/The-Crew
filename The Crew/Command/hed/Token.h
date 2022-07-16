//
// Purpur Tentakel
// 12.07.2022
//

#pragma once
#include <string>

enum class Token {
	COMMAND, // !commands
	PLAYER_COUNT, // !playercount
	QUIT, // !quit
	INVALID,
};

[[nodiscard]] Token LexToken(const std::string& command);
