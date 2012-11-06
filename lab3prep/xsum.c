#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main (int argc, char **argv){
  FILE *ret;
  unsigned int word;
  unsigned int cksum=0;
  int c;
  char * lala = "usage: xsum [-x] [-h] FILE";
  
   ret = fopen( argv[1], "r"); 
   
    while(fread(&word, sizeof(word), 1, ret)) {
    
      cksum = cksum^word;
  
    }
 while ((c = getopt (argc, argv, "xh:")) != -1){
         switch (c)
           {
	   case 'x': 
	    printf("%x\n",cksum );
	     
             break;
          
	   case 'h':
           
	     printf("%s\n", lala );
	    exit(0);
             
	    break;
           
	   
	   default:
             abort ();
            }
            
 }   
 fclose (ret);   
     
  printf("%d\n", cksum); 
  return 0;
}  