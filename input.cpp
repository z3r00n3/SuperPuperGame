#include "input.h"

Input::Input()
{
	_keyEnter  = new ButtonActivate();
	_keyEscape = NULL;
	_keyLeft   = NULL;
	_keyUp     = new ButtonNext();
	_keyRight  = NULL;
	_keyDown   = new ButtonLast();
}

Input::~Input()
{
	delete _keyEnter;
	delete _keyEscape;
	delete _keyLeft;
	delete _keyUp;
	delete _keyRight;
	delete _keyDown;
}

Command* Input::Handler()
{
	if (agk::GetRawKeyPressed(Key::ENTER)) return _keyEnter;
	if (agk::GetRawKeyPressed(Key::UP))    return _keyUp;
	if (agk::GetRawKeyPressed(Key::DOWN))  return _keyDown;

	return NULL;
}