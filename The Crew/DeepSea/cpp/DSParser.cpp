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
#include <filesystem>

[[nodiscard]] static std::vector<std::string> LoadAllConfig(bool loadAll);
static void LoadSingleConfig(auto fileName, std::vector<std::string>& toReturn);

[[nodiscard]] std::vector<Card> ParseCards() {
	bool loadAll;
	do {
		InputOrCommandType result = TryGetBoolInputOrExecuteCommand(loadAll, "load complete config?");
		if (IsBackCommand(result)) {
			PrintAnswer("!back not available");
		}
		if (IsValidInput(result)) {
			break;
		}
	} while (true);

	const std::vector<std::string> input = LoadAllConfig(loadAll);
	std::vector<Card> cards;
	cards.reserve(input.size());
	int index = 0;
	for (const std::string& entry : input) {
		size_t start = 0;
		size_t end = 0;

		std::array<int, 3> difficulties;
		for (int i = 0; i < 3; ++i) {
			end = entry.find(FileConfig::delimiter, start);
			difficulties[i] = std::stoi(entry.substr(start, end - start));
			start = end + 1;
		}

		std::array<std::string, 2> text;
		for (int i = 0; i < 2; ++i) {
			end = entry.find(FileConfig::delimiter, start);
			text[i] = entry.substr(start, end - start);
			start = end + 1;
		}

		cards.emplace_back(index, difficulties, text);
		++index;
	}
	return cards;
}

[[nodiscard]] std::vector<std::string> LoadAllConfig(const bool loadAll) {
	std::vector<std::string> toReturn;

	for (const auto& file : std::filesystem::directory_iterator(FileConfig::directoryName)) {
		if (file.path().extension() != FileConfig::fileExtension) {
			continue;
		}

		if (!loadAll) {
			bool loadConfig;
			do {
				InputOrCommandType result = TryGetBoolInputOrExecuteCommand(loadConfig, std::format("load this config? -> {}", file.path().string()));
				if (IsBackCommand(result)) {
					PrintAnswer("!back not available");
				}
				if (IsValidInput(result)) {
					break;
				}
			} while (true);
			if (!loadConfig) {
				continue;
			}
		}

		LoadSingleConfig(file, toReturn);
	}

	return toReturn;
}
void LoadSingleConfig(const auto fileName, std::vector<std::string>& toReturn) {
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		return;
	}
	std::string input;
	while (std::getline(file, input)) {
		toReturn.push_back(input);
	}
	file.close();
}