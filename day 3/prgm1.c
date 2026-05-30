#include<stdio.h>
int main(){
    int n,f=0,i;
    printf("enter the no");
    scanf("%d",&n);
    if(n<=1){
        printf("neither prime nor composite");
        f=1;
    }
    else{
        for(i=2;i<n;i++){
            if(n%i==0){
                f=1;
                break;
            }
        }
    }
    if(f==0){
        printf("no is prime");
    }
    else{
        printf("no is not prime");
    }
return 0;
}