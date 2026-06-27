#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define FILE_NAME "employees.dat"

typedef struct {
    int id;
    char name[50];
    char dept[30];
    char designation[30];
    float salary;
    int experience; // years
    char phone[15];
    char email[50];
} Employee;

Employee emp[MAX];
int n = 0, nextId = 1;

/* ───── File I/O ───── */

void saveToFile() {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) { printf("Error saving!\n"); return; }
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(&nextId, sizeof(int), 1, fp);
    fwrite(emp, sizeof(Employee), n, fp);
    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return;
    fread(&n, sizeof(int), 1, fp);
    fread(&nextId, sizeof(int), 1, fp);
    fread(emp, sizeof(Employee), n, fp);
    fclose(fp);
}

/* ───── Helpers ───── */

void clearBuffer() { while (getchar() != '\n'); }

void printLine() {
    printf("============================================================\n");
}

void printHeader(const char *title) {
    system("clear || cls");
    printLine();
    printf("        EMPLOYEE MANAGEMENT SYSTEM\n");
    printLine();
    printf("  %s\n", title);
    printLine();
}

int findById(int id) {
    for (int i = 0; i < n; i++)
        if (emp[i].id == id) return i;
    return -1;
}

void printTableHeader() {
    printf("%-5s %-18s %-15s %-15s %-10s %-5s\n",
           "ID", "Name", "Department", "Designation", "Salary", "Exp");
    printLine();
}

void printEmpRow(Employee *e) {
    printf("%-5d %-18s %-15s %-15s %-10.2f %-5d\n",
           e->id, e->name, e->dept, e->designation, e->salary, e->experience);
}

/* ───── Core Operations ───── */

void addEmployee() {
    printHeader("ADD NEW EMPLOYEE");

    if (n >= MAX) { printf("Storage full!\n"); return; }

    Employee e;
    e.id = nextId++;

    printf("Name        : "); scanf(" %[^\n]", e.name);
    printf("Department  : "); scanf(" %[^\n]", e.dept);
    printf("Designation : "); scanf(" %[^\n]", e.designation);
    printf("Salary      : "); scanf("%f", &e.salary); clearBuffer();
    printf("Experience  : "); scanf("%d", &e.experience); clearBuffer();
    printf("Phone       : "); scanf(" %[^\n]", e.phone);
    printf("Email       : "); scanf(" %[^\n]", e.email);

    emp[n++] = e;
    saveToFile();
    printf("\n  Employee '%s' added! (ID: %d)\n", e.name, e.id);
}

void listAll() {
    printHeader("ALL EMPLOYEES");

    if (n == 0) { printf("  No records found.\n"); return; }

    printf("  Total: %d employee(s)\n\n", n);
    printTableHeader();
    for (int i = 0; i < n; i++)
        printEmpRow(&emp[i]);
}

void searchEmployee() {
    printHeader("SEARCH EMPLOYEE");
    printf("  1. By ID\n  2. By Name\n  3. By Department\n");
    printf("Choice: ");
    int ch; scanf("%d", &ch); clearBuffer();

    int found = 0;

    if (ch == 1) {
        printf("Enter ID: ");
        int id; scanf("%d", &id); clearBuffer();
        int idx = findById(id);
        if (idx != -1) {
            Employee *e = &emp[idx];
            printLine();
            printf("  ID          : %d\n", e->id);
            printf("  Name        : %s\n", e->name);
            printf("  Department  : %s\n", e->dept);
            printf("  Designation : %s\n", e->designation);
            printf("  Salary      : %.2f\n", e->salary);
            printf("  Experience  : %d years\n", e->experience);
            printf("  Phone       : %s\n", e->phone);
            printf("  Email       : %s\n", e->email);
            found = 1;
        }
    } else if (ch == 2) {
        printf("Enter Name: ");
        char query[50]; scanf(" %[^\n]", query);
        printTableHeader();
        for (int i = 0; i < n; i++) {
            if (strstr(emp[i].name, query)) {
                printEmpRow(&emp[i]);
                found = 1;
            }
        }
    } else if (ch == 3) {
        printf("Enter Department: ");
        char dept[30]; scanf(" %[^\n]", dept);
        printTableHeader();
        for (int i = 0; i < n; i++) {
            if (strcmp(emp[i].dept, dept) == 0) {
                printEmpRow(&emp[i]);
                found = 1;
            }
        }
    }

    if (!found) printf("\n  No matching employee found.\n");
}

