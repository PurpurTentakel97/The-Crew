//
// Purpur Tentakel
// 12.07.2022
//

#include "Token.h"
#include "Config.h"

[[nodiscard]] Token LexToken(const std::string& command) {
	const auto& commands = Config::GetInstance().GetCommands();
	if (command == commands[0]) {
		return Token::COMMAND;
	}
	if (command == commands[1]) {
		return Token::PLAYER_COUNT;
	}
	if (command == commands[2]) {
		return Token::QUIT;
	}

	return Token::INVALID;
}

