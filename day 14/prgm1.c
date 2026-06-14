#include<stdio.h>
int main(){
    int a[20],n,sn,i;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    printf("Enter the elements");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&sn);
    int f=0;
    for(i=0;i<n;i++){
        if(a[i]==sn){
            f=1;
            break;
        }
    }
    if(f==0){
        printf("element not found");
    }
    else{
        printf("Element is found at index %d",i+1);
    }
    return 0;
}