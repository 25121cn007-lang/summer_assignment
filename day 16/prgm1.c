#include <stdio.h>
int main() {
    int n;
    printf("Enter total count: ");
    scanf("%d", &n);
    int arr[n - 1];
    printf("Enter the elements :\n");
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }
    int expected = n * (n + 1) / 2;
    int actual = 0;
    for (int i = 0; i < n - 1; i++) {
        actual += arr[i];
    }
    printf("Missing number = %d\n", expected - actual);
    return 0;
}