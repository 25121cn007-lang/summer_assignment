#include <stdio.h>
int main() {
    int n, largest = -1;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }
    if (n > 1)
        largest = n;

    printf("Largest prime factor: %d\n", largest);

    return 0;
}