#include <stdio.h>
#include <stdlib.h>

char* get_encoder (char* kw, int kw_len) {
    char* encoder = malloc( 26 * sizeof(char) );
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
                encoder[encoder_index++] = (char)kw[i] - (97 - 65);
                alphabet[kw[i] - 97] = 1;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!alphabet[i]) {
            encoder[encoder_index++] = (char) i + 65;
        }
    }

    encoder[encoder_index++] = '\0';
    return encoder;
}

char* encode_keyword_cypher (char* s, int s_len, char* encoder) {
    char* cyphered = malloc( s_len * sizeof(char) );
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

char* keyword_cypher (char* s, int s_len, char* keyword, int keyword_len) {
    char* encoder = get_encoder(keyword, keyword_len);
    char* cyphered = encode_keyword_cypher(s, s_len, encoder);
    free(encoder);
    return cyphered;
}

int main () {

    char* keyword = "secret";
    int keyword_len = 6;
    char* s = "This is a test message";
    int s_len = 22;
    char* cyphered = keyword_cypher(s, s_len, keyword, keyword_len);

    printf("Cyphered string '%s' with keyword %s is %s\n", s, keyword, cyphered);

    free(cyphered);
    return 0;
}