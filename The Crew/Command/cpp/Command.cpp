//
// Purpur Tentakel
// 12.07.2022
//

#include "Command.h"
#include "Config.h"
#include "Helper.h"
#include "Token.h"
#include "DSConfig.h"
#include <array>

static void PrintCommands();
static void Reload();

[[nodiscard]] bool HasCommandPrefix(const std::string& command) {
	const Config& config = Config::GetInstance();
	return !command.empty() && command[0] == config.GetCommandPrefix();
}
void ExecuteCommand(const std::string& command) {
	const Token& token = LexToken(command);
	switch (token) {
		case Token::COMMAND: 
			PrintCommands();
			break;
		case Token::PLAYER_COUNT: {
			PlayerCount& playerCount = PlayerCount::GetInstance();
			playerCount.SetPlayerCountWithInput();
			PrintAwenser("done");
			PrintAwenser("reload cards");
			Reload();
			break;
		}
		case Token::RELOAD: 
			Reload();
			break;
		case Token::QUIT: 
			std::exit(EXIT_SUCCESS);
			break;
		case Token::INVALID: 
			PrintAwenser("invalid command");
			break;
		default: 
			PrintAwenser("invalid command input");
			break;
	}
}

void PrintCommands() {
	const auto& commands = Config::GetInstance().GetCommands();
	for (const std::string& command : commands) {
		PrintAwenser(command);
	}
}
void Reload() {
	switch (Config::GetInstance().GetProgrammType()) {
		case ProgrammType::DEEP_SEE:
			DSConfig::GetInstance().SetCards();
			PrintAwenser("done");
			break;
		default:
			PrintAwenser("no reload here");
			break;
	}
}
