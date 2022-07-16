//
// Purpur Tentakel
// 12.07.2022
// C++ 20
//

#include "Helper.h"
#include "Execution.h"


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
		if (!TryGetIntInputOrExecuteCommand(input)) {
			continue;
		}
		ExecuteProgramm(input);
	}
}