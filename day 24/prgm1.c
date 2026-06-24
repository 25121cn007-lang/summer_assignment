#include <stdio.h>
#include <string.h>
int isRotation(char s1[], char s2[]) {
    int n = strlen(s1);
    if (n != strlen(s2)) return 0;
    char doubled[200];
    strcpy(doubled, s1);
    strcat(doubled, s1);
    if (strstr(doubled, s2) != NULL) return 1;
    return 0;
}
int main() {
    char s1[100], s2[100];
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    if (isRotation(s1, s2))
        printf("%s is a rotation of %s\n", s2, s1);
    else
        printf("%s is NOT a rotation of %s\n", s2, s1);
    return 0;
}