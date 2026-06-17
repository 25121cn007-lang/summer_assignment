#include <stdio.h>
int isPresent(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val)
            return 1;
    }
    return 0;
}
int unionArrays(int a[], int n, int b[], int m, int c[]) {
    int k = 0;
    for (int i = 0; i < n; i++)
        c[k++] = a[i];
    for (int i = 0; i < m; i++) {
        if (!isPresent(a, n, b[i]))
            c[k++] = b[i];
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
    int c[n + m]; 
    int unionSize = unionArrays(a, n, b, m, c);
    printf("\nArray A: ");
    printArray(a, n);
    printf("Array B: ");
    printArray(b, m);
    printf("Union  : ");
    printArray(c, unionSize);
    return 0;
}