#include<stdio.h>
int pailno(int ogno){
    int r,s=0,n;
    n=ogno;
    while(n>0){
        r=n%10;
        s=s*10+r;
        n=n/10;
    }
    if(s==ogno){
        printf("No is Palindrome");
    }
    else{
        printf("no is not palindrome");
    }
}
int main(){
    int ogno;
    printf("Enter the no:");
    scanf("%d",&ogno);
    pailno(ogno);
    return 0;
}