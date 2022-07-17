//
// Purpur Tentakel
// 12.07.2022
//

#include "Token.h"
#include "Config.h"

[[nodiscard]] Token LexToken(const std::string& command) {
	const auto& m_commands = Config::GetInstance().GetCommands();
	if (command == m_commands[0]) {
		return Token::COMMAND;
	}
	if (command == m_commands[1]) {
		return Token::PLAYER_COUNT;
	}
	if (command == m_commands[2]) {
		return Token::RELOAD;
	}
	if (command == m_commands[3]) {
		return Token::QUIT;
	}

	return Token::INVALID;
}

