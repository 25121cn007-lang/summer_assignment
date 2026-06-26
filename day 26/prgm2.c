#include <stdio.h>

int main() {
    int age;
    char citizenship;
    char criminal;

    printf("=== Voting Eligibility System ===\n\n");

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Are you a citizen of India? (y/n): ");
    scanf(" %c", &citizenship);

    printf("Do you have any criminal record? (y/n): ");
    scanf(" %c", &criminal);

    printf("\n--- Result ---\n");

    if (age < 18) {
        printf(" NOT ELIGIBLE - Age must be 18 or above.\n");
        printf("   Your age: %d (Need %d more years)\n", age, 18 - age);
    } else if (citizenship == 'n' || citizenship == 'N') {
        printf(" NOT ELIGIBLE - Must be an Indian citizen.\n");
    } else if (criminal == 'y' || criminal == 'Y') {
        printf("NOT ELIGIBLE - Criminal record found.\n");
    } else {
        printf(" ELIGIBLE TO VOTE!\n");
        printf("   Age: %d \n", age);
        printf("   Citizenship: Yes \n");
        printf("   Clean Record: Yes \n");
    }

    return 0;
}