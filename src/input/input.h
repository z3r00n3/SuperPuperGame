#pragma once

#include "agk.h"
#include "command.h"

///////////////////////////////////////////////////////////////////////////////
// MNEMONIC NAMES FOR KEYS                                                 
///////////////////////////////////////////////////////////////////////////////

class Input
{
public:
	Input();
	~Input();
	Command *Handler();

private:
	Command *_keyEnter;
	Command *_keyEscape;
	Command *_keyLeft;
	Command *_keyUp;
	Command *_keyRight;
	Command *_keyDown;
};