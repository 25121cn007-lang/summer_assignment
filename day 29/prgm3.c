#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[100], t[100];

int main() {
    int ch, i;
    printf("Enter string: "); scanf("%s", s);

    while(1) {
        printf("\n1.Length 2.Upper 3.Lower 4.Reverse 5.Palindrome 6.Concat 7.Compare 8.Copy 0.Exit\nChoice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Length: %d\n", strlen(s));
                break;

            case 2:
                for(i=0; s[i]; i++) s[i]=toupper(s[i]);
                printf("Upper: %s\n", s);
                break;

            case 3:
                for(i=0; s[i]; i++) s[i]=tolower(s[i]);
                printf("Lower: %s\n", s);
                break;

            case 4:
                strrev(s);
                printf("Reversed: %s\n", s);
                break;

            case 5:
                printf(strcmp(s, strrev(strdup(s)))==0 ? "Palindrome!\n" : "Not Palindrome!\n");
                break;

            case 6:
                printf("Enter string to concat: "); scanf("%s", t);
                strcat(s, t);
                printf("Result: %s\n", s);
                break;

            case 7:
                printf("Enter string to compare: "); scanf("%s", t);
                printf(strcmp(s,t)==0 ? "Strings are Equal!\n" : "Strings are Not Equal!\n");
                break;

            case 8:
                strcpy(t, s);
                printf("Copied: %s\n", t);
                break;

            case 0: return 0;

            default: printf("Invalid!\n");
        }
    }
}