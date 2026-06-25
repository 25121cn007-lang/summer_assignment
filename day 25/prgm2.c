#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);

    int freq1[26] = {0}, freq2[26] = {0};

    for (int i = 0; i < strlen(s1); i++)
        freq1[s1[i] - 'a']++;

    for (int i = 0; i < strlen(s2); i++)
        freq2[s2[i] - 'a']++;

    printf("Common characters: ");
    for (int i = 0; i < 26; i++) {
        if (freq1[i] > 0 && freq2[i] > 0) {
            int times = freq1[i] < freq2[i] ? freq1[i] : freq2[i];
            for (int j = 0; j < times; j++)
                printf("%c ", 'a' + i);
        }
    }
    printf("\n");
    return 0;
}