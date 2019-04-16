#include <stdio.h>
#include <string.h>

int min3(int a, int b, int c)
{
    if (a < b && a < c)
    {
        return a;
    }
    if (b < a && b < c)
    {
        return b;
    }

    return c;
}

// Recursive implementation of the Levenshtein algorithm
// https://en.wikipedia.org/wiki/Levenshtein_distance
int levenshtein(char *str_a, int str_a_len, char *str_b, int str_b_len)
{
    int a = 0, b = 0, c = 0, cost = 0;
    // Base cases

    // If either string is empty, return the length of the other one
    if (!str_a_len)
    {
        return str_b_len;
    }

    if (!str_b_len)
    {
        return str_a_len;
    }

    /* If the last letters are the same, move the position to the next characters
     * in each string
     */
    if (str_a[str_a_len - 1] == str_b[str_b_len - 1])
    {
        cost = 1;
        // return levenshtein(str_a, str_a_len, str_b, str_b_len);
    }

    /* else try:
         *      changing last letter of s to that of t; or
         *      remove last letter of s; or
         *      remove last letter of t,
         * any of which is 1 edit plus editing the rest of the strings
         */
    return min3(
        levenshtein(str_a, str_a_len - 1, str_b, str_b_len    ) + 1,
        levenshtein(str_a, str_a_len    , str_b, str_b_len - 1) + 1,
        levenshtein(str_a, str_a_len - 1, str_b, str_b_len - 1) + cost
    );
}

int main()
{
    char *s1 = "test";
    char *s2 = "teste";
    int distance = levenshtein(s1, strlen(s1), s2, strlen(s2));
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);
    return 0;
}