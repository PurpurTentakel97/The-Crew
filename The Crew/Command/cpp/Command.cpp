//
// Purpur Tentakel
// 12.07.2022
//

#include "Command.h"
#include "Token.h"
#include "Helper.h"
#include "Config.h"
#include <vector>

static char commandPrefix = '!';

static void PrintCommands();

[[nodiscard]] bool HasCommandPrefix(const std::string& command) {
	return command[0] == commandPrefix;
}
void ExecuteCommand(const std::string& command) {
	const Token token = LexToken(command);
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
			exit(0);
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
	const std::vector<std::string> commands = { "!playercount","!quit","!commands"};
	for (std::string command : commands) {
		Print("\t" + command);
	}
}
