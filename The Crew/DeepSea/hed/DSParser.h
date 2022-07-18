//
// Purpur Tentakel
// 16.07.2022
//

#pragma once

#include "DSCards.h"
#include <vector>

struct FileConfig {
	constexpr static char directoryName[] = "Config/DeepSea";
	constexpr static char fileExtension[] = ".cnfg";
	constexpr static char delimiter = ';';
};

[[nodiscard]] std::vector<DSCard> ParseCards();
