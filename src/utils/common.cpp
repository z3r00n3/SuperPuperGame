#include "common.h"

#include <fstream>

void DbgLog(const char *str)
{
	 std::fstream fp;
	 fp.open(DBG_FILE, std::fstream::app);
	 fp << str << std::endl;
	 fp.close();
}

void ButtonStartAction()
{
	DbgLog("Start");
}
