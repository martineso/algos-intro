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

char* encode_keyword_cipher (char* s, char* encoder) {
    int s_len = strlen(s);
    char* ciphered = malloc( (s_len + 1) * sizeof(char) );
    char* out = ciphered;
    for (; *s; s++) {
        if (*s >= 'A' && *s <= 'Z') {
            *ciphered++ = encoder[*s - 65]; 
        } else if (*s >= 'a' &&  *s <= 'z') {
            *ciphered++ = encoder[*s - 97];
        } else {
            *ciphered++ = *s;
        }
    }

    *ciphered = '\0';
    return out;
}

char* decode_keyword_cipher (char* s, char* encoder) {
    int s_len = strlen(s);
    char* deciphered = malloc( (s_len + 1) * sizeof(char) );
    char* out = deciphered;
    char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Pointer the to the the first char
    char* ch;
    int pos;

    for (; *s; s++) {
        if (*s >= 'A' && *s <= 'Z') {
            ch = strchr(encoder, *s);
            pos = (int)(ch - encoder);
            *deciphered++ = alphabet[pos];
        } else if (*s >= 'a' &&  *s <= 'z') {
            ch = strchr(encoder, *s - 32);
            pos = (int)(ch - encoder);
            *deciphered++ = alphabet[pos];
        } else {
            *deciphered++ = *s;
        }
    }

    *deciphered = '\0';
    return out;
}

char* keyword_cipher (char* s, char* keyword, int decode) {
    char* encoder = get_encoder(keyword);
    printf("Encoder %s\n", encoder);
    char* ciphered;
    if (decode) {
        ciphered = decode_keyword_cipher(s, encoder);
    } else {
        ciphered = encode_keyword_cipher(s, encoder);
    }

    free(encoder);
    return ciphered;
}

int main () {
    char* keyword = "secret";
    char* s = "This is a test message";
    char* ciphered = keyword_cipher(s, keyword, 0);

    printf("ciphered string '%s' with keyword %s is %s\n", s, keyword, ciphered);

    printf("Decoded: %s", keyword_cipher(ciphered, keyword, 1));
    free(ciphered);
    return 0;
}