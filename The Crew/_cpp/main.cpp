//
// Purpur Tentakel
// 12.07.2022
// C++ 20
//

#include "Config.h"
#include "Helper.h"

extern void ExecuteOriginal();
extern void ExecuteDeepSea();

enum class ProgrammType {
	ORIGINAL = 1,
	DEEP_SEE
};

static void ExecuteProgramm(int input) {
	switch (static_cast<ProgrammType>(input)) {
		case (ProgrammType::ORIGINAL): {
			ExecuteOriginal();
			break;
		}
		case (ProgrammType::DEEP_SEE): {
			ExecuteDeepSea();
			break;
		}
		default: {
			Print("Invalid Number");
			break;
		}										   
	}
}

int main() {
	Print("!commands");
	while (true) {
		Print("witch game do you play?\n1 -> original\n2 -> Deep Sea");
		int input;
		if (not TryGetIntInput(input)) {
			continue;
		}
		ExecuteProgramm(input);
	}
}