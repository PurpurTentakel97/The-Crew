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
	int m_index;
	int m_threePlayerDifficulty;
	int m_fourPlayerDifficulty;
	int m_fivePlayerDifficulty;
	std::string m_description;
	std::string m_extraText;
public:
	Card(const int index, const std::array<int, 3>& difficulties, const std::array<std::string, 2>& text);
	[[nodiscard]] int GetIndex() const;
	[[nodiscard]] int GetDifficulty() const;
	[[nodiscard]] std::string GetDesciption() const;
	[[nodiscard]] std::string GetExtraText() const;
	[[nodiscard]] std::string ToString() const;
};

void PrintCardTable(const std::vector<Card>& cards);
[[nodiscard]] bool TryGetCardSet(int difficultyCount, std::vector<Card>& selection);
void RemoveCardsFromPool(const std::vector<Card>& selection);