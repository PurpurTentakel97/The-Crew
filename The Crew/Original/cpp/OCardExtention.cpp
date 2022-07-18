//
// Purpur Tentakel
// 18.07.2022
//

#include "OCardExtention.h"
#include "Random.h"
#include <stdexcept>
#include <array>

// Card Extention
[[nodiscard]] std::string CardExtentionsToString(const CardExtentions cardExtension) {
	switch (cardExtension) {
	case CardExtentions::ONE_NUMBER:
		return "1";
	case CardExtentions::TWO_NUMBER:
		return "2";
	case CardExtentions::THREE_NUMBER:
		return "3";
	case CardExtentions::FOUR_NUMBER:
		return "4";
	case CardExtentions::FIVE_NUMBER:
		return "5";
	case CardExtentions::ONE_ARROW:
		return ">";
	case CardExtentions::TWO_ARROW:
		return ">>";
	case CardExtentions::THREE_ARROW:
		return ">>>";
	case CardExtentions::FOUR_ARROW:
		return ">>>>";
	case CardExtentions::OMEGA:
		return "omega";
	default:
		throw std::runtime_error("invalid card extention");
	}
}

// Card Extention Generator
[[nodiscard]] static bool DoesExtentionExists(const std::vector<CardExtentions>& extentions, CardExtentions extention);
[[nodiscard]] static bool IsValidCardExtention(CardExtentions cardEctention, int count);

[[nodiscard]] std::vector<CardExtentions> GenerateCardExtentions(int cardCount) {
	int extentionCount = static_cast<int>(CardExtentions::SIZE);
	int count = cardCount > extentionCount ? extentionCount : cardCount;
	Random& random = Random::GetInstance();
	int randomCount = static_cast<int>(random.random(count));

	std::vector<CardExtentions> toReturn;
	toReturn.reserve(randomCount);
	for (int i = 0; i < randomCount;) {
		int randomNumber = static_cast<int>(random.random(extentionCount));
		CardExtentions randomExtention = static_cast<CardExtentions>(randomNumber);

		const bool validEctention = !DoesExtentionExists(toReturn, randomExtention) &&
			IsValidCardExtention(randomExtention, count);
		if (!validEctention) {
			continue;
		}
		toReturn.push_back(randomExtention);
		++i;
	}
	return toReturn;
}
[[nodiscard]] bool DoesExtentionExists(const std::vector<CardExtentions>& extentions, const CardExtentions extention) {
	for (const auto& entry : extentions) {
		if (entry == extention) {
			return true;
		}
	}
	return false;
}
[[nodiscard]] bool IsValidCardExtention(const CardExtentions cardExtention, const int count) {
	if (cardExtention >= CardExtentions::OMEGA) {
		return true;
	}
	if (cardExtention < static_cast<CardExtentions>(count)) {
		return true;
	}
	return false;
}
