#include <stdio.h>
void mergeArrays(int a[], int n, int b[], int m, int c[]) {
    int i;
    for (i = 0; i < n; i++)
        c[i] = a[i];
    for (i = 0; i < m; i++)
        c[n + i] = b[i];
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
    mergeArrays(a, n, b, m, c);
    printf("\nArray A: ");
    printArray(a, n);
    printf("Array B: ");
    printArray(b, m);
    printf("Merged : ");
    printArray(c, n + m);
    return 0;
}