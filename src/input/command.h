#pragma once

#include "src/graphics/gui/menu.h"

class Command
{
public:
	virtual ~Command() {};
	virtual void Execute(Menu *menu) = 0;
};

class ButtonActivate : public Command
{
public:
	virtual void Execute(Menu *menu) { menu->ButtonActivate(); }
};

class ButtonNext : public Command
{
public:
	virtual void Execute(Menu *menu) { menu->ButtonNext(); }
};

class ButtonLast : public Command
{
public:
	virtual void Execute(Menu *menu) { menu->ButtonLast(); }
};