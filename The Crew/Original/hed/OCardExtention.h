//
// Purpur Tentakel
// 18.07.2022
//

#pragma once
#include <string>
#include <vector>

enum class CardExtentions {
	ONE_NUMBER,
	TWO_NUMBER,
	THREE_NUMBER,
	FOUR_NUMBER,
	FIVE_NUMBER,
	OMEGA,
	ONE_ARROW,
	TWO_ARROW,
	THREE_ARROW,
	FOUR_ARROW,
	SIZE,
};

// result >= OMEGA -> true
// result < (CardEctention)cardCount



[[nodiscard]] std::string CardExtentionsToString(const CardExtentions cardExtension);

[[nodiscard]] std::vector<CardExtentions> GenerateCardExtentions(int cardCount);
