//
// Purpur Tentakel
// 12.07.2022
//

#include "DSCards.h"
#include "DSConfig.h"
#include "Helper.h"
#include <format>

// Free Cardset
bool TryGetCardSet(const int difficultyCount, std::vector<Card>& selection) {
	const std::vector<Card>& cards = GetCards();
	if (difficultyCount > GetTotalDifficultyCount()) {
		return true;
	}

	Print(GetRandomInteger(0,static_cast<int>(cards.size()-1)));

	Print(GetTotalDifficultyCount());
	return false;
}

int GetTotalDifficultyCount() {
	const std::vector<Card>& cards = GetCards();
	int count = 0;
	for (const Card& card : cards) {
		count += card.GetDificulty(GetPlayerCount());
	}
	return count;
}