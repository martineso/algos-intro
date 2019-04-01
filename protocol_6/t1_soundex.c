#include <stdio.h>
#include <ctype.h>
#include <string.h>

char soundex_code (char ch) {
    char code = ' ';
    
    switch(tolower(ch)) {
      case 'b':
      case 'f':
      case 'p':
      case 'v':
        code = '1';
        break;

      case 'c':
      case 'g':
      case 'j':
      case 'k':
      case 'q':
      case 's':
      case 'x':
      case 'z':
        code = '2';
        break;

      case 'd':
      case 't':
        code = '3';
        break;

      case 'l':
        code = '4';
        break;

      case 'm':
      case 'n':
        code = '5';
        break;

      case 'r':
        code = '6';
        break;

      // All other characters, vowels, punctuation marks etc.
      default:
        code = 0;
        break;
    }

    return code;
}

void soundex (char* in, char* out) {
  int j = 0;
  out[j++] = toupper(in[0]);
  char prev = out[0];
  char code;
  for (int i = 1, len = strlen(in); (i < len && j < 4); i++) {
    code = soundex_code(in[i]);
    if (code && prev != code) {
      out[j++] = code;
    }
    prev = code;
  }

  while (j < 4) {
    out[j++] = '0';
  }
  out[4] = '\0';
}

int main () {
    char out[5];
    char line[256];

    if (fgets(line, sizeof(line), stdin)) {
      soundex(line, out);
    }
    printf("Soundex result %s", out);

    return 0;
}