//
// Purpur Tentakel
// 12.07.2022
//

#pragma once
#include <array>
#include <string>

enum class ProgrammType {
	INVALID,
	ORIGINAL,
	DEEP_SEE
};

enum class PlayerCountValue {
	THREE = 3,
	FOUR,
	FIVE
};

struct Config {
public:
	[[nodiscard]] static Config& GetInstance();
	[[nodiscard]] char GetCommandPrefix() const;
	[[nodiscard]] const std::array<std::string, 4>& GetCommands() const;
	[[nodiscard]] ProgrammType GetProgrammType() const;
	void SetProgrammType(ProgrammType programmType);
private:
	char commandPrefix = '!';
	ProgrammType programmType;
	std::array<std::string,4> commands = { "!commands", "!playercount", "!reload", "!quit" };
	Config();
	Config(const Config& old) = delete;
};

struct PlayerCount {
private:
	PlayerCountValue playerCount;
	PlayerCount();
	PlayerCount(const PlayerCount& old) = delete;
public:
	[[nodiscard]] static PlayerCount& GetInstance();
	[[nodiscard]] PlayerCountValue GetPlayerCount() const;
	[[nodiscard]] bool SetPlayerCount(int input);
	void SetPlayerCountWithInput();
};






