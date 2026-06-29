#include <stdio.h>
#include <math.h>
void displayMenu() {
    printf("\n=============================\n");
    printf("     MENU-DRIVEN CALCULATOR  \n");
    printf("=============================\n");
    printf("  1. Addition\n");
    printf("  2. Subtraction\n");
    printf("  3. Multiplication\n");
    printf("  4. Division\n");
    printf("  5. Modulus\n");
    printf("  6. Power\n");
    printf("  7. Square Root\n");
    printf("  0. Exit\n");
    printf("=============================\n");
    printf("Enter your choice: ");
}
int main() {
    int choice;
    double a, b, result;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        if (choice == 0) {
            printf("\nExiting calculator. Goodbye!\n");
            break;
        }
        if (choice == 7) {
            printf("Enter a number: ");
            scanf("%lf", &a);
            if (a < 0) {
                printf("Error: Cannot compute square root of a negative number.\n");
            } else {
                result = sqrt(a);
                printf("Result: sqrt(%.2lf) = %.4lf\n", a, result);
            }
            continue;
        }
        if (choice >= 1 && choice <= 6) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
        } else {
            printf("Invalid choice! Please select a valid option.\n");
            continue;
        }
        switch (choice) {
            case 1:
                result = a + b;
                printf("Result: %.2lf + %.2lf = %.4lf\n", a, b, result);
                break;
            case 2:
                result = a - b;
                printf("Result: %.2lf - %.2lf = %.4lf\n", a, b, result);
                break;
            case 3:
                result = a * b;
                printf("Result: %.2lf * %.2lf = %.4lf\n", a, b, result);
                break;
            case 4:
                if (b == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = a / b;
                    printf("Result: %.2lf / %.2lf = %.4lf\n", a, b, result);
                }
                break;
            case 5:
                if (b == 0) {
                    printf("Error: Modulus by zero is not allowed.\n");
                } else {
                    result = fmod(a, b);
                    printf("Result: %.2lf %% %.2lf = %.4lf\n", a, b, result);
                }
                break;
            case 6:
                result = pow(a, b);
                printf("Result: %.2lf ^ %.2lf = %.4lf\n", a, b, result);
                break;
        }
    }
    return 0;
}