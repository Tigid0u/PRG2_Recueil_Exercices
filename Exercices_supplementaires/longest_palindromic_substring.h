#ifndef LONGEST_PALINDROMIC_SUBS_H
#define LONGEST_PALINDROMIC_SUBS_H

#include <stdbool.h>
#include <stdio.h>

bool is_a_palindrome(const char *str, size_t size, size_t start_index);
void longest_palindrome_in_string(const char *str, size_t str_size);

#endif
