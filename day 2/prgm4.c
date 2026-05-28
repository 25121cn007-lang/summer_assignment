#include<stdio.h>
int main(){
    int n,rem,re=0,og;
    printf("enter the no");
    scanf("%d",&n);
    og=n;
    while(n>0){
        rem=n%10;
        re=re*10+rem;
        n=n/10;
    }
    printf("the reverse of the no is %d \n",re);
    if(og==re){
        printf("the no is palindrome");
    }
    else{
        printf("the no is not palindrome");
    }
return 0;
}