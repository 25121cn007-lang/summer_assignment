#include<stdio.h>
int main(){
    int n,i,f=0;
    printf("Enter the number");
    scanf("%d",&n);
    if(n==1){
        printf("the number is neither prime nor composite");
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
        printf("the no is prime");
    }
    else{
        printf("the no is not prime");
    }
return 0;
}