#include<stdio.h>
int main(){
   int n,ct=0,r;
   printf("enter the no");
   scanf("%d",&n);
   while(n>0){
      r=n%10;
      ct=ct+1;
      n=n/10;
   }
   printf("the no of digits are %d",ct);
return 0;
}