#include<stdio.h>
int main(){
    int n,i,s=0;
    printf("enter a number");
    scanf("%d",&n);
    for(i=1;i<n;i++){
        if(n%i==0){
            s=s+i;
        }
    }
    printf("the sum of factors is %d\n",s);
    if(s==n){
        printf("%d is a perfect number",n);
    }
    else{
        printf("%d is not a perfect number",n);
    }
return 0;
}