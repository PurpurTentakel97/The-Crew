//
// Purpur Tentakel
// 12.07.2022
//

#include "Token.h"

[[nodiscard]] Token LexToken(const std::string& command) {
	if (command == "!commands") {
		return Token::COMMAND;
	}
	if (command == "!playercount") {
		return Token::PLAYER_COUNT;
	}
	if (command == "!quit") {
		return Token::QUIT;
	}

	return Token::INVALID;
}

