#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int secret, guess, attempts = 0;
    int maxAttempts = 7;
    srand(time(0));
    secret = (rand() % 100) + 1;
    printf("=== Number Guessing Game ===\n");
    printf("guess no between 1 to 100!\n");
    printf("You have %d attempts.\n\n", maxAttempts);
    while (attempts < maxAttempts) {
        printf("Attempt %d/%d - Enter guess: ", attempts + 1, maxAttempts);
        scanf("%d", &guess);
        attempts++;
        if (guess < 1 || guess > 100) {
            printf("Invalid!.\n\n");
            attempts--; 
            continue;
        }
        if (guess < secret) {
            printf("Too Low! . (%d attempts left)\n\n",
                   maxAttempts - attempts);
        } else if (guess > secret) {
            printf("Too High!. (%d attempts left)\n\n",
                   maxAttempts - attempts);
        } else {
            printf("\ncorrect answer mate: %d\n", secret);
            printf("you have guessed in %d attempts \n", attempts);
            return 0;
        }
    }
    printf("\nGame Over! Number was: %d\n", secret);
    return 0;
}