void updateEmployee() {
    printHeader("EDIT EMPLOYEE");
    printf("Enter Employee ID: ");
    int id; scanf("%d", &id); clearBuffer();

    int idx = findById(id);
    if (idx == -1) { printf("  Not found.\n"); return; }

    Employee *e = &emp[idx];
    printf("Editing: %s (Press Enter to keep current value)\n\n");

    char buf[100];

    printf("Name [%s]: ", e->name);
    fgets(buf, 50, stdin); buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf)) strcpy(e->name, buf);

    printf("Department [%s]: ", e->dept);
    fgets(buf, 30, stdin); buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf)) strcpy(e->dept, buf);

    printf("Designation [%s]: ", e->designation);
    fgets(buf, 30, stdin); buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf)) strcpy(e->designation, buf);

    printf("Salary [%.2f]: ", e->salary);
    fgets(buf, 20, stdin); buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf)) e->salary = atof(buf);

    printf("Experience [%d]: ", e->experience);
    fgets(buf, 10, stdin); buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf)) e->experience = atoi(buf);

    printf("Phone [%s]: ", e->phone);
    fgets(buf, 15, stdin); buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf)) strcpy(e->phone, buf);

    printf("Email [%s]: ", e->email);
    fgets(buf, 50, stdin); buf[strcspn(buf, "\n")] = 0;
    if (strlen(buf)) strcpy(e->email, buf);

    saveToFile();
    printf("\n  Employee updated successfully!\n");
}

void deleteEmployee() {
    printHeader("DELETE EMPLOYEE");
    printf("Enter Employee ID: ");
    int id; scanf("%d", &id); clearBuffer();

    int idx = findById(id);
    if (idx == -1) { printf("  Not found.\n"); return; }

    printf("Delete '%s'? (y/n): ", emp[idx].name);
    char c = getchar(); clearBuffer();

    if (c == 'y' || c == 'Y') {
        for (int i = idx; i < n - 1; i++)
            emp[i] = emp[i + 1];
        n--;
        saveToFile();
        printf("  Deleted successfully!\n");
    } else {
        printf("  Cancelled.\n");
    }
}

void giveRaise() {
    printHeader("GIVE SALARY RAISE");
    printf("  1. Raise by ID\n  2. Raise entire department\n");
    printf("Choice: ");
    int ch; scanf("%d", &ch); clearBuffer();

    if (ch == 1) {
        printf("Enter ID: ");
        int id; scanf("%d", &id); clearBuffer();
        int idx = findById(id);
        if (idx == -1) { printf("Not found.\n"); return; }
        printf("Raise %% : ");
        float pct; scanf("%f", &pct); clearBuffer();
        emp[idx].salary += emp[idx].salary * pct / 100;
        saveToFile();
        printf("  New Salary: %.2f\n", emp[idx].salary);

    } else if (ch == 2) {
        printf("Department: ");
        char dept[30]; scanf(" %[^\n]", dept);
        printf("Raise %%   : ");
        float pct; scanf("%f", &pct); clearBuffer();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(emp[i].dept, dept) == 0) {
                emp[i].salary += emp[i].salary * pct / 100;
                count++;
            }
        }
        saveToFile();
        printf("  Raise applied to %d employee(s).\n", count);
    }
}

void showStats() {
    printHeader("STATISTICS");

    if (n == 0) { printf("  No data.\n"); return; }

    float total = 0, maxSal = 0, minSal = emp[0].salary;
    int totalExp = 0;
    char depts[MAX][30];
    int deptCount = 0;

    for (int i = 0; i < n; i++) {
        total += emp[i].salary;
        totalExp += emp[i].experience;
        if (emp[i].salary > maxSal) maxSal = emp[i].salary;
        if (emp[i].salary < minSal) minSal = emp[i].salary;

        int found = 0;
        for (int j = 0; j < deptCount; j++)
            if (strcmp(depts[j], emp[i].dept) == 0) { found = 1; break; }
        if (!found) strcpy(depts[deptCount++], emp[i].dept);
    }

    printf("  Total Employees   : %d\n", n);
    printf("  Total Salary Bill : %.2f\n", total);
    printf("  Average Salary    : %.2f\n", total / n);
    printf("  Highest Salary    : %.2f\n", maxSal);
    printf("  Lowest Salary     : %.2f\n", minSal);
    printf("  Avg Experience    : %.1f years\n", (float)totalExp / n);
    printf("  Departments       : %d\n", deptCount);
    printLine();
    for (int i = 0; i < deptCount; i++)
        printf("    - %s\n", depts[i]);
}

/* ───── Main ───── */

int main() {
    loadFromFile();
    int ch;
    do {
        printHeader("MAIN MENU");
        printf("  1. Add Employee\n");
        printf("  2. List All\n");
        printf("  3. Search\n");
        printf("  4. Edit Employee\n");
        printf("  5. Delete Employee\n");
        printf("  6. Give Salary Raise\n");
        printf("  7. Statistics\n");
        printf("  0. Exit\n");
        printLine();
        printf("  Choice: ");
        scanf("%d", &ch); clearBuffer();

        switch (ch) {
            case 1: addEmployee();    break;
            case 2: listAll();        break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: giveRaise();      break;
            case 7: showStats();      break;
            case 0: printf("\n  Goodbye!\n"); break;
            default: printf("  Invalid choice!\n");
        }

        if (ch != 0) { printf("\n  Press Enter to continue..."); getchar(); }

    } while (ch != 0);
    return 0;
}