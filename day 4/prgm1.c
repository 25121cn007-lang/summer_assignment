#include<stdio.h>
int main(){
    int n1=0,n2=1,n3=n1+n2,n,i;
    printf("enter the no of terms");
    scanf("%d",&n);
    printf("Fibonacci series: %d %d ",n1,n2);
    for(i=3;i<=n;i++){
        printf("%d ",n3);
        n1=n2;
        n2=n3;
        n3=n1+n2;
    }
    return 0;
}