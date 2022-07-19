//
// Purpur Tentakel
// 19.07.2022
//

#pragma once
#include <string>

enum class OExtraRules {
	NOTHING,
	NO_COMMUNICATION,
	HALF_COMMUNICATION,
	NO_SOS_SINGNAL,
	COMMANDER_DISTRIBUTES_TASKS,
	SPECIFIC_PLAYER_LAST_TICK,
	NUMBER_OF_TICKS,
	SIZE,
};

[[nodiscard]] std::string GetOExtraRule();