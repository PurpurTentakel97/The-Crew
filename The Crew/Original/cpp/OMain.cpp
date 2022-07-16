//
// Purpur Tentakel
// 12.07.2022
//

#include "Config.h"
#include "Helper.h"


void ExecuteOriginal() {
	Print("Original -> nothing to see here");
	Config::GetInstance().SetProgrammType(ProgrammType::INVALID);
}