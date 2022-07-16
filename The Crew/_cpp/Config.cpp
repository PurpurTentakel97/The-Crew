//
// Purpur Tentakel
// 12.07.2022
//

#include "Config.h"
#include "Helper.h"

static PlayerCount playerCount;

PlayerCount GetPlayerCount() {
	return playerCount;
}
bool SetPlayerCount(int input) {
	switch (input) {
	case (3): {
		playerCount = PlayerCount::THREE;
		break;
	}
	case (4): {
		playerCount = PlayerCount::FOUR;
		break;
	}
	case(5): {
		playerCount = PlayerCount::FIVE;
		break;
	}
	default:
	{
		Print("\tbad player count");
		return true;
	}
	}
	return false;
}

void SetPlayerCountWithInput() {
	int input = 0;
	Print("enter player count (3-5)");
	while (not TryGetIntInput(input)) {}
	while (SetPlayerCount(input)) {
		while (not TryGetIntInput(input)) {}
	}
}
