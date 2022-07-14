//
// Purpur Tentakel
// 12.07.2022
//

#pragma once
#include <string>
#include <vector>
#include <array>
#include "Config.h"

class Card {
private:
	const int threePlayerDifficulty;
	const int fourPlayerDifficulty;
	const int fivePlayerDifficulty;
	const std::string desciption;
	const std::string extraText;
public:
	Card(const std::array<int, 3>& difficulties, const std::array<std::string, 2>& text);
	int GetDificulty(PlayerCount playerCount) const;
	std::string GetDesciption() const;
	std::string GetExtraText() const;
	std::string ToString(PlayerCount playerCount) const;
};

void PrintCardTable();
bool TryGetCardSet(int difficultyCount, std::vector<Card>& selection);