#include <stdio.h>
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
    printf("\nArray A: { ");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");
    printf("Array B: { ");
    for (int i = 0; i < m; i++) {
        printf("%d", b[i]);
        if (i < m - 1) printf(", ");
    }
    printf(" }\n");
    int count = 0;
    printf("Common Elements: { ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                if (count > 0) printf(", ");
                printf("%d", a[i]);
                count++;
                break; 
            }
        }
    }
    printf(" }\n");
    if (count == 0)
        printf("No common elements found.\n");
    else
        printf("Total common elements: %d\n", count);
    return 0;
}