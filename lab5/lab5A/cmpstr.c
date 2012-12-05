#include "cmpstr.h"


int cmpstr(char* anna, char* shiran){
  int i;
  
  for(i=0; anna[i]!=0 && shiran[i]==anna[i]; ++i);
  
  if(anna[i]==shiran[i]) return 0;
  if(anna[i]>shiran[i]) return 1;
  return 2;
  
}
