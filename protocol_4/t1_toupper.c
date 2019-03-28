#include <stdio.h>

char to_upper(char c) {
  if (c == 'a' && c <= 'Z') {
     return c + 'A' - 'a';
  }
  return c;
}

int main() {
   char c;
   while ((c = getc(stdin)) != EOF) {
      putchar(to_upper(c));
   }

   return 0;
}