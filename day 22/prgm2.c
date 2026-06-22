#include <stdio.h>
int main() {
    char str[200];
    int count = 1, i;
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    if (str[0] == '\n') {
        printf("Word count = 0\n");
        return 0;
    }
    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == ' ' && str[i+1] != ' ' && str[i+1] != '\0' && str[i+1] != '\n')
            count++;
    }
    printf("Word count = %d\n", count);
    return 0;
}