//
// Purpur Tentakel
// 14.07.2022
//

#pragma once
#include "Config.h"
#include <string>
#include <vector>

class Card {
private:
	int threePlayerDifficulty;
	int fourPlayerDifficulty;
	int fivePlayerDifficulty;
	std::string description;
	std::string extraText;
public:
	Card(const std::array<int, 3>& difficulties, const std::array<std::string, 2>& text);
	[[nodiscard]] int GetDificulty() const;
	[[nodiscard]] std::string GetDescription() const;
	[[nodiscard]] std::string GetExtraText() const;
	[[nodiscard]] std::string ToString() const;
};

void PrintCardTable(const std::vector<Card>& cards);
[[nodiscard]] bool TryGetCardSet(int difficultyCount, std::vector<Card>& selection);
void RemoveCardsFromPool(const std::vector<Card>& selection);