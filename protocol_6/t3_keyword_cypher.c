#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_encoder (char* kw) {
    int kw_len = strlen(kw);
    char* encoder = malloc( 27 * sizeof(char) );
    int alphabet[26] = { 0 };

    int encoder_index = 0;
    for (int i = 0; i < kw_len; i++) {
        if (kw[i] >= 'A' && kw[i] <= 'Z') {
            if (!alphabet[kw[i] - 65]) {
                encoder[encoder_index++] = kw[i];
                alphabet[kw[i] - 65] = 1;
            }
        } else if (kw[i] >= 'a' &&  kw[i] <= 'z') {
            if (!alphabet[kw[i] - 97]) {
                encoder[encoder_index++] = (char)kw[i] - 32;
                alphabet[kw[i] - 97] = 1;
            }
        }
    }

    // Fill the rest of the encoder array with the remaining characters
    // of the alphabet, while skipping through the ones that were already
    // a part of the keyword
    for (int i = 0; i < 26; i++) {
        if (!alphabet[i]) {
            encoder[encoder_index++] = (char) i + 65;
        }
    }

    encoder[encoder_index] = '\0';
    return encoder;
}

char* encode_keyword_cypher (char* s, char* encoder) {
    int s_len = strlen(s);
    char* cyphered = malloc( s_len + 1 * sizeof(char) );
    char* out = cyphered;
    for (; *s; s++) {
        if (*s >= 'A' && *s <= 'Z') {
            *cyphered++ = encoder[*s - 65]; 
        } else if (*s >= 'a' &&  *s <= 'z') {
            *cyphered++ = encoder[*s - 97];
        } else {
            *cyphered++ = *s;
        }
    }

    *cyphered = '\0';
    return out;
}

char* decode_keyword_cypher (char* s, char* encoder) {
    int s_len = strlen(s);
    char* decyphered = malloc( s_len + 1 * sizeof(char) );
    char* out = decyphered;
    char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Pointer the to the the first char
    char* ch;
    int pos;

    for (; *s; s++) {
        if (*s >= 'A' && *s <= 'Z') {
            ch = strchr(encoder, *s);
            pos = (int)(ch - encoder);
            *decyphered++ = alphabet[pos];
        } else if (*s >= 'a' &&  *s <= 'z') {
            ch = strchr(encoder, *s - 32);
            pos = (int)(ch - encoder);
            *decyphered++ = alphabet[pos];
        } else {
            *decyphered++ = *s;
        }
    }

    *decyphered = '\0';
    return out;
}

char* keyword_cypher (char* s, char* keyword, int decode) {
    char* encoder = get_encoder(keyword);
    printf("Encoder %s\n", encoder);
    char* cyphered;
    if (decode) {
        cyphered = decode_keyword_cypher(s, encoder);
    } else {
        cyphered = encode_keyword_cypher(s, encoder);
    }

    free(encoder);
    return cyphered;
}

int main () {
    char* keyword = "secret";
    char* s = "This is a test message";
    char* cyphered = keyword_cypher(s, keyword, 0);

    printf("Cyphered string '%s' with keyword %s is %s\n", s, keyword, cyphered);

    printf("Decoded: %s", keyword_cypher(cyphered, keyword, 1));
    free(cyphered);
    return 0;
}