#include <stdio.h>
int main(){
    int decimal, remainder;
    int binary = 0;
    int multiplier = 1;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    int temp = decimal;
    while (temp != 0) {
        remainder = temp % 2;
        binary += remainder * multiplier;
        temp /= 2;
        multiplier *= 10;
    }
    printf("Binary of %d = %d\n", decimal, binary);
    return 0;
}