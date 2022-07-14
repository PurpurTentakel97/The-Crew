//
// Purpur Tentakel
// 14.07.2022
//

#pragma once
#include "DSCards.h"
#include <vector>

void SetDSConfig();

void SetCards(std::vector<Card> newCards);
std::vector<Card>& GetCards();

