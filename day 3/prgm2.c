#include<stdio.h>
int main(){
    int l,h,i,f,j,ct;
    printf("Enter the starting no of the range");
    scanf("%d",&l);
    printf("enter the last no of the range");
    scanf("%d",&h);
    for(i=l;i<=h;i++){
        f=0;
        if(i==1){
            printf("the number is neither prime nor composite\n");
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
        printf("%d is a prime no\n",i);
        }
    }
return 0;
}