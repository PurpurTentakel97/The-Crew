//
// Purpur Tentakel
// 14.07.2022
//

#include "DSConfig.h"
#include "DSCards.h"
#include "Config.h"
#include <vector>

extern std::vector<Card> ParseCards();

static std::vector<Card> cards;

void SetDSConfig() {
	PlayerCount& playerCount = PlayerCount::GetInstance();
	playerCount.SetPlayerCountWithInput();
	cards = ParseCards();
}

void SetCards(std::vector<Card> newCards) {
	cards = newCards;
}
std::vector<Card>& GetCards() {
	return cards;
}
