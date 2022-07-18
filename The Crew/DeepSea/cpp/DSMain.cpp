//
// Purpur Tentakel
// 14.07.2022
//

#include "Helper.h"
#include "Config.h"
#include "Command.h"

#include "DSConfig.h"
#include "DSCards.h"
#include "DSParser.h"
#include "DSExtraRules.h"

#include <windows.h>


[[nodiscard]] InputOrCommandType IsValidSelection() {
	Print("valid selection? (1 -> yes)");
	std::string input;
	while (true) {
		InputOrCommandType result = TryGetStringInputOrExecuteCommand(input);
		if (IsBackCommand(result)) {
			return InputOrCommandType::BACK_COMMAND;
		}
		if (IsValidInput(result)) {
			break;
		}
	}
	if (input != "1") {
		return InputOrCommandType::INVALID_INPUT;
	}

	return InputOrCommandType::VALID_INPUT;

}

void ExecuteDeepSea() {
	DSConfig& dsConfig = DSConfig::GetInstance();
	InputOrCommandType result = dsConfig.SetDSConfig();
	if (IsBackCommand(result)) {
		goto BACK;
	}
	while (true) {
		int difficultiyCount = 0;
		Print("enter difficulty (recommended: 5 - 20)");
		while (true) {
			result = TryGetIntInputOrExecuteCommand(difficultiyCount);
			if (IsBackCommand(result)) {
				goto BACK;
			}
			if (IsValidInput(result)) {
				break;
			}
		}
		RETRY:
		std::vector<DSCard> selection;
		bool reloaded = false;
		while (TryGetCardSet(difficultiyCount, selection)) {
			if (reloaded) {
				PrintAnswer("fatal error setting card set");
				Sleep(2500);
				exit(0);
			}
			PrintAnswer("no selection left -> reload cards");
			dsConfig.SetCards();
			reloaded = true;
		}
		PrintCardTable(selection);
		result = IsValidSelection();
		if (IsBackCommand(result)) {
			goto BACK;
		}
		if (!IsValidInput(result)) {
			PrintAnswer("retry");
			goto RETRY;
		}
		RemoveCardsFromPool(selection);
		Print(GetExtraRule());
	}
BACK:
	Config::GetInstance().SetProgrammType(ProgrammType::INVALID);
}
