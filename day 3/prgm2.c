#include<stdio.h>
int main(){
    int l,h,f=0,i,j;
    printf("enter the lowest no of the range\n");
    scanf("%d",&l);
    printf("enter the last no of the ranges\n");
    scanf("%d",&h);
    for(i=l;i<=h;i++){
        f=0;
        if(i<=1){
            printf("%d is neither prime nor composite\n",i);
            f=1;
        }
        else{
            for(j=2;j<i;j++){
                if(i%j==0){
                    f=1;
                    break;
                }
            }
        }
        if(f==0){
            printf("%d is prime between this range\n",i);
        }
    }
return 0;
}