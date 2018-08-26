#include "../include/filedump.h"

int validateArg(int argc , char *argv[],UtilConfig*config)
{

	char isArgValid=1;//validation flag
	//check arguments count
	if(argc<2)
	{
		//print usage statement
		printf("%s usage : ./fileDump [file] [-format]\n",argv[0]);
		puts("file:file to be printed");
		puts("format:display format");
		isArgValid=0;
	}
	//validate passed file path
	//check format argument if passed
	return isArgValid;
}