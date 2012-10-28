    #include <assert.h>
    #include <stdio.h>
    #include "bclib.h"
    #include "encbc.h"
    

    int main(int argc, char **argv) {	
      
		int bitsArray[80][8] = {{0}};
	    int i,j;
	    int k=0;//number of char from the user include space between words
		    
	    /* encode */
	    for(i=1; i!=argc; ++i){
	      for(j=0; argv[i][j] != 0; ++j){ 
			bc_char2bits(argv[i][j] , bitsArray[k]);
			k=k+1;
	      }
	      if(i != argc-1){
			bc_char2bits(0 , bitsArray[k]);
			k=k+1;
	      } 
	    } 
	    
	/* print */
	    for(j=0; j!=8; ++j){  
	      for(i=0; i<k; ++i){
			if(bitsArray[i][j] == 1){
				printf("%c",'#' );
			}
			else{
				printf("%c",' ' );
			} 
	      }
		printf("\n");
	      
	    }
	return 0;
    }
