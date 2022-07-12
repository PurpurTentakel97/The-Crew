//
// Purpur Tentakel
// 12.07.2022
//

#include "Command.h"
#include "Token.h"
#include "Helper.h"
#include <vector>

static char commandPrefix = '!';

static void PrintCommands();

bool HasCommandPrefix(const std::string& command) {
	return command[0] == commandPrefix;
}
void ExecuteCommand(const std::string& command) {
	const Token token = LexToken(command);
	switch (token) {
		case (Token::COMMAND): {
			PrintCommands();
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

static void PrintCommands() {
	const std::vector<std::string> commands = { "!quit","!commands" };
	for (std::string command : commands) {
		Print("\t" + command);
	}
}
