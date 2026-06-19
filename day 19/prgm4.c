#include <stdio.h>
int main() {
    int matrix[10][10];
    int size, i, j;
    int diagonalSum = 0;
    printf("Enter the size of the square matrix (max 10): ");
    scanf("%d", &size);
    if (size > 10 || size <= 0) {
        printf("Invalid matrix size.\n");
        return 1;
    }
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < size; i++) {
        diagonalSum += matrix[i][i];
    }
    printf("\nThe given matrix is:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nSum of the main diagonal elements is: %d\n", diagonalSum);
    return 0;
}
