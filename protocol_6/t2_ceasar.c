#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* ceasar (char* in, int key, int decode) {
    int in_len = strlen(in);
    char* out = malloc( (in_len + 1) * sizeof(char) );
    char* encoded = out;
    
    int sign = 1;
    if (decode) {
        sign = -1;
    }

    // printf("Sign %d", sign);
    for (; *in; in++) {
        *out++ = (tolower(*in) - 97 + (sign * key) % 26 + 97);  
    }

    *out = '\0';
    return encoded;
}

int main () {

    char in[] = "test";
    int key = 1;
    char* encoded = ceasar(in, key, 0);
    char* decoded = ceasar(encoded, key, 1);

    printf("Encoded result for ceasar cypher for %s with key %d is %s\n", in, key, encoded);
    printf("Decoded result for ceasar cypher for %s with key %d is %s\n", encoded, key, decoded);
    return 0;
}