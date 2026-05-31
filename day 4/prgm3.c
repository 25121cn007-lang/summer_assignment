#include<stdio.h>
#include<math.h>
int main(){
    int n,temp,rem,ct=0,no=0;
    printf("enter the number");
    scanf("%d",&n);
    temp=n;
    while(temp!=0){
        temp=temp/10;
        ct++;
    }
    temp=n;
    while(temp!=0){
        rem=temp%10;
        no=no+pow(rem,ct);
        temp=temp/10;
    }
    if(no==n){
        printf("armstrong no");
    }
    else{
        printf("get lost");
    }
    return 0;
}