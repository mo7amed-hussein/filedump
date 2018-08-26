#ifndef __FILEDUMP__
#define __FILEDUMP__
#include <stdio.h>
#include <math.h>
#define MAX_ROWS 20 //20 row of bytes per page
#define MAX_COLS 10 //10 byte per row
//display formats allowed in utility
typedef enum{HEX,OCTAL,ASCII,HEXASCII,DECIMAL}DispFormat;

//config structure
typedef struct 
{
	FILE *fPtr;//hold file pointer
	DispFormat format;//display format
	int addressSize;// address size based on file size
	int fileSize;//file size
	int pagesCount;//display pages
}UtilConfig;

/**
	validate argument and initialize utility config structure
	@param argc number of arguments
	@param argv array of arguments strings
	@param config pointer to UtilConfig strucutre
	@return 1 if arguments validation is success else 0
**/
int validateArg(int argc , char *argv[],UtilConfig*config);

/**
	print bytes stream on screen
	@param stream bytes stream pointer
	@param len  bytes stream length
	@param format display format
	@param delimter delimter between two successive bytes
**/
void printStream(unsigned char *stream,int len,DispFormat format,char *delimiter);
#endif