#include <stdio.h>
void merge(int a[], int n, int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
}
int main() {
    int n, m;
    printf("Enter size of array 1: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter size of array 2: ");
    scanf("%d", &m);
    int b[m];
    printf("Enter sorted elements: ");
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    int c[n + m];
    merge(a, n, b, m, c);
    printf("Merged array: ");
    for (int i = 0; i < n + m; i++) printf("%d ", c[i]);
    printf("\n");
    return 0;
}