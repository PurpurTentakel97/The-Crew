//
// Purpur Tentakel
// 14.07.2022
//

#pragma once
#include <vector>
#include "DSCards.h"

void SetDSConfig();

void SetCards(const std::vector<Card>& newCards);
std::vector<Card>& GetCards();