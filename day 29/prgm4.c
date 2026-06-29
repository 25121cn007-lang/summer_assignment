#include <stdio.h>
#include <string.h>
#define MAX 100
struct Product {
    int id;
    char name[50];
    int qty;
    float price;
};
struct Product inv[MAX];
int n = 0;
void addProduct() {
    printf("Enter ID: ");      scanf("%d", &inv[n].id);
    printf("Enter Name: ");    scanf("%s", inv[n].name);
    printf("Enter Qty: ");     scanf("%d", &inv[n].qty);
    printf("Enter Price: ");   scanf("%f", &inv[n].price);
    n++;
    printf("Product Added!\n");
}
void displayAll() {
    if (n == 0) { printf("No products!\n"); return; }
    printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Qty", "Price");
    printf("----------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-5d %-20s %-10d %-10.2f\n", inv[i].id, inv[i].name, inv[i].qty, inv[i].price);
}
void searchProduct() {
    int id, found = 0;
    printf("Enter ID to search: "); scanf("%d", &id);
    for (int i = 0; i < n; i++)
        if (inv[i].id == id) {
            printf("ID: %d | Name: %s | Qty: %d | Price: %.2f\n",
                   inv[i].id, inv[i].name, inv[i].qty, inv[i].price);
            found = 1; break;
        }
    if (!found) printf("Product not found!\n");
}
void updateProduct() {
    int id, found = 0;
    printf("Enter ID to update: "); scanf("%d", &id);
    for (int i = 0; i < n; i++)
        if (inv[i].id == id) {
            printf("New Name: ");  scanf("%s", inv[i].name);
            printf("New Qty: ");   scanf("%d", &inv[i].qty);
            printf("New Price: "); scanf("%f", &inv[i].price);
            printf("Updated!\n");
            found = 1; break;
        }
    if (!found) printf("Product not found!\n");
}
void deleteProduct() {
    int id, found = 0;
    printf("Enter ID to delete: "); scanf("%d", &id);
    for (int i = 0; i < n; i++)
        if (inv[i].id == id) {
            for (int j = i; j < n - 1; j++)
                inv[j] = inv[j + 1];
            n--;
            printf("Product Deleted!\n");
            found = 1; break;
        }
    if (!found) printf("Product not found!\n");
}
void lowStock() {
    int limit, found = 0;
    printf("Enter stock limit: "); scanf("%d", &limit);
    printf("\nLow Stock Products:\n");
    for (int i = 0; i < n; i++)
        if (inv[i].qty <= limit) {
            printf("ID: %d | %s | Qty: %d\n", inv[i].id, inv[i].name, inv[i].qty);
            found = 1;
        }
    if (!found) printf("No low stock products!\n");
}
void totalValue() {
    float total = 0;
    for (int i = 0; i < n; i++)
        total += inv[i].qty * inv[i].price;
    printf("Total Inventory Value: %.2f\n", total);
}
int main() {
    int ch;
    while (1) {
        printf("\n=== INVENTORY MANAGEMENT ===\n");
        printf("1.Add  2.Display  3.Search  4.Update  5.Delete  6.LowStock  7.TotalValue  0.Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addProduct();    break;
            case 2: displayAll();    break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
            case 6: lowStock();      break;
            case 7: totalValue();    break;
            case 0: printf("Bye!\n"); return 0;
            default: printf("Invalid!\n");
        }
    }
}