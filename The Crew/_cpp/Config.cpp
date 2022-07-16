//
// Purpur Tentakel
// 12.07.2022
//

#include "Config.h"
#include "Helper.h"

PlayerCount::PlayerCount()
	: playerCount(PlayerCountValue::THREE) {}
[[nodiscard]] PlayerCount& PlayerCount::GetInstance() {
	static PlayerCount playercount = PlayerCount();
	return playercount;
}
[[nodiscard]] PlayerCountValue PlayerCount::GetPlayerCount() const {
	return playerCount;
}
bool PlayerCount::SetPlayerCount(int input) {
	switch (input) {
		case 3:
		case 4:
		case 5: 
			playerCount = static_cast<PlayerCountValue>(input);
			return true;
		default:
			Print("\tbad player count");
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

