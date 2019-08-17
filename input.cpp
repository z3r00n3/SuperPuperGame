#include "input.h"

InputHandler::InputHandler()
{
	_keyEnter  = new ButtonActivate();
	_keyEscape = NULL;
	_keyLeft   = NULL;
	_keyUp     = NULL;
	_keyRight  = NULL;
	_keyDown   = NULL;
}

InputHandler::~InputHandler()
{
	delete _keyEnter;
	delete _keyEscape;
	delete _keyLeft;
	delete _keyUp;
	delete _keyRight;
	delete _keyDown;
}

Command* InputHandler::Handler()
{
	if (agk::GetRawKeyPressed(KEY_ENTER)) return _keyEnter;

	return NULL;
}