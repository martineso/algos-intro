#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* get_encoder (char* msg, char* keyword) {
    int msg_len = strlen(msg);
    int kw_len = strlen(keyword);
    char* encoder = malloc( (msg_len + 1) * sizeof(char) );
    int i, j;
    for (i = 0, j = 0; i < msg_len; ++i, ++j) {
        if (j == kw_len) {
            j = 0;
        }
        encoder[i] = toupper(keyword[j]);
    }

    encoder[i] = '\0';
    return encoder;
}

char* encrypt_vigenere (char* msg, char* encoder) {
    int msg_len = strlen(msg);
    char* encrypted = malloc( (msg_len + 1) * sizeof(char) );
    int i;
    for (i = 0; i < msg_len; i++) {
        char msg_ch = toupper(msg[i]);
        if (msg_ch >= 'A' && msg_ch <= 'Z') {
            encrypted[i] = ((msg_ch + encoder[i]) % 26) + 'A';
        } else {
            encrypted[i] = msg_ch;
        }
    }

    encrypted[i] = '\0';
    return encrypted;
}

char* decrypt_vigenere (char* msg, char* encoder) {
    int msg_len = strlen(msg);
    char* decrypted = malloc( (msg_len + 1) * sizeof(char) );
    int i;
    for (i = 0; i < msg_len; i++) {
        char msg_ch = toupper(msg[i]);
        if (msg_ch >= 'A' && msg_ch <= 'Z') {
            decrypted[i] = (((msg_ch - encoder[i]) + 26) % 26) + 'A';
        } else {
            decrypted[i] = msg_ch;
        }
    }

    decrypted[i] = '\0';
    return decrypted;
}

char* vigenere (char* msg, char* keyword, int decode) {
    char* encoder = get_encoder(msg, keyword);
    char* result;
    if (decode) {
        result = decrypt_vigenere(msg, encoder);
    } else {
        result = encrypt_vigenere(msg, encoder);
    }

    free(encoder);
    return result;
}

int main () {
    char* msg = "This is a test message";
    char* keyword = "secret";
    char* encrypted = vigenere(msg, keyword, 0);

    printf("Encrypted msg '%s' with keyword - %s is %s\n", msg, keyword, encrypted);

    printf("Decrypted msg '%s' is %s", encrypted, vigenere(encrypted, keyword, 1));
    free(encrypted);
    return 0;
}