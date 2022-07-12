//
// Purpur Tentakel
// 12.07.2022
//

#include "Config.h"

static int maxPlayerCount = 5;
static int minPlayerCount = 3;
static int playerCount = minPlayerCount;

const int GetPlayerCount() {
	return playerCount;
}
void SetPlayerCount(const int count) {
	if (count < minPlayerCount) {
		playerCount = minPlayerCount;
	}
	else if (count > maxPlayerCount) {
		playerCount = maxPlayerCount;
	}
	else {
		playerCount = count;
	}
}