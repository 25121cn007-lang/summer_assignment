#include<stdio.h>
int main(){
    int n1,n2,temp,dividend,divisor,lcm,gcd;
    printf("enter the nos");
    scanf("%d %d",&n1,&n2);
    if(n1>n2){
        dividend=n1;
        divisor=n2;
    }
    else if(n2>n1){
        dividend=n2;
        divisor=n1;
    }
    while(divisor!=0){
        temp=divisor;
        divisor=dividend%divisor;
        dividend=temp;
    }
    printf("the gcd is %d\n",dividend);
    gcd=dividend;
    lcm=(n1*n2)/gcd;
    printf("the lcm is %d",lcm);
return 0;
}