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
static void SetPlayerCount();
static void Reload();
static void Back();

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
			SetPlayerCount();
			break;
		}
		case Token::RELOAD: 
			Reload();
			break;
		case Token::BACK:
			Back();
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
	const auto& m_commands = Config::GetInstance().GetCommands();
	for (const std::string& command : m_commands) {
		PrintAwenser(command);
	}
}
void SetPlayerCount() {
	PlayerCount& playerCount = PlayerCount::GetInstance();
	playerCount.SetPlayerCountWithInput();
	PrintAwenser("done");
}
void Reload() {
	switch (Config::GetInstance().GetProgrammType()) {
		case ProgrammType::DEEP_SEE:
			DSConfig::GetInstance().SetCards();
			PrintAwenser("done");
			break;
		case ProgrammType::ORIGINAL:
			PrintAwenser("no reload");
		default:
			PrintAwenser("no reload here");
			break;
	}
}
void Back() {
	PrintAwenser("TODO");
}
