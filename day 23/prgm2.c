#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    printf("Enter string: ");
    scanf("%s", s);
    
    int freq[256] = {0};
    int n = strlen(s);
    
    for (int i = 0; i < n; i++)
        freq[(int)s[i]]++;
    
    for (int i = 0; i < n; i++) {
        if (freq[(int)s[i]] > 1) {
            printf("First repeating character: %c", s[i]);
            return 0;
        }
    }
    
    printf("No repeating character found");
    return 0;
}