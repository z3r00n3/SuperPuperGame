#include "util.h"
#include "fstream"

using namespace std;

void log(char *str)
{
	 fstream fp;
	 fp.open("dbg.txt", fstream::app);
	 fp << str << endl;
	 fp.close();
}
