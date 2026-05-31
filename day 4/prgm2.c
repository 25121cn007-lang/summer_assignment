#include <stdio.h>
long long findNthFibonacci(int n) {
    if (n < 0) {
        return -1; 
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    long long prev2 = 0;
    long long prev1 = 1;
    long long current = 0;

    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {
    int n;

    printf("Enter the value of n: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    long long result = findNthFibonacci(n);

    if (result == -1) {
        printf("Fibonacci is not defined for negative numbers.\n");
    } else {
        printf("The %dth Fibonacci term is: %lld\n", n, result);
    }

    return 0;
}