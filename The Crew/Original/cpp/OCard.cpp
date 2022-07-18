//
// Purpur Tentakel
// 18.07.2022
//

#include "Random.h"
#include "OCard.h"
#include <format>

// Card Color
[[nodiscard]] std::string CardColorToString(const CardColor cardColor) {
	switch (cardColor) {
		case CardColor::BLUE:
			return "blue";
		case CardColor::GREEN:
			return "green";
		case CardColor::RED:
			return "red";
		case CardColor::YELLOW:
			return "yellow";
		default:
			return "non existing color";
	}
}

// Card
OCard::OCard(CardColor color, int number)
	:m_color(color), m_number(number) {}
[[nodiscard]] CardColor OCard::GetColor() const noexcept {
	return m_color;
}
[[nodiscard]] int OCard::GetNumber() const noexcept {
	return m_number;
}
[[nodiscard]] std::string OCard::ToString() const noexcept {
	return std::format("Card -> {} , {}", CardColorToString(m_color), m_number);
}

// Operator
bool operator== (const OCard& first, const OCard& second) {
	return first.GetColor() == second.GetColor() && first.GetNumber() == second.GetNumber();
}

// Card Generator
[[nodiscard]] static bool DoesCardExists(const std::vector<OCard>& cards, CardColor cardColor, int cardNumber);

[[nodiscard]] std::vector<OCard> GenerateCards(const int count) {
	std::vector<OCard> toReturn;
	Random& random = Random::GetInstance();
	for (int i = 0; i < count; ++i) {
		int randomNumber = static_cast<int>(random.random(9) + 1);
		CardColor randomColor = static_cast<CardColor>(static_cast<int>(random.random(4)));
		if (DoesCardExists(toReturn, randomColor, randomNumber)) {
			--i;
			continue;
		}
		toReturn.emplace_back(randomColor, randomNumber);
	}
	return toReturn;
}
[[nodiscard]] bool DoesCardExists(const std::vector<OCard>& cards, const CardColor cardColor, const int cardNumber) {
	for (const auto& card : cards) {
		if (card.GetColor() == cardColor && card.GetNumber() == cardNumber) {
			return true;
		}
	}
	return false;
}
