#include <stdio.h>
#include <string.h>
void compressString(char s[], char result[]) {
    int n = strlen(s);
    int k = 0;
    for (int i = 0; i < n; ) {
        int count = 1;
        while (i + count < n && s[i + count] == s[i])
            count++;
        result[k++] = s[i];
        if (count > 1)
            k += sprintf(result + k, "%d", count);
        i += count;
    }
    result[k] = '\0';
}
int main() {
    char s[100], result[200];
    printf("Enter string: ");
    scanf("%s", s);
    compressString(s, result);
    if (strlen(result) < strlen(s))
        printf("Compressed: %s\n", result);
    else
        printf("Compression not beneficial. Original: %s\n", s);
    return 0;
}