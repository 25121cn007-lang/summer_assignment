#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Need at least 2 elements!\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int largest = arr[0], second = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    if (second == largest)
        printf("No second largest element found\n");
    else
        printf("Largest: %d\nSecond Largest: %d\n", largest, second);

    return 0;
}