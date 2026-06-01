#include<stdio.h>
int main(){
    int n,f,i,j,f1,s=0,n1;
    printf("enter the number");
    scanf("%d",&n);
    n1=n;
    while(n>0){
        i=n%10;
        f=1;
        for(j=1;j<=i;j++){
            f=f*j;
        }
        s=s+f;
        n=n/10;
    }
    if(s==n1){
        printf("the no is a strong no");
    }
    else{
        printf("not a strong no");
    }
return 0;
}