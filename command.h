#pragma once

#include "util.h"
#include "menu.h"

class Command
{
public:
	virtual ~Command() {};
	virtual void Execute(Menu *menu) = 0;
};

class ButtonActivate : public Command
{
public:
	virtual void Execute(Menu *menu)
	{ 
		menu->InputHandler(Key::ENTER);
	}
};

class ButtonUp : public Command
{
public:
	virtual void Execute(Menu *menu)
	{
		menu->InputHandler(Key::UP);
	}
};

class ButtonDown : public Command
{
public:
	virtual void Execute(Menu *menu)
	{
		menu->InputHandler(Key::DOWN);
	}
};