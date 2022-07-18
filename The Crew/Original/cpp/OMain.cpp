//
// Purpur Tentakel
// 12.07.2022
//

#include "Config.h"
#include "Command.h"
#include "Helper.h"
#include "OCard.h"


void ExecuteOriginal() {
	while (true) {
		Print("enter number of cards");
		int cardCount;

		while (true) {
			InputOrCommandType result = TryGetIntInputOrExecuteCommand(cardCount);
			if (IsBackCommand(result)) {
				goto BACK;
			}

			const bool validInput = IsValidInput(result) && cardCount > 0 && cardCount < 37;
			if (validInput) {
				break;
			}
			PrintAnswer("invalid card count (1-36)");
		}
		std::vector<OCard> cards = GenerateCards(cardCount);
		for (const auto& card : cards) {
			Print(card.ToString());
		}
	}
BACK:
	Config::GetInstance().SetProgrammType(ProgrammType::INVALID);
}