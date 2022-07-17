//
// Purpur Tentakel
// 14.07.2022
//

#include "Config.h"

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
void DSConfig::SetDSConfig() {
	PlayerCount& m_playerCount = PlayerCount::GetInstance();
	m_playerCount.SetPlayerCountWithInput();
	SetCards();
}
void DSConfig::SetCards() {
	m_cards = ParseCards();
}
