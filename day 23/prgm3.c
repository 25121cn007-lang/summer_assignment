#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    
    if (strlen(s1) != strlen(s2)) {
        printf("Not anagram");
        return 0;
    }
    
    int freq[256] = {0};
    int n = strlen(s1);
    
    for (int i = 0; i < n; i++) {
        freq[(int)s1[i]]++;
        freq[(int)s2[i]]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("Not anagram");
            return 0;
        }
    }
    
    printf("Anagram!");
    return 0;
}