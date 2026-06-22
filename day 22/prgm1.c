#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len, isPalin = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalin = 0;
            break;
        }
    }

    if (isPalin)
        printf("%s is a Palindrome.\n", str);
    else
        printf("%s is NOT a Palindrome.\n", str);

    return 0;
}