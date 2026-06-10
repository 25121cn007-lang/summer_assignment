#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter the no of rows");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=0;j<=n-i;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%c",'A'+(j-1));
        }
        for(j=i-1;j>0;j--){
            printf("%c",'A'+(j-1));
        }
        printf("\n");
    }
    return 0;
}