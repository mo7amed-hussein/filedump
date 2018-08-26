#include "../include/filedump.h"

int validateArg(int argc , char *argv[],UtilConfig*config)
{

	//check arguments count
	if(argc<2)
	{
		//print usage statement
		printf("%s usage : ./fileDump [file] [-format]\n",argv[0]);
		puts("file:file to be printed");
		puts("format:display format");
		return 0;
	}
	//validate passed file path
	//open file for reading in binary mode
	FILE *ptr=fopen(argv[1],"rb");
	if(ptr==NULL)
	{
		//file not found
		puts("File NOT Found ");
		return 0;
	}else
	{
		int fileSize;
		//seek to file end
		fseek(ptr,0l,SEEK_END);
		//get total # of bytes in file
		fileSize=ftell(ptr);
		fileSize=(log(fileSize)/log(2));
		config->addressSize=(fileSize/8 )+1;
		config->fPtr=ptr;
		rewind(ptr);
	}
	//check format argument if passed
	if(argc<3)
	{
		config->format=HEX;
	}
	else
	{
		char f;
		sscanf(argv[2],"-%c",&f);
		switch(f)
		{
			case 'c':
			config->format=ASCII;
			break;
			case 'x':
			config->format=HEX;
			break;
			case 'o':
			config->format=OCTAL;
			break;
			case 'C':
			config->format=HEXASCII;
			break;
			default:
			config->format=HEX;
			break;

		}
	}
	return 1;
}