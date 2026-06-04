#include<stdio.h>
int main(){
    int n,a=0,b=1,c=a+b,i;
    printf("Enter the term to find:");
    scanf("%d",&n);
    if(n==1){
        printf("%d Fibonacci term=0\n",n);
    }
    else if(n==2){
        printf("%d Fibonacci series=1\n",n);
    }
    else{
        for(i=3;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        printf("%dth Fibonacci term = %d\n",n,b);
    }
    return 0;
}