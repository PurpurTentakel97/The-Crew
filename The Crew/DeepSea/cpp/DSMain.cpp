//
// Purpur Tentakel
// 14.07.2022
//

#include "Helper.h"
#include "Config.h"

#include "DSConfig.h"
#include "DSCards.h"
#include "DSParser.h"
#include "DSExtraRules.h"

#include <windows.h>


bool IsValidSelection() {
	Print("valid selection? (1 -> yes)");
	std::string input;
	while(!TryGetStringInputOrExecuteCommand(input)){}
	return input == "1";
}

void ExecuteDeepSea() {
	DSConfig& dsConfig = DSConfig::GetInstance();
	dsConfig.SetDSConfig();
	while (true) {
		int difficultiyCount = 0;
		Print("enter difficulty (recommended: 5 - 20)");
		while (!TryGetIntInputOrExecuteCommand(difficultiyCount)) {}
		std::vector<Card> selection;
		bool reloaded = false;
		while (TryGetCardSet(difficultiyCount, selection)) {
			if (reloaded) {
				PrintAwenser("fatal error setting card set");
				Sleep(2500);
				exit(0);
			}
			PrintAwenser("no selection left -> reload cards");
			dsConfig.SetCards();
			reloaded = true;
		}
		PrintCardTable(selection);
		if (!IsValidSelection()) {
			PrintAwenser("retry");
			continue;
		}
		RemoveCardsFromPool(selection);
		Print(GetExtraRule());
	}
	Config::GetInstance().SetProgrammType(ProgrammType::INVALID);
}