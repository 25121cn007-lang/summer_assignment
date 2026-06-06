#include<stdio.h>
#include<math.h>
int main(){
    int bin,dec=0,rem,r=0;
    printf("Enter the binary number:");
    scanf("%d",&bin);
    while(bin!=0){
        rem=bin%10;
        dec=dec+rem*pow(2,r);
        bin=bin/10;
        r++;
    }
    printf("The decimal number is : %d",dec);
    return 0;
}