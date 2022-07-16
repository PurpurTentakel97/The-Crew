//
// Purpur Tentakel
// 14.07.2022
//

#include "DSConfig.h"
#include "DSCards.h"
#include "Config.h"
#include "DSParser.h"
#include <vector>



// DSConfig
DSConfig::DSConfig(){}
[[nodiscard]] DSConfig& DSConfig::GetInstance() {
	static DSConfig dsConfig = DSConfig();
	return dsConfig;
}
[[nodiscard]] std::vector<Card>& DSConfig::GetCards() {
	return cards;
}
void DSConfig::SetDSConfig() {
	PlayerCount& playerCount = PlayerCount::GetInstance();
	playerCount.SetPlayerCountWithInput();
	SetCards();
}
void DSConfig::SetCards() {
	cards = ParseCards();
}
