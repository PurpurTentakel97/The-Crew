//
// Purpur Tentakel
// 12.07.2022
//

#include "Token.h"

[[nodiscard]] Token LexToken(const std::string& command) {
	if (command == "!commands") {
		return Token::COMMAND;
	}
	else if (command == "!playercount") {
		return Token::PLAYER_COUNT;
	}
	else if (command == "!quit") {
		return Token::QUIT;
	}
	else {
		return Token::INVALID;
	}
}

