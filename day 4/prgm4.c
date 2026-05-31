#include <stdio.h>
#include <math.h>
int isArmstrong(int num) {
    int originalNum = num;
    int digits = 0;
    int sum = 0;
    int temp = num;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    temp = num;
    while (temp != 0) {
        int remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }
    return (sum == originalNum);
}

int main() {
    int start, end;
    printf("Enter the starting number of the range: ");
    scanf("%d", &start);
    printf("Enter the ending number of the range: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
