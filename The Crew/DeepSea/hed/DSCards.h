//
// Purpur Tentakel
// 12.07.2022
//

#pragma once
#include <string>
#include <array>
#include "DSConfig.h"

class Card {
private:
	const int threePlayerDificulty;
	const int fourPlayerDificulty;
	const int fivePlayerDificulty;
	const std::string disciption;
	const std::string extraText;
public:
	Card(const std::array<int,3>& dificulties, const std::array<std::string,2>& text);
	Card(const Card& old_obj);
	int GetDificulty(PlayerCount playerCount) const;
	std::string GetDisciption() const;
	std::string GetExtraText() const;
	std::string ToString(PlayerCount playerCount) const;
};