//
// Purpur Tentakel
// 12.07.2022
//

#include "Helper.h"
#include "DSCards.h"
#include "DSConfig.h"
#include <vector>

extern std::vector<Card> ParseCards();
void ExecuteDeepSea() {
	std::vector<Card> cards = ParseCards();

	for (Card& card : cards) {
		Print(card.ToString(PlayerCount::FOUR));
	}
}