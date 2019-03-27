#include <stdio.h>
#include <stdlib.h>

// Does not handle signed integers
void custom_itoa (int num, char* out, int out_length) {

    int pos = out_length - 1;
    char curr;

    // Goes backwards over the number
    // Last position in the string is the null character
    out[pos--] = '\0';
    
    do {
        curr = (num % 10) + 48;
        if (curr < '0' || curr > '9') {
            continue;
        }
        out[pos--] = curr;
    } while (num = num / 10);
}

int main() 
{   
    int x = 123786123;
    int length = snprintf( NULL, 0, "%d", x );
    // Account for null character
    char* s = malloc( length + 1 );
    custom_itoa( x, s, length + 1 );
    printf( "String %s", s );
    
    free(s);
    return 0;
}