#include<stdio.h>
int main(){
    int n,i,a[20],j;
    printf("Enter the no of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int maxfreq=0;
    int maxele=0;
    for(i=0;i<n;i++){
        int ct=0;
        for(j=0;j<n;j++){
            if(a[j]==a[i]){
                ct++;
            }
        }
        if(ct>maxfreq){
            maxfreq=ct;
            maxele=a[i];
        }
    }
    printf("the element with max frequency %d is %d",maxfreq,maxele);
    return 0;
}