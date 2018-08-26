#ifndef __FILEDUMP__
#define __FILEDUMP__

//display formats allowed in utility
typedef enum{HEX,OCTAL,ASCII,HEXASCII}DispFormat;

//config structure
typedef struct 
{
	File *fPtr;//hold file pointer
	DispFormat format;//display format
	int addressSize;// address size based on file size 
}UtilConfig;

/**
	validate argument and initialize utility config structure
	@param argc number of arguments
	@param argv array of arguments strings
	@param config pointer to UtilConfig strucutre
	@return 0 if arguments validation is success else -1
**/
int validateArg(int argc , char *argv[],UtilConfig*config);

/**
	print bytes stream on screen
	@param stream bytes stream pointer
	@param len  bytes stream length
	@param format display format
	@param delimter delimter between two successive bytes
**/
void printStream(char *stream,int len,DispFormat format,char *delimiter);
#endif