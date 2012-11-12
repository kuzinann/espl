#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h> 
#include <string.h>
#include "xsum.h" 

int main (int argc, char **argv){
  FILE *originalFile;
  int numOfBytesRead=1;
  int c;
  
  FILE *fileToWrite;
  char * sumOfOptions = "usage: bsplit [-x] [-h] [-b SIZE] FILE";
  int maxSizeFromUser=1024;
  
  int numOfFile=1;
  char numOfFileStr[50];
  
  unsigned int originalFileCksum = 0;
  
  originalFile = fopen( argv[argc-1], "r"); /*opens the original file */
    
while ((c = getopt (argc, argv, "xhb:")) != -1){
	switch (c)
	  {
	  case 'x': 
	    originalFileCksum = cksum(originalFile);
	    printf("%d\n", originalFileCksum );
	    
	    break;
	  
	  case 'h':
	  
	    printf("%s\n", sumOfOptions );
	    exit(0);
	    
	    break;
	    
	  case 'b':
	  
	    maxSizeFromUser = atoi(optarg);

	
	    
	    break;
	  
	  
	  default:
	    abort ();
	    }
	    
} 


  unsigned int arrayForNewFile [(maxSizeFromUser+3)/4] ;
  
while(numOfBytesRead){
  numOfBytesRead = fread(arrayForNewFile, 1, maxSizeFromUser, originalFile); /*reads maxSizeFromUser at most bytes- 1 byte each time*/

  if(numOfBytesRead!=0){
   
    if(numOfFile<10){
      sprintf(numOfFileStr , "FILE0.%d", numOfFile); /*adds the numOfFile into "FILE.0%d" and saves the resulting string in numOfFileStr */
     
    }else{
      sprintf(numOfFileStr , "FILE.%d", numOfFile); /*adds the numOfFile into "FILE.%d" and saves the resulting string in numOfFileStr */
  
    } 
    /* printf ("Characters: %c %d \n", 'a', 65);*/
    
    fileToWrite = fopen( numOfFileStr, "w"); /*creates a new file to write to, called numOfFileStr*/
    
    fwrite ( arrayForNewFile, 1, numOfBytesRead, fileToWrite);/*write into the new file*/
      
    ++numOfFile;
    
    fclose(fileToWrite);
  }
}
  
  

fclose (originalFile);   
  
  return 0;
}  
