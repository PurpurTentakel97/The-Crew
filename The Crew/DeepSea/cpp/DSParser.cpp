//
// Purpur Tentakel
// 12.07.2022
//

#include "Config.h"
#include "Helper.h"

#include "DSParser.h"
#include "DSCards.h"

#include <array>
#include <fstream>


const static char delimiter = ';';
const static std::string fileName = "Config/DeepSea/DeepSeaDefault.cnfg";
static std::vector<std::string> LoadConfig();

[[nodiscard]] std::vector<Card> ParseCards() {
	const std::vector<std::string> input = LoadConfig();
	std::vector<Card> cards;
	cards.reserve(input.size());
	int index = 0;
	for (const std::string& entry : input) {
		size_t start = 0;
		size_t end = 0;

		std::array<int, 3> difficulties;
		for (int i = 0; i < 3; ++i) {
			end = entry.find(delimiter, start);
			difficulties[i] = std::stoi(entry.substr(start, end - start));
			start = end + 1;
		}

		std::array<std::string, 2> text;
		for (int i = 0; i < 2;++i) {
			end = entry.find(delimiter, start);
			text[i] = entry.substr(start, end - start);
			start = end + 1;
		}

		cards.emplace_back(index, difficulties, text);
		++index;
	}
	return cards;
}
std::vector<std::string> LoadConfig() {
	std::fstream file;
	std::vector<std::string> toReturn;
	std::string input;

	file.open(fileName, std::ios::in);
	if (!file.is_open()) {
		PrintAwenser("Cant open Config");
		return toReturn;
	}

	while (std::getline(file, input)) {
		toReturn.push_back(input);
	}
	file.close();
	return toReturn;
}