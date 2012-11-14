#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h> 
#include <string.h>
#include "xsum.h" 

int main (int argc, char **argv){
	FILE *someFile;
	unsigned int numOfBytesRead=1;
	int c;
	FILE *fileToWrite;
	char * sumOfOptions = "usage: bmerge [-x CHECKSUM] [-h] [-o OUTPUT] FILE";
	char *nameOfFile = 0;
	char *nameOfFileToWrite = 0;
	char currentlyName[256];
 	int countFiles=1;
	unsigned int calculatedCheckSum=0;
	unsigned int savedCheckSum=0;
	int shouldDoCheckSum = 0;


	while ((c = getopt (argc, argv, "xho:")) != -1){
		switch (c)
		{
		case 'x': 
			shouldDoCheckSum = 1;
			break;

		case 'h':

			printf("%s\n", sumOfOptions );
			exit(0);

			break;

		case 'o':
			nameOfFileToWrite = optarg;


			break;


		default:
			abort ();
		}
	} 

	nameOfFile = argv[optind];

	if (nameOfFileToWrite == 0)
		nameOfFileToWrite = nameOfFile;

	unsigned int arrayForNewFile [1] ;
	fileToWrite = fopen( nameOfFileToWrite, "w");

	sprintf(currentlyName , "%s%s", nameOfFile, ".01");


	someFile = fopen( currentlyName, "r");

	while(someFile != 0){
		numOfBytesRead = 1;
		fread(&savedCheckSum, sizeof(numOfBytesRead), 1, someFile);
		calculatedCheckSum=0;
		while(numOfBytesRead!=0){
			numOfBytesRead = fread(arrayForNewFile, 1, 4, someFile);
			if (numOfBytesRead > 0)
			{
				fwrite (arrayForNewFile, 1, numOfBytesRead, fileToWrite);
				calculatedCheckSum = calculatedCheckSum ^ *arrayForNewFile;
			}
		}


		if (shouldDoCheckSum == 1)
		{
			if (calculatedCheckSum != savedCheckSum)
				printf("bad check sum for file: %s. excpected:%x calculated: %x\n", currentlyName, savedCheckSum, calculatedCheckSum);
		}
		fclose (someFile); 
		++countFiles;

		if(countFiles<10){
		      sprintf(currentlyName , "%s.0%d", nameOfFile, countFiles);
		}
		else{
		      sprintf(currentlyName , "%s.%d", nameOfFile, countFiles);
		} 
		someFile = fopen( currentlyName, "r");
	}

	fclose (fileToWrite);   

  
  return 0;
}  
