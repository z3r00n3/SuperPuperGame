#include <fstream>

#include "util.h"

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
