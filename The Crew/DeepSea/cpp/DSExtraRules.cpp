//
// Purpur Tentakel
// 16.07.2022
//

#include "DSExtraRules.h"
#include "Helper.h"
#include <format>

[[nodiscard]] std::string GetExtraRule() {
	const int random = GetRandomInt(0,static_cast<int>(ExtraRules::SIZE));
	const std::string first = "extra rule -> ";
	switch (static_cast<ExtraRules>(random)) {
		case ExtraRules::NO_EMERGENCY_SIGNAL:
			return std::format("{}no emergency signal -> you cannot pass a card face down.",first);
		case ExtraRules::ALL_TASKS_ONE_CREW_MEMBER:
			return std::format("{}one crew member must complete all tasks. -> choose this one.", first);
		case ExtraRules::ALL_TASKS_KAPTAIN_OR_COMMUNICATE_IMMEDIATELY:
			return std::format("{}the captain must complete all tasks or it must be communicated before the first round.", first);
		case ExtraRules::COMMUNICATION_WITH_LESS_TOKEN:
			return std::format("{}communicate with fewer tokens. -> put the tokens in the middle and flip 2 already. to communicate, take the remaining ones from the center and communicate normally.", first);
		case ExtraRules::SIMPLE_COMMUNICATION:
			return std::format("{}simple communication -> you cannot use your token to mark which card it is. just place the card in front of you.", first);
		case ExtraRules::NO_COMMUNICATION:
			return std::format("{}no communication. -> turn over your tokens already.", first);
		case ExtraRules::TIME_LIMIT:
			return std::format("{}time limit -> Finish the mission in under {} minutes", first, GetTime());
		case ExtraRules::HARDEST_TASK_FOR_CAPTAIN:
			return std::format("{}hardest task for captain -> the captain must complete the hardest task or one of the hardest tasks.", first);
		case ExtraRules::CARD_FOR_CHOOCE_COMMUNICATE:
			return std::format("{}card for communication -> pick a card. is it a:\n\t-> 1, 2, 3->no restriction\n\t-> 4, 5, 6->communication with less tokens.puts it in the middle and turns over 2.\n\t-> 7, 8, 9->no communication.", first);
		case ExtraRules::COMMUNICATE_TO_THE_SECOND_ROUND:
			return std::format("{}second round communication -> you are not allowed to communicate until the 2nd round is over.", first);
		case ExtraRules::FREE_SELECTION:
			return std::format("{}Free choice of tasks -> you may distribute the tasks freely. not all crew members have to choose a task.", first);
		default:
			return std::format("{}nothing -> you have no restrictions.", first);
	}
}
[[nodiscard]] std::string GetTime() {
	const int random = GetRandomInt(0,static_cast<int>(Time::SIZE));
	switch (static_cast<Time>(random)) {
		case Time::FOUR:
			return "4:00";
		case Time::THREE_THIRTY:
			return "3:30";
		case Time::THREE:
			return "3:00";
		case Time::TWO_THIRTY:
			return "2:30";
		case Time::TWO:
			return "2:00";
		case Time::ONE_THIRTY:
			return "1:30";
		case Time::ONE:
			return "1:00";
		default:
			return "2:30";
	}
}

