#include <stdio.h>
#include <stdlib.h>
#include "fgetname.h"
#include "namelist.h"

int compare (const void * a, const void * b){
	int i=0;
	char* firstName = ((struct namestat*)a)->name;
	char* secName = ((struct namestat*)b)->name;

  	while((firstName[i] == secName[i]))
		++i;
	
	return firstName[i] - secName[i];
	
}

    
int main(int argc, char **argv) {
	FILE *ret;
	int j, i, isEqual=0;
	namelist ourList = make_namelist();


	char tempWord[64];
	char *saveWords[] = {"auto", "double", "int", "long", "break", "else", "long", "switch", "case", "enum", "register", 		"typedef" ,"char", "extern",
	"return", "union", "const", "float", "short", "unsigned", "continue",
	"for","signed", "void", "default", "goto", "sizeof" ,"volatile",
	"do", "if" ,"static" ,"while"};

	for (j=1; j < argc; ++j)
	{
		ret = fopen( argv[j], "r"); /*ret is a pointer to the file*/
	
		while( fgetname(tempWord, 64, ret)){
			isEqual = 0;
			for(i=0; i<32; ++i){


				if(strcmp(tempWord, saveWords[i])!=0){
					isEqual = isEqual+1;
				}
				if(isEqual==32){ /*tempWord not equal to any of the key words*/
					add_name(ourList, tempWord);
				
				}
			}

		}

		fclose (ret);
	}

	qsort (ourList->names, ourList->size, sizeof(struct namestat), compare);

	for(i=0; i<ourList->size; ++i){
		printf("%s ", ourList->names[i].name);
		printf("%d\n", ourList->names[i].count);
	}

	




	

	return 0;
}
