#pragma once

#define DBG_FILE "../dbg.txt"

enum Keys
{
	LEFT = 37,
	UP = 38,
	RIGHT = 39,
	DOWN = 40,
};

void DbgLog(const char *str);
