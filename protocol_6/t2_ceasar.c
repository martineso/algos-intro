#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* ceasar (char* in, int key, int decode) {
    int in_len = strlen(in);
    char* out = malloc( (in_len + 1) * sizeof(char) );
    char* encoded = out;
    
    if (decode) {
        key = 26 - key;
    }

    char ch;
    for (; *in; in++) {
        if (*in >= 'A' && *in <= 'Z') {
            *out++ = (*in - 65 + key) % 26 + 65;
        } else {
            *out++ = (*in - 97 + key) % 26 + 97;
        }
    }

    *out = '\0';
    return encoded;
}

int main () {

    char in[] = "Test";
    int key = 3;
    char* encoded = ceasar(in, key, 0);
    char* decoded = ceasar(encoded, key, 1);

    printf("Encoded result for ceasar cypher for %s with key %d is %s\n", in, key, encoded);
    printf("Decoded result for ceasar cypher for %s with key %d is %s\n", encoded, key, decoded);

    free(encoded);
    free(decoded);
    return 0;
}