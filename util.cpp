#include "util.h"
#include "fstream"

using namespace std;

void DbgLog(const char *str)
{
	 fstream fp;
	 fp.open(DBG_FILE, fstream::app);
	 fp << str << endl;
	 fp.close();
}
