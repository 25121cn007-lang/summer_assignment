#include <stdio.h>
#include<math.h>
int main() {
    int num, originalNum, remainder, result = 0,ct=0;
    printf("Enter a integer: ");
    scanf("%d", &num);
    originalNum = num;
    while(originalNum>0){
        originalNum/=10;
        ct++;
    }
    originalNum=num;

    while (originalNum != 0) {
        remainder = originalNum % 10;
        result=result+pow(remainder,ct);
        originalNum /= 10;
    }

    if (result == num)
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);

    return 0;
}