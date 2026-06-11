#include<stdio.h>
int twonsum(int n1,int n2){
    int z;
    z=n1+n2;
    printf("The sum of 2 nos is: %d",z);
}
int main(){
    int n1,n2;
    printf("Enter the 2 nos:");
    scanf("%d %d",&n1,&n2);
    twonsum(n1,n2);
    return 0;
}