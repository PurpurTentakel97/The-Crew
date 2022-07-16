//
// Purpur Tentakel
// 12.07.2022
//

#include "Command.h"
#include "Token.h"
#include "Helper.h"
#include "Config.h"
#include <array>
#include <cstdlib>
#include <iostream>
#include <format>

static constexpr char commandPrefix = '!';

static void PrintCommands();

[[nodiscard]] bool HasCommandPrefix(const std::string& command) {
	return not command.empty() and command.front() == commandPrefix;
}

void ExecuteCommand(const std::string& command) {
	const Token token = LexToken(command);
	switch (token) {
		case (Token::COMMAND): {
			PrintCommands();
			break;
		}
		case (Token::PLAYER_COUNT): {
			SetPlayerCountWithInput();
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

static void PrintCommands() {
	constexpr std::array commands = { "!playercount", "!quit", "!commands"};
	for (const auto& command : commands) {
		// Print function not used here to avoid heap allocations due
		// to conversion to std::string
		//
		// TODO: make Print function a variadic template to print anything
		
		// output either with iostream:
		// std::cout << "\t" << command << "\n";

		// or (even better) with iostream and std::format:
		std::cout << std::format("\t{}\n", command);
	}
}
