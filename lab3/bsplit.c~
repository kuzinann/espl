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
  
  unsigned int currCksum = 0;
    
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
  
  numOfBytesRead = fread(arrayForNewFile, 1, maxSizeFromUser, originalFile); /*reads maxSizeFromUser at most bytes- 1 byte each time and saves it in arrayForNewFile*/

  if(numOfBytesRead!=0){
   
    if(numOfFile<10){
      sprintf(numOfFileStr , "FILE0.%d", numOfFile); /*adds the numOfFile into "FILE.0%d" and saves the resulting string in numOfFileStr */
     
    }else{
      sprintf(numOfFileStr , "FILE.%d", numOfFile); /*adds the numOfFile into "FILE.%d" and saves the resulting string in numOfFileStr */
  
    } 
    /* printf ("Characters: %c %d \n", 'a', 65);*/
    
    fileToWrite = fopen( numOfFileStr, "w+"); /*creates a new file to write&read to, called numOfFileStr*/
    
    fwrite ( &currCksum, sizeof(currCksum), 1, fileToWrite);/*write 4 bytes of "0" into the beggining of the new file*/
   
    fwrite ( arrayForNewFile, 1, numOfBytesRead, fileToWrite); /*write into the new file all the chunk data from the arrayForNewFile*/
    
    fseek( fileToWrite, sizeof(currCksum) , SEEK_SET ); /*Sets the position indicator associated with the stream to a new position- 4 bytes after the beggining of the file */
    
    currCksum = cksum(fileToWrite); /*calculates the cksum of the new file */
    
    rewind ( fileToWrite ); /* Set position of stream to the beginning */
    
    fwrite ( &currCksum, sizeof(currCksum), 1, fileToWrite); /*write the currCksum in the beggining of the fileToWrite- override the "0" that was there */
    
    currCksum = 0; 
   
    ++numOfFile;
    
    fclose(fileToWrite);
  }
}
  
  

fclose (originalFile);   
  
  return 0;
}  
