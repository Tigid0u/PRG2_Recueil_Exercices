#include <stdio.h>
#include <string.h>

int isPalindrome(const char *word);

int main() {
    char word[30], upword[30];
    printf("Saisir un mot: ");
    scanf("%29s", word);
    for (int i = 0; i < 29; i++) upword[i] = toupper(word[i]);
    if (isPalindrome(word)) printf("%s est un palindrome\n", word);
    else printf("%s n'est pas un palindrome", word);
    return 0;
}

int isPalindrome(const char *word) {
    const char *last = (word + strlen(word) - 1), *first = word;
    while (first != last) {
        if (*first != *last) return 0;
        first++;
        last--;
    }
    return 1;
}
