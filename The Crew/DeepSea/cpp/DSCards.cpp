//
// Purpur Tentakel
// 14.07.2022
//

#include "Helper.h"
#include "DSCards.h"
#include "DSConfig.h"
#include <array>
#include <algorithm>
#include <format>
#include <random>


struct Hedline {
	inline static std::string number = "Nr.";
	inline static std::string difficulty = "Schwierigkeit";
	inline static std::string task = "Aufgabe";
	Hedline() = delete;
	Hedline(const Hedline& old) = delete;
};


// Cards
Card::Card(const int index, const std::array<int, 3>& dificulties, const std::array<std::string, 2>& text)
	: m_index(index)
	, m_threePlayerDifficulty(dificulties[0])
	, m_fourPlayerDifficulty(dificulties[1])
	, m_fivePlayerDifficulty(dificulties[2])
	, m_description(text[0])
	, m_extraText(text[1]) {}
[[nodiscard]] int Card::GetIndex() const {
	return m_index;
}
[[nodiscard]] int Card::GetDifficulty() const {
	const PlayerCount& playerCount = PlayerCount::GetInstance();
	switch (playerCount.GetPlayerCount()) {
	case (PlayerCountValue::THREE): {
		return m_threePlayerDifficulty;
	}
	case (PlayerCountValue::FOUR): {
		return m_fourPlayerDifficulty;
	}
	case (PlayerCountValue::FIVE): {
		return m_fivePlayerDifficulty;
	}
	default: {
		return m_fourPlayerDifficulty;
	}
	}
}
[[nodiscard]] std::string Card::GetDesciption() const {
	return m_description;
}
[[nodiscard]] std::string Card::GetExtraText() const {
	return m_extraText;
}
[[nodiscard]] std::string Card::ToString() const {
	return std::format("Schwirigkeit: {} / Aufgabe: {} / Zusatz: {}",
		GetDifficulty(), m_description, m_extraText);
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
	size_t numberWith = std::to_string(cards.size()).size() > Hedline::number.size()
		? std::to_string(cards.size()).size() : Hedline::number.size();
	size_t difficultyWith = Hedline::difficulty.size();
	size_t taskWith = Hedline::task.size();
	for (const Card& card : cards) {
		size_t size = std::to_string(card.GetDifficulty()).size();
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

	std::array<std::string, 4> headlines = { "",Hedline::number,Hedline::difficulty,Hedline::task };
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
	std::array<std::string, 4> entries = { "",std::to_string(count), std::to_string(card.GetDifficulty()),"- " + card.GetDesciption() };
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
[[nodiscard]] bool TryGetCardSet(const int difficultyCount, std::vector<Card>& selection) {
	DSConfig& dsConfig = DSConfig::GetInstance();
	int totalDifficultyCount = GetTotalDifficultyCount();
	if (difficultyCount > totalDifficultyCount) {
		return true;
	}
	if (difficultyCount == totalDifficultyCount) {
		selection = dsConfig.GetCards();
		return false;
	}
	std::vector<Card> cards = dsConfig.GetCards();
	for (int i = 0; i < 10; ++i) {
		selection.clear();
		std::random_device rd;
		std::default_random_engine rng(rd());
		shuffle(cards.begin(), cards.end(), rng);
		int count = 0;
		for (const Card& card : cards) {
			if (count + card.GetDifficulty() <= difficultyCount) {
				count += card.GetDifficulty();
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
	DSConfig& dsConfig = DSConfig::GetInstance();
	for (Card card : dsConfig.GetCards()) {
		count += card.GetDifficulty();
	}
	return count;
}


// Free Remove Cards Hed

// Free Remove Cards
void RemoveCardsFromPool(const std::vector<Card>& selection) {
	std::vector<Card>& cards = DSConfig::GetInstance().GetCards();
	for (int i = 0; i < selection.size(); ++i) {
		for (int j = 0; j < cards.size(); ++j) {
			if (selection[i].GetIndex() == cards[j].GetIndex()) {
				cards.erase(cards.begin()+j);
				break;
			}
		}
	}
}
