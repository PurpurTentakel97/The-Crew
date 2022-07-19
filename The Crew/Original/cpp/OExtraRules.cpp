//
// Purpur Tentakel
// 19.07.2022
//

#include "OExtraRules.h"
#include "Random.h"
#include <format>

[[nodiscard]] std::string OExtraRuleToString(OExtraRules rule);

[[nodiscard]] std::string GetOExtraRule() {
	Random& random = Random::GetInstance();
	int randomInt = random.random(static_cast<int>(OExtraRules::SIZE));
	return OExtraRuleToString(static_cast<OExtraRules>(randomInt));
}

[[nodiscard]] std::string OExtraRuleToString(OExtraRules rule) {
	const std::string first = "extra rule -> ";
	switch (rule) {
	case OExtraRules::NOTHING:
		return std::format("{}no extra rule", first);
	case OExtraRules::NO_COMMUNICATION:
		return std::format("{}no communication. -> turn over your tokens already.", first);
	case OExtraRules::HALF_COMMUNICATION:
		return std::format("{}simple communication -> you cannot use your token to mark which card it is. just place the card in front of you.", first);
	case OExtraRules::NO_SOS_SINGNAL:
		return std::format("{}no emergency signal -> you cannot pass a card face down.", first);
	case OExtraRules::COMMANDER_DISTRIBUTES_TASKS:
		return std::format("{}commander distrebutes cards by asking if you ready. You only allowed to awenser yes or no.", first);
	case OExtraRules::SPECIFIC_PLAYER_LAST_TICK:
		return std::format("{}choose a player hwo must get the last tick. This player is not the captain", first);
	case OExtraRules::NUMBER_OF_TICKS:
		return std::format("{}at no time no player is allowed to habe 2 more ticks than any other player", first);
	default:
		throw std::runtime_error("no valid extra rule");
	}
}