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
		config->fileSize=fileSize;
		config->pagesCount=fileSize/(MAX_ROWS*MAX_COLS);
		if(fileSize%(MAX_COLS*MAX_ROWS)!=0)
		{
			config->pagesCount++;
		}
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
			case 'd':
			config->format=DECIMAL;
			break;
			default:
			config->format=HEX;
			break;

		}
	}
	return 1;
}

void printStream(unsigned char *stream,int len,DispFormat format,char *delimiter)
{
	int i=0;
	for(i=0;i<len;i++)
	{
		switch(format)
		{
			case HEX:
				printf("%.2x",stream[i]);
				break;
			case OCTAL:
				printf("%.3o",stream[i]);
				break;
			case ASCII:

				if(stream[i]>=' '&&stream[i]<=127)
				{
					printf("%c",stream[i]);
				}
				else
				{
					printf(" ");
				}
				break;
			case DECIMAL:
				printf("%.3d",stream[i]);
				break;
			default:
				printf("%.2x",stream[i]);			
		}
		if(i!= len-1)
		{
			printf("%s",delimiter);	
		}
		
	}
}