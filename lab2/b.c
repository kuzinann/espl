 
 int main(int argc, char **argv) {
   printf("hello ");
   if(argc>1)
     printf("%s", argv[1]);
   else
     foo();   /* love **/
   printf("/n");

   return 0;
 }
