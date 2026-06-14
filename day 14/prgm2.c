#include <stdio.h>
int main() {
    int n, target, count = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to find frequency: ");
    scanf("%d", &target);
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            count++;
    }
    if (count > 0)
        printf("Element %d appears %d time(s)\n", target, count);
    else
        printf("Element %d not found in array\n", target);
    return 0;
}