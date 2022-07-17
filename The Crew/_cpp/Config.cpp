//
// Purpur Tentakel
// 12.07.2022
//

#include "Config.h"
#include "Helper.h"

// Config
Config::Config()
	: m_programmType(ProgrammType::INVALID) {}
[[nodiscard]] Config& Config::GetInstance() {
	static Config config;
	return config;
}
[[nodiscard]] char Config::GetCommandPrefix() const {
	return m_commandPrefix;
}
[[nodiscard]] const std::array<std::string, 5>& Config::GetCommands() const {
	return m_commands;
}
[[nodiscard]] ProgrammType Config::GetProgrammType() const {
	return m_programmType;
}
void Config::SetProgrammType(const ProgrammType programmType_) {
	m_programmType = programmType_;
}

// PlayerCount
PlayerCount::PlayerCount()
	: m_playerCount(PlayerCountValue::THREE) {}
[[nodiscard]] PlayerCount& PlayerCount::GetInstance() {
	static PlayerCount playercount = PlayerCount();
	return playercount;
}
[[nodiscard]] PlayerCountValue PlayerCount::GetPlayerCount() const {
	return m_playerCount;
}
[[nodiscard]] bool PlayerCount::SetPlayerCount(int input) {
	switch (input) {
		case 3:
			PrintAwenser("One of you gets one more card. This card is not played at the end.");
		case 4:
		case 5: 
			m_playerCount = static_cast<PlayerCountValue>(input);
			return true;
		default:
			PrintAwenser("bad player count");
			return false;
	}
}
[[nodiscard]] InputOrCommandType PlayerCount::SetPlayerCountWithInput() {
	int input = 0;
	Print("enter player count (3-5)");
	do {
		InputOrCommandType result = TryGetIntInputOrExecuteCommand(input);
		if (IsBackCommand(result)) {
			return InputOrCommandType::BACK_COMMAND;
		}
		if (!IsValidInput(result)) {
			continue;
		}
	} while (!SetPlayerCount(input));

	return InputOrCommandType::VALID_INPUT;
}

