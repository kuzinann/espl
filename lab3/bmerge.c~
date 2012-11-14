#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h> 
#include "xsum.h"

int main (int argc, char **argv){
	FILE *someFile;
	int numOfBytesRead=1;
	int c;
	FILE *fileToWrite;
	char * sumOfOptions = "usage: bmerge [-x CHECKSUM] [-h] [-o OUTPUT] FILE";
	char *nameOfFile = 0;


	while ((c = getopt (argc, argv, "x:ho:")) != -1){
		switch (c)
		{
		case 'x': 
			/*  printf("%x\n",cksum );*/

			break;

		case 'h':

			printf("%s\n", sumOfOptions );
			exit(0);

			break;

		case 'o':
			nameOfFile = optarg;

			break;


		default:
			abort ();
		}
	} 
	if (nameOfFile == 0)
		nameOfFile = argv[optind];


 	unsigned int arrayForNewFile [100] ;
	fileToWrite = fopen( nameOfFile, "w");
	someFile = fopen( "", "r");
	while(someFile != 0){		
		while(numOfBytesRead!=0){
			numOfBytesRead = fread(arrayForNewFile, 1, 100, someFile);
			fwrite (arrayForNewFile, 1, numOfBytesRead, fileToWrite);
		}
		
		fclose (someFile); 
		someFile = fopen( "", "r");
	}
	  
	 fclose (fileToWrite);   

  
  return 0;
}  
