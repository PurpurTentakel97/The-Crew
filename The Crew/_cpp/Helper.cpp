//
// Purpur Tentakel
// 12.07.2022
//

#include "Command.h"
#include "Helper.h"
#include "Random.h"

#include <iostream>
#include <stdexcept>
#include <random>

[[nodiscard]] static std::string ReadInput();
static void StripString(std::string& input);

// Input
[[nodiscard]] std::string ReadInput() {
	std::string toReturn;
	std::getline(std::cin, toReturn);
	StripString(toReturn);
	return toReturn;
}

[[nodiscard]] InputOrCommandType TryGetStringInputOrExecuteCommand(std::string& input) {
	input = ReadInput();
	if (HasCommandPrefix(input)) {
		return ExecuteCommand(input);
	}
	return InputOrCommandType::VALID_INPUT;
}
[[nodiscard]] InputOrCommandType TryGetIntInputOrExecuteCommand(int& input) {
	std::string localInput = ReadInput();
	if (HasCommandPrefix(localInput)) {
		return ExecuteCommand(localInput);
	}

	try {
		input = std::stoi(localInput);
	}
	catch (std::invalid_argument ex) {
		PrintAwenser("bad number");
		return InputOrCommandType::INVALID_INPUT;
	}
	catch (std::out_of_range ex) {
		PrintAwenser("bad number");
		return InputOrCommandType::INVALID_INPUT;
	}

	return InputOrCommandType::VALID_INPUT;
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

void PrintAwenser(const std::string& message) {
	std::cout << "-> " << message << std::endl;
}
void PrintAwenser(const int number) {
	std::cout << "-> " << number << std::endl;
}
void PrintAwenser(const char character) {
	std::cout << "-> " << character << std::endl;
}


// Helper
static void StripString(std::string& input) {
	input = input.erase(0, input.find_first_not_of(' '));
	input = input.erase(input.find_last_not_of(' ') + 1, input.size() - 1);
}
[[nodiscard]] int GetRandomInt(const int max) {
	Random& random = Random::GetInstance();
	const int randomInt = static_cast<int>(random.random(max));
	return randomInt;
}