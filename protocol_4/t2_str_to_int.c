#include <stdio.h>

int custom_atoi (const char *str) {
    int result = 0;
    int i = 0;

    while (str[i] != '\0') {
        
        if (str[i] == ' ') {
            i++;
            continue;
        }

        result = (result * 10) + str[i] - '0';
        i++;
    }

    return result;
}

int main () {
    unsigned int i;
    char *s = " 9885";
    i = custom_atoi(s);
    printf("%d\n", i);
    return 0;
}