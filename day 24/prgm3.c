#include <stdio.h>
#include <string.h>
int main() {
    char s[200], longest[100], word[100];
    int i = 0, j = 0;
    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);
    longest[0] = '\0';
    while (s[i] != '\0') {
        if (s[i] != ' ' && s[i] != '\n') {
            word[j++] = s[i];
        } else {
            word[j] = '\0';
            if (strlen(word) > strlen(longest))
                strcpy(longest, word);
            j = 0;
        }
        i++;
    }
    word[j] = '\0';
    if (strlen(word) > strlen(longest))
        strcpy(longest, word);

    printf("Longest word: %s\n", longest);
    return 0;
}