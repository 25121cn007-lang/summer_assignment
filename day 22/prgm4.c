#include <stdio.h>
int main() {
    char str[100], result[100];
    int i, j = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] != ' ')
            result[j++] = str[i];
    }
    result[j] = '\0';
    printf("After removing spaces: %s\n", result);
    return 0;
}