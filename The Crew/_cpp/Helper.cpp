//
// Purpur Tentakel
// 12.07.2022
//

#include "Helper.h"
#include "Command.h"
#include <iostream>
#include <stdexcept>
#include <random>

static bool CommandCheck(std::string& command);
static std::string ReadInput();
static void StripString(std::string& input);

// Input
static std::string ReadInput() {
	std::string toReturn;
	std::getline(std::cin, toReturn);
	StripString(toReturn);
	return toReturn;
}

bool TryGetStringInput(std::string& input) {
	input = ReadInput();
	return CommandCheck(input);
}
bool TryGetIntInput(int& input) {
	std::string localInput = ReadInput();
	if (CommandCheck(localInput)) {
		return true;
	}
	try {
		input = std::stoi(localInput);
	}
	catch (std::invalid_argument ex) {
		Print("\tbad number");
		return true;
	}
	catch (std::out_of_range ex) {
		Print("\tbad number");
		return true;
	}

	return false;
}

static bool CommandCheck(std::string& command) {
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
void Print(const int number, bool newLine) {
	if (newLine) {
		std::cout << number << std::endl;
		return;
	}
	std::cout << number;
}
void Print(const char character, bool newLine) {
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

int GetRandomInteger(const int min, const int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max - 1);

	return distr(gen);
}