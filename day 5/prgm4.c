#include<stdio.h>
int main(){
    int n, i, largest = -1;
    printf("Enter the number: ");
    scanf("%d", &n);
    
    for(i = 2; i <= n; i++){
        if(n % i == 0){          // i is a factor
            // check if i is prime
            int j, isPrime = 1;
            for(j = 2; j < i; j++){
                if(i % j == 0){
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime){
                largest = i;     // update largest prime factor
            }
        }
    }
    
    printf("Largest prime factor = %d", largest);
    return 0;
}