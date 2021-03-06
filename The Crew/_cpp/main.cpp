//
// Purpur Tentakel
// 12.07.2022
// C++ 20
//

// original Random by coder2k (https://gist.github.com/mgerhold/353e39da27ae9b22c614bc264c8a3d18)

#include "Config.h"
#include "Command.h"
#include "Helper.h"
#include "Execution.h"


static void ExecuteProgramm(int input) {
	Config& config = Config::GetInstance();
	switch (static_cast<ProgrammType>(input)) {
		case (ProgrammType::ORIGINAL): {
			config.SetProgrammType(ProgrammType::ORIGINAL);
			ExecuteOriginal();
			break;
		}
		case (ProgrammType::DEEP_SEE): {
			config.SetProgrammType(ProgrammType::DEEP_SEE);
			ExecuteDeepSea();
			break;
		}
		default: {
			PrintAnswer("Invalid Number");
			break;
		}										   
	}
}

int main() {
	Print("!commands");
	while (true) {
		Print("witch game do you play?\n1 -> Original\n2 -> Deep Sea");
		int input;
		InputOrCommandType result = TryGetIntInputOrExecuteCommand(input);
		if (IsBackCommand(result)) {
			goto BACK;
		}
		if (!IsValidInput(result)) {
			continue;
		}
		ExecuteProgramm(input);
	}
BACK:
	return 0;
}
