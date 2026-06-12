#include<stdio.h>
int prfctno(int n){
    int i,s=0;
    for(i=1;i<n;i++){
        if(n%i==0){
            s=s+i;
        }
    }
    if(s==n){
        printf("PERFECT NUMBER");
    }
    else{
        printf("NOT A PERFECT NUMBER");
    }
}
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    prfctno(n);
    return 0;
}