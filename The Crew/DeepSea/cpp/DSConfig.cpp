//
// Purpur Tentakel
// 14.07.2022
//

#include "Config.h"
#include "Command.h"

#include "DSConfig.h"
#include "DSCards.h"
#include "DSParser.h"

#include <vector>



// DSConfig
DSConfig::DSConfig(){}
[[nodiscard]] DSConfig& DSConfig::GetInstance() {
	static DSConfig dsConfig;
	return dsConfig;
}
[[nodiscard]] std::vector<Card>& DSConfig::GetCards() {
	return m_cards;
}
[[nodiscard]] InputOrCommandType DSConfig::SetDSConfig() {
	PlayerCount& playerCount = PlayerCount::GetInstance();
	InputOrCommandType result =  playerCount.SetPlayerCountWithInput();
	SetCards();
	return result;
}
void DSConfig::SetCards() {
	m_cards = ParseCards();
}
