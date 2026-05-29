#include<stdio.h>
int main(){
    int n,s=0,rem;
    printf("enter the number");
    scanf("%d",&n);
    while(n>0){
        rem=n%10;
        s=s+rem;
        n=n/10;
    }
    printf("the sum of digits of the number is %d",s);
return 0;
}