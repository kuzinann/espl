#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
 int main(int argc, char **argv) {
	FILE *ret;
	char txt[128]="1";
	int countLine;
	int i;
	int randomLine;

	ret = fopen( argv[1], "r"); 
	for(countLine=-1;*txt!=0 ;++countLine){ 
		txt[0] = 0;
		fgets(txt, 128, ret);	
	}
	fclose (ret);
	srand ( time(NULL) );
	randomLine =(rand() % countLine)+1;
	printf("%d :", randomLine);
	ret = fopen( argv[1], "r");
	for(i=0; i!=randomLine; ++i){
		fgets(txt, 128, ret);
	}
	printf("%s", txt);
	fclose (ret);

	return 0;
  }
