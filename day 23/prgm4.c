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
    
    int maxFreq = 0;
    char maxChar;
    
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = (char)i;
        }
    }
    
    printf("Maximum occurring character: %c (%d times)", maxChar, maxFreq);
    return 0;
}