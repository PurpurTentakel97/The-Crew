//
// Purpur Tentakel
// 18.07.2022
//

#pragma once
#include <string>
#include <vector>

enum class CardColor {
	GREEN,
	RED,
	BLUE,
	YELLOW,
};

[[nodiscard]] std::string CardColorToString(CardColor cardColor);

class OCard {
public:
	OCard(CardColor color, int number);
	[[nodiscard]] CardColor GetColor() const noexcept;
	[[nodiscard]] int GetNumber() const noexcept;
	[[nodiscard]] std::string ToString() const noexcept;
private:
	CardColor m_color;
	int m_number;
};

bool operator== (const OCard& first, const OCard& second);

[[nodiscard]] std::vector<OCard> GenerateCards(int count);
