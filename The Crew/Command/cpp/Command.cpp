//
// Purpur Tentakel
// 12.07.2022
//

#include "Command.h"
#include "Token.h"
#include "Helper.h"
#include "Config.h"
#include <array>

static void PrintCommands();

[[nodiscard]] bool HasCommandPrefix(const std::string& command) {
	const Config& config = Config::GetInstance();
	return !command.empty() && command[0] == config.GetCommandPrefix();
}
void ExecuteCommand(const std::string& command) {
	const Token& token = LexToken(command);
	switch (token) {
		case (Token::COMMAND): {
			PrintCommands();
			break;
		}
		case (Token::PLAYER_COUNT): {
			PlayerCount& playerCount = PlayerCount::GetInstance();
			playerCount.SetPlayerCountWithInput();
			Print("\tdone");
			break;
		}
		case (Token::QUIT): {
			std::exit(EXIT_SUCCESS);
			break;
		}
		case (Token::INVALID): {
			Print("\tinvalid command");
			break;
		}
		default: {
			Print("\tinvalid command input");
			break;
		}
	}
}

void PrintCommands() {
	const auto& commands = Config::GetInstance().GetCommands();
	for (const std::string& command : commands) {
		Print("\t" + command);
	}
}
