#include<stdio.h>
int main(){
    int n,rem,rev=0;
    printf("enter the no");
    scanf("%d",&n);
    while(n>0){
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    printf("the reverse of the no is %d",rev);
return 0;
}