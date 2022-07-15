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
static std::array<int, 4> GetSpacer(const std::vector<Card>& cards);
static void PrintHeadline(const std::array<int, 4>& spacer);
static void PrintCard(const Card& card, const std::array<int, 4>& spacer, int count);
static void PrintExtraLine(const Card& card, const std::array<int, 4>& spacer);
static void PrintLine(const std::array<int, 4>& spacer);
static std::string GetCharXTimes(int x, char s);

// Free Print
void PrintCardTable(const std::vector<Card>& cards) {
	const std::array<int, 4> spacer = GetSpacer(cards);
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
std::array<int, 4> GetSpacer(const std::vector<Card>& cards) {
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
	std::string toPrint;
	for (int i = 1; i < spacer.size(); ++i) {
		int space = static_cast<int>((spacer[i] - headlines[i].size()) / 2 + spacer[0]);
		toPrint += '|' + GetCharXTimes(space, ' ') + headlines[i] + GetCharXTimes(space, ' ');
		if (spacer[i] % 2 == 0) {
			toPrint += ' ';
		}
	}
	toPrint += '|';
	Print(toPrint);

	PrintLine(spacer);
	PrintLine(spacer);
}
void PrintCard(const Card& card, const std::array<int, 4>& spacer, const int count) {
	std::array<std::string, 4> entries = { "",std::to_string(count), std::to_string(card.GetDificulty()),"- " + card.GetDesciption() };
	std::string toPrint;
	for (int i = 1; i < spacer.size(); ++i) {
		toPrint += '|' + GetCharXTimes(spacer[0], ' ') + entries[i] + 
			GetCharXTimes(static_cast<int>(spacer[i] - entries[i].size() + spacer[0]), ' ');
	}
	toPrint += '|';
	Print(toPrint);
}
void PrintExtraLine(const Card& card, const std::array<int, 4>& spacer) {
	std::array<std::string, 4> entries = { "","","","    - " + card.GetExtraText() };
	std::string toPrint;
	for (int i = 1; i < spacer.size(); ++i) {
		toPrint += '|' + GetCharXTimes(spacer[0], ' ') + entries[i] + 
			GetCharXTimes(static_cast<int>(spacer[i] - entries[i].size() + spacer[0]), ' ');
	}
	toPrint += '|';
	Print(toPrint);

}
void PrintLine(const std::array<int, 4>& spacer) {
	std::string toPrint;
	for (int i = 1; i < spacer.size(); ++i) {
		toPrint += '+' + GetCharXTimes(2 * spacer[0] + spacer[i], '-');
	}
	toPrint += '+';
	Print(toPrint);
}
std::string GetCharXTimes(const int x, const char s) {
	std::string toReturn(x,s);
	return toReturn;
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
	for (int i = 0; i < 10; ++i) {
		selection.clear();
		std::random_device rd;
		std::default_random_engine rng(rd());
		shuffle(cards.begin(), cards.end(), rng);
		int count = 0;
		for (const Card& card : cards) {
			if (count + card.GetDificulty() <= difficultyCount) {
				count += card.GetDificulty();
				selection.push_back(card);
			}
			if (count >= difficultyCount) {
				break;
			}
		}
		if (count == difficultyCount) {
			return false;
		}
	}

	return true;
}
static int GetTotalDifficultyCount() {
	int count = 0;
	for (Card card : GetCards()) {
		count += card.GetDificulty();
	}
	return count;
}


// Free Remove Cards Hed

// Free Remove Cards
void RemoveCardsFromPool(const std::vector<Card>& selection) {
	std::vector<Card>& cards = GetCards();
	for (int i = 0; i < selection.size(); ++i) {
		for (int j = 0; j < cards.size(); ++j) {
			if (selection[i].GetDesciption() == cards[j].GetDesciption()) {
				cards.erase(cards.begin()+j);
				break;
			}
		}
	}
}
