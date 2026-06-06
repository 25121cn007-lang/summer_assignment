#include <stdio.h>
int main(){
    int decimal, remainder,r;
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
    int ct=0;
    while(binary!=0){
        r=binary%10;
        if(r==1){
            ct=ct+1;
        }
        binary=binary/10;
    }
    printf("The set bits in this number is: %d",ct);
    return 0;
}