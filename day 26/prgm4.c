#include <stdio.h>
int main() {
    int pin;
    int correctPin = 1234;
    float balance = 50000.00;
    int choice;
    float amount;
    int attempts = 0;
    printf("=======\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\=======================\n");
    printf("       WELCOME TO ATM         \n");
    printf("==============================\n\n");
    while (attempts < 3) {
        printf("Enter PIN: ");
        scanf("%d", &pin);
        attempts++;
        if (pin == correctPin) {
            break;
        } else {
            printf("❌ Wrong PIN! %d attempt(s) remaining.\n\n", 3 - attempts);
        }

        if (attempts == 3) {
            printf("🔒 Card Blocked! Too many wrong attempts.\n");
            return 0;
        }
    }

    printf("\n✅ PIN Correct! Welcome!\n\n");

    // Main menu loop
    while (1) {
        printf("==============================\n");
        printf("         MAIN MENU            \n");
        printf("==============================\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {

            case 1:
                printf("💰 Current Balance: Rs. %.2f\n\n", balance);
                break;

            case 2:
                printf("Enter deposit amount: Rs. ");
                scanf("%f", &amount);

                if (amount <= 0) {
                    printf("❌ Invalid amount!\n\n");
                } else {
                    balance += amount;
                    printf("✅ Rs. %.2f deposited successfully!\n", amount);
                    printf("💰 New Balance: Rs. %.2f\n\n", balance);
                }
                break;

            case 3:
                printf("Enter withdrawal amount: Rs. ");
                scanf("%f", &amount);

                if (amount <= 0) {
                    printf("❌ Invalid amount!\n\n");
                } else if (amount > balance) {
                    printf("❌ Insufficient Balance!\n");
                    printf("💰 Available: Rs. %.2f\n\n", balance);
                } else {
                    balance -= amount;
                    printf("✅ Rs. %.2f withdrawn successfully!\n", amount);
                    printf("💰 Remaining Balance: Rs. %.2f\n\n", balance);
                }
                break;

            case 4:
                printf("Thank you for using ATM!\n");
                printf("Please collect your card. 👋\n");
                return 0;

            default:
                printf("❌ Invalid choice! Enter 1-4.\n\n");
        }
    }

    return 0;
}