//
// Purpur Tentakel
// 12.07.2022
//

#include "Config.h"
#include "Helper.h"

// Config
Config::Config()
	: programmType(ProgrammType::INVALID) {}
[[nodiscard]] Config& Config::GetInstance() {
	static Config config = Config();
	return config;
}
[[nodiscard]] char Config::GetCommandPrefix() const {
	return commandPrefix;
}
[[nodiscard]] const std::array<std::string, 4>& Config::GetCommands() const {
	return commands;
}
[[nodiscard]] ProgrammType Config::GetProgrammType() const {
	return programmType;
}
void Config::SetProgrammType(const ProgrammType programmType_) {
	programmType = programmType_;
}

// PlayerCount
PlayerCount::PlayerCount()
	: playerCount(PlayerCountValue::THREE) {}
[[nodiscard]] PlayerCount& PlayerCount::GetInstance() {
	static PlayerCount playercount = PlayerCount();
	return playercount;
}
[[nodiscard]] PlayerCountValue PlayerCount::GetPlayerCount() const {
	return playerCount;
}
[[nodiscard]] bool PlayerCount::SetPlayerCount(int input) {
	switch (input) {
		case 3:
		case 4:
		case 5: 
			playerCount = static_cast<PlayerCountValue>(input);
			return true;
		default:
			PrintAwenser("bad player count");
			return false;
	}
}
void PlayerCount::SetPlayerCountWithInput() {
	int input = 0;
	Print("enter player count (3-5)");
	while (!TryGetIntInputOrExecuteCommand(input)) {}
	while (!SetPlayerCount(input)) {
		while (!TryGetIntInputOrExecuteCommand(input)) {}
	}
}

