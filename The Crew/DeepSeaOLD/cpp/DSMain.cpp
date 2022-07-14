//
// Purpur Tentakel
// 12.07.2022
//

#include "Helper.h"
#include "DSCards.h"
#include "Config.h"
#include "DSConfig.h"
#include <vector>
#include <windows.h>

extern std::vector<Card> ParseCards();


void ExecuteDeepSea() {
	SetDSConfig();
	while (true) {
		int difficultiyCount = 0;
		Print("enter difficulty (recommended: 5 - 20)");
		while (TryGetIntInput(difficultiyCount)) {}
		std::vector<Card> selection;
		bool reloaded = false;
		while (TryGetCardSet(difficultiyCount, selection)) {
			if (reloaded) {
				Print("fatal error setting card set");
				Sleep(5000);
				exit(0);
			}
			Print("\tno selection left -> reload cards");
			SetCards(ParseCards());
			reloaded = true;
		}

	}

	PrintCardTable();
}