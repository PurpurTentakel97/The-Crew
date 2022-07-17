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
	[[nodiscard]] InputOrCommandType SetDSConfig();
	void SetCards();
private:
	std::vector<Card> m_cards;
	DSConfig();
	DSConfig(const DSConfig& old) = delete;
};





