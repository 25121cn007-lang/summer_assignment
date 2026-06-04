#include <stdio.h>
#include <math.h>
int isArmstrong(int num) {
    int originalNum, remainder, result = 0;
    int n;
    originalNum = num;  
    n = log10(num) + 1;  
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    return (result == num);
}

int main() {
    int low,high;
    printf("Enter the range:"); 
    scanf("%d %d",&low,&high);
    printf("Armstrong numbers between %d and %d are: ", low, high);

   
    for (int i = low; i <=high; ++i) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}