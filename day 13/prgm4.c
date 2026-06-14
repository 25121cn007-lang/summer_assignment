#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int even = 0, odd = 0;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }
    printf("Even elements = %d\n", even);
    printf("Odd elements = %d\n", odd);
    return 0;
}