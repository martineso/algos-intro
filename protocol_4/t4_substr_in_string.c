#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int all_substrings (char* str, int str_len, char* substr, int substr_len, int* positions) {
    int i = 0;
    int position_index = 0;
    int occurrences = 0;
    char* pos = str;

    while (i < str_len) {
        pos = strstr(pos + 1, substr);
        if (pos != NULL) {
            i = pos - str;
            positions[position_index++] = i;
            occurrences++;
        } else {
            break;
        }
    }

    return occurrences;
}

int main () {
    char* str = "This is a test, test";
    char* substr = "test";
    int substr_len = (int)strlen(substr);

    printf("String length: %d \n", strlen(str));
    int positions_length = strlen(str) + 1; 
    int* positions = malloc( positions_length );
    int occurrences = all_substrings(str, strlen(str), substr, strlen(substr) + 1, positions);

    printf("Occurrences %d \n", occurrences);
    for (int i = 0; i < occurrences; i++) {
        printf("Substring at position %d \n", positions[i]);
    }

    free(positions);
    return 0;
}