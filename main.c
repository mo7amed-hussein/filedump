#include<stdio.h>
#include "include/filedump.h"

int main( int argc,char *argv[])
{
	UtilConfig config;
	char isDone=0;
	int address=0;
	int len=0;
	int spaces=0;
	char printFormat[15];
	unsigned char stream[MAX_COLS];
	//validate arguments
	if(validateArg(argc,argv,&config)==0)
	{
		return 0;
	}
	sprintf(printFormat,"%%0%dx   ",config.addressSize*2);

	while(!isDone)
	{
		len = (config.fileSize-address) >MAX_COLS?MAX_COLS:(config.fileSize-address);
		
		fread(stream,len,1,config.fPtr);
		//display address
		printf(printFormat,address);
		//printf("%02x\t",address);
		printStream(stream,len,config.format," ");
		if(config.format==HEXASCII)
		{
			spaces=len<MAX_COLS?(MAX_COLS-len)*3+3:3;
			printf("%*c",spaces,' ');
			printf("|   ");
			printStream(stream,len,ASCII," ");
			printf("%*c|",spaces,' ');
		}
		
		printf("\n");
		address +=len;
		if(address>=config.fileSize)
		{
			isDone=1;
		}
	}

	return 0;
}