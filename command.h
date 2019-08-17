#pragma once

#include "util.h"

class Command
{
public:
	virtual ~Command() {};
	virtual void Execute() = 0;
};

class ButtonActivate : public Command
{
public:
	virtual void Execute()
	{ 
		DbgLog("wooooooooow");
	}
};
