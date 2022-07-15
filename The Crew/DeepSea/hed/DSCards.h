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
	std::string desciption;
	std::string extraText;
public:
	Card(const std::array<int, 3>& difficulties, const std::array<std::string, 2>& text);
	int GetDificulty() const;
	std::string GetDesciption() const;
	std::string GetExtraText() const;
	std::string ToString() const;
};

void PrintCardTable(const std::vector<Card>& cards);
bool TryGetCardSet(int difficultyCount, std::vector<Card>& selection);
void RemoveCardsFromPool(const std::vector<Card>& selection);