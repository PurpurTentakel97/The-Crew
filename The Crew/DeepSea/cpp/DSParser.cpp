//
// Purpur Tentakel
// 12.07.2022
//

#include <vector>
#include <array>
#include <fstream>
#include "DSConfig.h"
#include "DSCards.h"
#include "Helper.h"

const static char delimiter = ';';
static std::vector<std::string> LoadConfig();

std::vector<Card> ParseCards() {
	const std::vector<std::string> input = LoadConfig();
	std::vector<Card> cards;
	cards.reserve(input.size());
	for (std::string entry : input) {
		size_t start = 0;
		size_t end = 0;

		std::array<int, 3> dificulties;
		for (int i = 0; i < 3; ++i) {
			end = entry.find(delimiter,start);
			dificulties[i] = std::stoi(entry.substr(start, end - start));
			start = end + 1;
		}
		
		std::array<std::string, 2> text;
		for (int i = 0; i < 2;++i) {
			end = entry.find(delimiter, start);
			text[i] = entry.substr(start, end - start);
			start = end + 1;
		}

		cards.emplace_back(dificulties,text);
	}
	return cards;
}

std::vector<std::string> LoadConfig() {
	std::fstream file;
	std::vector<std::string> toReturn;
	std::string input;

	file.open("DeepSea/DeepSea.cnfg", std::ios::in);
	if (!file.is_open()) {
		Print("Cant open Config");
		return toReturn;
	}

	while (std::getline(file, input)) {
		toReturn.push_back(input);
	}
	file.close();
	return toReturn;
}