#pragma once

#include "agk.h"
#include "command.h"

///////////////////////////////////////////////////////////////////////////////
// MNEMONIC NAMES FOR KEYS                                                 
///////////////////////////////////////////////////////////////////////////////

#define KEY_ENTER 13
#define KEY_ESCAPE 27
#define KEY_LEFT 37
#define KEY_UP 38
#define KEY_RIGHT 39
#define KEY_DOWN 40

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	Command* Handler();

private:
	Command* _keyEnter;
	Command* _keyEscape;
	Command* _keyLeft;
	Command* _keyUp;
	Command* _keyRight;
	Command* _keyDown;
};