#include <stdio.h>
#include <string.h>
#define MAX 50

struct Employee { int id; char name[50]; char dept[30]; float salary; } emp[MAX];
int count = 0;

void addEmployee() {
    printf("ID: "); scanf("%d", &emp[count].id);
    printf("Name: "); scanf(" %[^\n]", emp[count].name);
    printf("Department: "); scanf(" %[^\n]", emp[count].dept);
    printf("Salary: "); scanf("%f", &emp[count].salary);
    count++;
    printf("Employee added!\n");
}

void displayAll() {
    printf("\n%-5s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    for (int i = 0; i < count; i++)
        printf("%-5d %-20s %-15s %-10.2f\n", emp[i].id, emp[i].name, emp[i].dept, emp[i].salary);
}

void searchEmployee() {
    int id;
    printf("Enter ID to search: "); scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            printf("Found -> Name:%s Dept:%s Salary:%.2f\n", emp[i].name, emp[i].dept, emp[i].salary);
            return;
        }
    }
    printf("Employee not found!\n");
}

void updateSalary() {
    int id;
    printf("Enter ID to update salary: "); scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            printf("New Salary: "); scanf("%f", &emp[i].salary);
            printf("Salary updated!\n");
            return;
        }
    }
    printf("Employee not found!\n");
}

void deleteEmployee() {
    int id;
    printf("Enter ID to delete: "); scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            for (int j = i; j < count - 1; j++) emp[j] = emp[j + 1];
            count--;
            printf("Employee deleted!\n");
            return;
        }
    }
    printf("Employee not found!\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Add 2.Display 3.Search 4.Update Salary 5.Delete 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: searchEmployee(); break;
            case 4: updateSalary(); break;
            case 5: deleteEmployee(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}