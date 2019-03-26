#include <stdio.h>
#include <ctype.h>

int main()
{
   char c;
   while ((c = getc(stdin)) != EOF)
   {
      putchar(toupper(c));
   }

   return 0;
}