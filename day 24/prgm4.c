#include <stdio.h>
#include <string.h>
int main() {
    char s[100], result[100];
    int seen[256] = {0};
    int j = 0;
    printf("Enter string: ");
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (seen[(int)s[i]] == 0) {
            seen[(int)s[i]] = 1;
            result[j++] = s[i];
        }
    }
    result[j] = '\0';
    printf("After removing duplicates: %s\n", result);
    return 0;
}