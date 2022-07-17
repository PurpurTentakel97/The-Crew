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

[[nodiscard]] static InputOrCommandType PrintCommands();
[[nodiscard]] static InputOrCommandType SetPlayerCount();
[[nodiscard]] static InputOrCommandType Reload();
[[nodiscard]] static InputOrCommandType Back();

[[nodiscard]] bool HasCommandPrefix(const std::string& command) {
	const Config& config = Config::GetInstance();
	return !command.empty() && command[0] == config.GetCommandPrefix();
}
[[nodiscard]] InputOrCommandType ExecuteCommand(const std::string& command) {
	const Token& token = LexToken(command);
	switch (token) {
		case Token::COMMAND: 
			return PrintCommands();
		case Token::PLAYER_COUNT:
			return SetPlayerCount();
		case Token::RELOAD: 
			return Reload();
		case Token::BACK:
			return Back();
		case Token::QUIT: 
			std::exit(EXIT_SUCCESS);
		case Token::INVALID: 
			PrintAwenser("invalid command");
			return InputOrCommandType::INVALID_COMMAND;
		default: 
			PrintAwenser("invalid command input");
			return InputOrCommandType::INVALID_COMMAND;
	}
}

[[nodiscard]] bool IsValidInput(InputOrCommandType value) {
	return value == InputOrCommandType::VALID_INPUT;
}
[[nodiscard]] bool IsBackCommand(InputOrCommandType value) {
	return value == InputOrCommandType::BACK_COMMAND;
}

[[nodiscard]] InputOrCommandType PrintCommands() {
	const auto& m_commands = Config::GetInstance().GetCommands();
	for (const std::string& command : m_commands) {
		PrintAwenser(command);
	}
	return InputOrCommandType::EXECUTED_COMMAND;
}
[[nodiscard]] InputOrCommandType SetPlayerCount() {
	PlayerCount& playerCount = PlayerCount::GetInstance();
	InputOrCommandType result =  playerCount.SetPlayerCountWithInput();
	PrintAwenser("done");
	return result;
}
[[nodiscard]] InputOrCommandType Reload() {
	switch (Config::GetInstance().GetProgrammType()) {
		case ProgrammType::DEEP_SEE:
			DSConfig::GetInstance().SetCards();
			PrintAwenser("done");
			return InputOrCommandType::EXECUTED_COMMAND;
		case ProgrammType::ORIGINAL:
			PrintAwenser("no reload");
			return InputOrCommandType::EXECUTED_COMMAND;
		default:
			PrintAwenser("!reload not avalable");
			return InputOrCommandType::INVALID_COMMAND;
	}
}
[[nodiscard]] InputOrCommandType Back() {
	switch (Config::GetInstance().GetProgrammType()) {
		case ProgrammType::ORIGINAL:
		case ProgrammType::DEEP_SEE:
			return InputOrCommandType::BACK_COMMAND;
		default:
			PrintAwenser("!back not avalable");
			return InputOrCommandType::INVALID_COMMAND;
	}
}
