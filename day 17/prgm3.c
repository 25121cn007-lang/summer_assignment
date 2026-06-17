#include <stdio.h>
int isPresent(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val)
            return 1;
    }
    return 0;
}
int intersectionArrays(int a[], int n, int b[], int m, int c[]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (isPresent(b, m, a[i]))
            c[k++] = a[i];
    }
    return k; 
}
void printArray(int arr[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf(" }\n");
}
int main() {
    int n, m;
    printf("Enter size of Array A: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements of Array A:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("Enter size of Array B: ");
    scanf("%d", &m);
    int b[m];
    printf("Enter elements of Array B:\n");
    for (int i = 0; i < m; i++) {
        printf("b[%d]: ", i);
        scanf("%d", &b[i]);
    }
    int c[n < m ? n : m]; 
    int interSize = intersectionArrays(a, n, b, m, c);
    printf("\nArray A: ");
    printArray(a, n);
    printf("Array B: ");
    printArray(b, m);
    if (interSize == 0)
        printf("Intersection: { } (no common elements)\n");
    else {
        printf("Intersection: ");
        printArray(c, interSize);
    }
    return 0;
}