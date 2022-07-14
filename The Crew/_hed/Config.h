//
// Purpur Tentakel
// 12.07.2022
//

#pragma once

enum class PlayerCount {
	THREE = 3,
	FOUR,
	FIVE
};

PlayerCount GetPlayerCount();
bool SetPlayerCount(int input);
void SetPlayerCountWithInput();