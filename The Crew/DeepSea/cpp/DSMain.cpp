//
// Purpur Tentakel
// 14.07.2022
//

#include "DSConfig.h"
#include "DSCards.h"
#include "Helper.h"
#include <vector>
#include <windows.h>

extern std::vector<Card> ParseCards();

bool IsValidSelection() {
	Print("valid selection? (1 -> yes)");
	std::string input;
	while(!TryGetStringInput(input)){}
	return input == "1";
}

void ExecuteDeepSea() {
	SetDSConfig();
	while (true) {
		int difficultiyCount = 0;
		Print("enter difficulty (recommended: 5 - 20)");
		while (!TryGetIntInput(difficultiyCount)) {}
		std::vector<Card> selection;
		bool reloaded = false;
		while (TryGetCardSet(difficultiyCount, selection)) {
			if (reloaded) {
				Print("fatal error setting card set");
				Sleep(2500);
				exit(0);
			}
			Print("\tno selection left -> reload cards");
			SetCards(ParseCards());
			reloaded = true;
		}
		PrintCardTable(selection);
		if (!IsValidSelection()) {
			Print("\tretry");
			continue;
		}
		RemoveCardsFromPool(selection);
	}
}