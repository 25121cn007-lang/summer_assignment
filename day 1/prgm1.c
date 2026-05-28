#include<stdio.h>
int main(){
    int i,n,s=0;
    printf("enter the no of numbers");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        s=s+i;
    }
    printf("the sum of n nos is %d",s);
return 0;
}