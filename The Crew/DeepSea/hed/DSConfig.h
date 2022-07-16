//
// Purpur Tentakel
// 14.07.2022
//

#pragma once
#include "DSCards.h"
#include <vector>

struct DSConfig {
public:
	[[nodiscard]] static DSConfig& GetInstance();
	[[nodiscard]] std::vector<Card>& GetCards();
	void SetDSConfig();
	void SetCards();
private:
	std::vector<Card> cards;
	DSConfig();
	DSConfig(const DSConfig& old) = delete;
};





