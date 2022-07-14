//
// Purpur Tentakel
// 14.07.2022
//

#include "DSCards.h"
#include "DSConfig.h"
#include "Helper.h"
#include <format>
#include <array>
#include <algorithm>
#include <random>


const static std::string hedNumber = "Nr.";
const static std::string hedDifficulty = "Schwierigkeit";
const static std::string hedTask = "Aufgabe";

// Cards
Card::Card(const std::array<int, 3>& dificulties, const std::array<std::string, 2>& text)
	: threePlayerDifficulty(dificulties[0]), fourPlayerDifficulty(dificulties[1]),
	fivePlayerDifficulty(dificulties[2]), desciption(text[0]), extraText(text[1]) {}
int Card::GetDificulty() const {
	switch (GetPlayerCount()) {
	case (PlayerCount::THREE): {
		return threePlayerDifficulty;
	}
	case (PlayerCount::FOUR): {
		return fourPlayerDifficulty;
	}
	case (PlayerCount::FIVE): {
		return fivePlayerDifficulty;
	}
	default: {
		return fourPlayerDifficulty;
	}
	}
}
std::string Card::GetDesciption() const {
	return desciption;
}
std::string Card::GetExtraText() const {
	return extraText;
}
std::string Card::ToString() const {
	return std::format("Schwirigkeit: {} / Aufgabe: {} / Zusatz: {}",
		GetDificulty(), desciption, extraText);
}


// Free Print Hed
static std::array<int, 4> GetSpacer();
static void PrintHeadline(const std::array<int, 4>& spacer);
static void PrintCard(const Card& card, const std::array<int, 4>& spacer, int count);
static void PrintExtraLine(const Card& card, const std::array<int, 4>& spacer);
static void PrintLine(const std::array<int, 4>& spacer);
static void PrintCharXTimes(int x, char s);

// Free Print
void PrintCardTable() {
	const std::vector<Card>& cards = GetCards();
	const std::array<int, 4> spacer = GetSpacer();
	PrintHeadline(spacer);

	for (int i = 0; i < cards.size(); ++i) {
		const Card& card = cards[i];
		PrintCard(card, spacer, i + 1);
		if (card.GetExtraText().size()) {
			PrintExtraLine(card, spacer);
		}
		PrintLine(spacer);
	}
}
std::array<int, 4> GetSpacer() {
	const std::vector<Card>& cards = GetCards();
	int columnSpacing = 2;
	size_t numberWith = std::to_string(cards.size()).size() > hedNumber.size()
		? std::to_string(cards.size()).size() : hedNumber.size();
	size_t difficultyWith = hedDifficulty.size();
	size_t taskWith = hedTask.size();
	for (const Card& card : cards) {
		size_t size = std::to_string(card.GetDificulty()).size();
		if (size > difficultyWith) {
			difficultyWith = size;
		}

		size = ("- " + card.GetDesciption()).size();
		if (size > taskWith) {
			taskWith = size;
		}
		size = static_cast<std::string>("    - ").size() + card.GetExtraText().size();
		if (size > taskWith) {
			taskWith = size;
		}
	}

	return { columnSpacing, static_cast<int>(numberWith),static_cast<int>(difficultyWith),static_cast<int>(taskWith) };

}
void PrintHeadline(const std::array<int, 4>& spacer) {
	PrintLine(spacer);

	std::array<std::string, 4> headlines = { "",hedNumber,hedDifficulty,hedTask };
	for (int i = 1; i < spacer.size(); ++i) {
		Print('|', false);
		int space = static_cast<int>((spacer[i] - headlines[i].size()) / 2 + spacer[0]);
		PrintCharXTimes(space, ' ');
		Print(headlines[i], false);
		PrintCharXTimes(space, ' ');
	}
	Print('|');

	PrintLine(spacer);
	PrintLine(spacer);
}
void PrintCard(const Card& card, const std::array<int, 4>& spacer, const int count) {
	std::array<std::string, 4> entries = { "",std::to_string(count), std::to_string(card.GetDificulty()),"- " + card.GetDesciption() };
	for (int i = 1; i < spacer.size(); ++i) {
		Print('|', false);
		PrintCharXTimes(spacer[0], ' ');
		Print(entries[i], false);
		PrintCharXTimes(static_cast<int>(spacer[i] - entries[i].size() + spacer[0]), ' ');
	}
	Print('|');
}
void PrintExtraLine(const Card& card, const std::array<int, 4>& spacer) {
	std::array<std::string, 4> entries = { "","","","    - " + card.GetExtraText() };
	for (int i = 1; i < spacer.size(); ++i) {
		Print('|', false);
		PrintCharXTimes(spacer[0], ' ');
		Print(entries[i], false);
		PrintCharXTimes(static_cast<int>(spacer[i] - entries[i].size() + spacer[0]), ' ');
	}
	Print('|');

}
void PrintLine(const std::array<int, 4>& spacer) {
	for (int i = 1; i < spacer.size(); ++i) {
		Print('+', false);
		PrintCharXTimes(2 * spacer[0] + spacer[i], '-');
	}
	Print('+');
}
void PrintCharXTimes(const int x, const char s) {
	for (int i = 0; i < x; ++i) {
		Print(s, false);
	}
}

// Free Cardset Hed
static int GetTotalDifficultyCount();
// Free Cardset
bool TryGetCardSet(const int difficultyCount, std::vector<Card>& selection) {
	int totalDifficultyCount = GetTotalDifficultyCount();
	if (difficultyCount > totalDifficultyCount) {
		return true;
	}
	if (difficultyCount == totalDifficultyCount) {
		selection = GetCards();
		return false;
	}
	std::vector<Card> cards = GetCards();
	std::shuffle(std::begin(cards), std::end(cards), std::default_random_engine());
	for (Card card : cards) {
		Print(card.ToString());
	}
	return false;
}

static int GetTotalDifficultyCount() {
	int count = 0;
	for (Card card : GetCards()) {
		count += card.GetDificulty();
	}
	return count;
}