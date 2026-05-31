#include<stdio.h>
int main(){
    int n,n1=0,n2=1,nxt=n1+n2,i;
    printf("enter the nth term");
    scanf("%d",&n);
    printf("fibonacci series: %d , %d ,",n1,n2);
    for(i=3;i<=n;++i){
        nxt=n1+n2;
        n1=n2;
        n2=nxt;
        printf("%d, ",nxt);
    }
return 0;
}