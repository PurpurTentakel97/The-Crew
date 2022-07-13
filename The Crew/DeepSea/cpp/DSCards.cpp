//
// Purpur Tentakel
// 12.07.2022
//

#include "DSCards.h"
#include "Helper.h"
#include <format>

Card::Card(const std::array<int,3>& dificulties, const std::array<std::string,2>& text)
	:threePlayerDificulty(dificulties[0]), fourPlayerDificulty(dificulties[1]),
	fivePlayerDificulty(dificulties[2]), disciption(text[0]), extraText(text[1]) {}
Card::Card(const Card& old_obj) 
	: threePlayerDificulty(old_obj.threePlayerDificulty), fourPlayerDificulty(old_obj.fourPlayerDificulty),
	fivePlayerDificulty(old_obj.fivePlayerDificulty), disciption(old_obj.disciption), extraText(old_obj.extraText)
{
	Print("COPY!");
}
int Card::GetDificulty(const PlayerCount playerCount) const {
	switch (playerCount) {
		case (PlayerCount::THREE): {
			return threePlayerDificulty;
		}
		case (PlayerCount::FOUR): {
			return fourPlayerDificulty;
		}
		case (PlayerCount::FIVE): {
			return fivePlayerDificulty;
		}
		default: {
			return fourPlayerDificulty;
		}
	}
}
std::string Card::GetDisciption() const {
	return disciption;
}
std::string Card::GetExtraText() const {
	return extraText;
}
std::string Card::ToString(const PlayerCount playerCount) const {
	return std::format("Schwirigkeit: {} / Aufgabe: {} / Zusatz: {}", 
		GetDificulty(playerCount), disciption, extraText);
}