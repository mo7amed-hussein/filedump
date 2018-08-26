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
	printf("%d\n",config.format);
	return 0;
}