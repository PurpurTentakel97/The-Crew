//
// Purpur Tentakel
// 12.07.2022
//

#include "Config.h"
#include "Helper.h"

static PlayerCount playerCount;

[[nodiscard]] PlayerCount GetPlayerCount() {
	return playerCount;
}

bool SetPlayerCount(int input) {
	switch (input) {
		case 3:
		case 4:
		case 5:
			playerCount = static_cast<PlayerCount>(input);
			return true;
		default:
			Print("\tbad player count");
			return false;
	}
}

void SetPlayerCountWithInput() {
	int input = 0;
	Print("enter player count (3-5)");
	while (not TryGetIntInput(input)) {}
	while (not SetPlayerCount(input)) {
		while (not TryGetIntInput(input)) {}
	}
}
