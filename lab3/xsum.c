#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "xsum.h" 

unsigned int word;
unsigned int myCksum=0;

unsigned int cksum(FILE *file){
  
  while(fread(&word, 1, sizeof(word), file)) {

    myCksum = myCksum^word;

  }
  
  
  return(myCksum);
}



  
