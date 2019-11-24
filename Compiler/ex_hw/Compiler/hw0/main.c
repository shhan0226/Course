#include <stdio.h>
#include <stdlib.h>

extern void countfile(), printtotal();

main(int argc, char *argv[])
{
   register FILE *fp;
   register int i;

   if (argc == 1)
      countfile(stdin, "");
   else {
      i = 1;
      while (i < argc) {
         if ((fp = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "%s: %s을(를) 열 수 없습니다\n", argv[0], argv[i]);
         else {
            countfile(fp, argv[i]);
            fclose(fp);
         }
         i++;
      }
      if (argc > 2) printtotal();
   }
   exit(0);
}
