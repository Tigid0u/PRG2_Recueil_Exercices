#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool is_a_palindrome(const char *str, size_t size, size_t start_index) {
    size_t mid, i, j;
    if (size % 2 == 0 || size < 3) return false;

    mid = start_index + size / 2;

    i = start_index;
    j = start_index + size - 1;
    while (i < mid && j > mid) {
        if (str[i++] != str[j--]) return false;
    }

    return true;
}

void longest_palindrome_in_string(const char *str, size_t str_size) {
    int size, max_size = 0, max_i = -1, max_j = -1;

    if (str_size < 3) {
        printf("Empty string or string is too short to be a palindrome\n");
        return;
    }

    for (int i = 0; i < str_size; i++) {
        for (int j = i; j < str_size; j += 2) {
            size = j - i + 1;
            if (is_a_palindrome(str, size, i) && size >= max_size) {
                max_i = i;
                max_j = j;
                max_size = size;
            }
        }
    }
    if (max_i < 0 || max_j < 0) {
        printf("No palindrome was found in %s !\n", str);
        return;
    }

    printf("Longest palindromic substring of the said string: ");
    for (int i = max_i; i <= max_j; i++) {
        putchar(str[i]);
    }
}

// int main() {
//     char *str, buf[100];
//     int input_size;

//     printf("String containing potential palindromes: ");
//     fgets(buf, 100, stdin);

//     input_size = strlen(buf);

//     str = (char *)malloc(input_size + 1);
//     if (NULL == str) {
//         printf("Memory allocation error !\n");
//         return -1;
//     }

//     strcpy(str, buf);

//     longest_palindrome_in_string(str, input_size);

//     free(str);
//     return 0;
// }
