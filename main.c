#include<stdio.h>
#include "include/filedump.h"

int main( int argc,char *argv[])
{
	UtilConfig config;
	//validate arguments
	if(validateArg(argc,argv,&config)==0)
	{
		return 0;
	}
	unsigned char c[]={0x12,0x44,0x88,0xaf};
	printStream(c,4,HEX,"--");
	puts("");
	return 0;
}