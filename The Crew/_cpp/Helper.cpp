//
// Purpur Tentakel
// 12.07.2022
//

#include "Helper.h"
#include "Command.h"
#include <iostream>
#include <stdexcept>
#include <random>

[[nodiscard]] static bool CommandCheck(std::string& command);
[[nodiscard]] static std::string ReadInput();
static void StripString(std::string& input);

// Input
[[nodiscard]] std::string ReadInput() {
	std::string toReturn;
	std::getline(std::cin, toReturn);
	StripString(toReturn);
	return toReturn;
}

[[nodiscard]] bool TryGetStringInputOrExecuteCommand(std::string& input) {
	input = ReadInput();
	return !CommandCheck(input);
}
[[nodiscard]] bool TryGetIntInputOrExecuteCommand(int& input) {
	std::string localInput = ReadInput();
	if (CommandCheck(localInput)) {
		return false;
	}
	try {
		input = std::stoi(localInput);
	}
	catch (std::invalid_argument ex) {
		Print("\tbad number");
		return false;
	}
	catch (std::out_of_range ex) {
		Print("\tbad number");
		return false;
	}

	return true;
}

[[nodiscard]] bool CommandCheck(std::string& command) {
	if (HasCommandPrefix(command)) {
		ExecuteCommand(command);
		return true;
	}
	return false;
}


// Output
void Print(const std::string& message, const bool newLine) {
	if (newLine) {
		std::cout << message << std::endl;
		return;
	}
	std::cout << message;
}
void Print(const int number, const bool newLine) {
	if (newLine) {
		std::cout << number << std::endl;
		return;
	}
	std::cout << number;
}
void Print(const char character, const bool newLine) {
	if (newLine) {
		std::cout << character << std::endl;
		return;
	}
	std::cout << character;
}


// Helper
static void StripString(std::string& input) {
	input = input.erase(0, input.find_first_not_of(' '));
	input = input.erase(input.find_last_not_of(' ') + 1, input.size() - 1);
}