//
// Purpur Tentakel
// 12407.2022
//

#include "DSConfig.h"
#include "DSCards.h"
#include <vector>

extern std::vector<Card> ParseCards();

static std::vector<Card> cards;

void SetDSConfig() {
	cards = ParseCards();
	SetPlayerCountWithInput();
}

void SetCards(const std::vector<Card>& newCards) {
	cards = newCards;
}
std::vector<Card>& GetCards() {
	return cards;
}